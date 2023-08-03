classdef TrajectoryGenerator < handle
    %TRAJECTORYGENERATOR Summary of this class goes here
    %   Detailed explanation goes here

    % The Fossen(2021) Reference is the book "Handbook of Marine Craft Hydrodynamics and Motion Control second edition"
    % Disponible a la bibliotheque de l'ets. Code : VM 156 F67 2021

    properties (Constant)
        % Code d'erreur
        WARN_AUV_MAY_SURFACE = 1
        RECIEVED_VALID_WAYPTS = 0;
        ERR_INVALID_INTERP_METHOD = -1;
        ERR_INVALID_FRAME_REF = -2;
        ERR_INVALID_SPEED_PARAM = -3;
        ERR_RADIUS_TO_LARGE =-4;
        ERR_INVALID_IC = -5;
        ERR_TRAJ_EXCEED_MAX_DEPTH = -6;
        ERR_OBSTACLE_IS_NOT_DETECT = -7;

        obstacleOffset =10;

    end

    properties
        status; % Validité de waypoints reçus.

    end

    properties (Access = private)

        % class
        qUtils; % quaternion utilities

        % Structures
        MAPM; % Multi Add Pose Msg.
        param; % paramètre de trajectoire.
        obstacleData; % Information des obstacle

        % Parametres
        nMAPM;     % nombre de waypoints dans la liste multiaddpose.
        n;         % Nombre de waypoints réel.
        lastConj = false; % condition de discontinute du quaternion.
        icOffset = 2; % nombre de point pour la condition initial.

        % Liste waypoints
        pointList; % liste de position.
        quatList;  % liste de quaternion.
        timeList;  % liste de temp
        courseList; % Liste de courbe
        speedList; % parametre de vitesse


        % liste de trajectoire
        nbPoint = 1;      % Nombre de points dans la trajectoire
        trajPosition;
        trajQuat;
        trajBodyVelocity;
        trajAngulairRates;
        trajLinearAcceleration;
        trajAngularAcceleration;

    end

    methods
        %==================================================================
        % Constructeur
        function this = TrajectoryGenerator(multiAddposeMsg, param, icMsg, obstMsg)
            % Initialise l'objet trajectoire et vérifie si le message multi add pose est valide.

            this.status = this.RECIEVED_VALID_WAYPTS; % Validité de waypoints reçus.

            this.obstacleData = obstMsg; % prendre les infos des obstacles.

            this.MAPM =multiAddposeMsg;
            this.nMAPM = max(size(multiAddposeMsg.Pose)); % matlab and cpp dont use same index. return max instead

            % Initialiser les parametres
            this.param = param;

            % Importer la librairie quatUtilities
             this.qUtils = quatUtilities();

            % Verifier que le dernier point ne contient pas de rayon.
            if this.MAPM.Pose(this.nMAPM).Fine ~= 0

                this.MAPM.Pose(this.nMAPM).Fine = 0;
                fprintf('Warning : proc planner : last waypoint must have fine parameter set to 0 \n');

            end

            % point supplementaire pour l'arrondissement.
            suppPoint = 0;
            for i=1 : this.nMAPM

                if ~(this.MAPM.Pose(i).Fine == 0)
                    suppPoint =suppPoint + 1;
                end
            end

            % nombre de waypoints  + point supp + offset + point initial
            this.n = this.nMAPM + suppPoint + this.icOffset + 1;

             % Initialiser les tableaux
            this.pointList = zeros(this.n,3);
            this.quatList = zeros(this.n,4);
            this.timeList = zeros(this.n,1);
            this.courseList = zeros(1, this.n);
            this.speedList = zeros(1, this.n);

            % trouver le waypoint initial
            if ~this.getInitialWaypoint(icMsg)
                this.status = this.ERR_INVALID_IC;
                fprintf('INFO : proc planner : initial waypoint not received \n');

            end

            % Verifier si le mode d'interpolation est valide
            if ~logical(this.interpStrategy(0, 0, 0, true))
                this.status = this.ERR_INVALID_INTERP_METHOD;
                fprintf('INFO : proc planner : Interpolation strategy is not recognized  \n');
            end

            % Process le message addpose
                this.processWpt();

            % Calculer les temps entre chaque waypoints
            if (this.status == this.RECIEVED_VALID_WAYPTS && logical(this.computetimeArrival()))
                % Déterminer le nombre de points
                this.nbPoint = round(this.timeList(end) / this.param.ts);

            else
                this.nbPoint = 1;

            end

            % vérifier la profondeur maximum.
            if (max(this.pointList(:,3)) > this.param.maxDepth )
                this.status = this.ERR_TRAJ_EXCEED_MAX_DEPTH;
            end

              % NEED MISSION CLEAN UP
%             % Vérifier si le sub peut faire surface;
%             if (min(this.pointList(:,3)) > this.param.surface_warning )
%                 this.status = this.WARN_AUV_MAY_SURFACE;
%             end

            % Definir la taille de la trajectoire
            this.trajPosition = zeros(this.nbPoint,3);
            this.trajQuat = zeros(this.nbPoint,4);
            this.trajBodyVelocity = zeros(this.nbPoint,3);
            this.trajAngulairRates = zeros(this.nbPoint,3);
            this.trajLinearAcceleration = zeros(this.nbPoint,3);
            this.trajAngularAcceleration = zeros(this.nbPoint,3);

        end
        %==================================================================
        % Fonction Main qui génère les waypoints
        function status = Compute(this,trajpub)

            %Vérifier la pré-validation
            if (this.status == this.RECIEVED_VALID_WAYPTS)
                % Interpoler les waypoints
                this.interpolateWaypoints();

                % Envoyer la trajectoire sur ROS.
                status = this.sendTrajectory(trajpub);

            else
                status =false;

            end

        end
    end
%% ========================================================================
    % Private function

    methods (Access = private)

        %==================================================================
        % Fonction qui interprete les waypoints reçu par ROS
        function processWpt(this)

            for i = 1 : this.nMAPM % pour chaques AddPose

                % transformer les angle d'euler quaternions
                q = eul2quat(deg2rad([this.MAPM.Pose(i).Orientation.Z,...
                                      this.MAPM.Pose(i).Orientation.Y,...
                                      this.MAPM.Pose(i).Orientation.X]),'ZYX');

                % cree le vecteur pose
                p = [this.MAPM.Pose(i).Position.X,...
                     this.MAPM.Pose(i).Position.Y,...
                     this.MAPM.Pose(i).Position.Z];

                % transformer le point en fonction du frame
                switch this.MAPM.Pose(i).Frame

                    case 0 % position et angle absolue
                        this.quatList(i+this.icOffset,:) = this.qUtils.checkQuatFlip(q, this.quatList(i+this.icOffset-1,:));
                        this.pointList(i+this.icOffset,:) = p;

                    case 1 % position et angle relatif
                        this.quatList(i+this.icOffset,:) = this.qUtils.getQuatDir(this.quatList(i+this.icOffset-1,:), q, this.MAPM.Pose(i).Rotation);
                        this.pointList(i+this.icOffset,:) = this.pointList(i+this.icOffset-1,:) + this.qUtils.quatRotation(p,this.quatList(i+this.icOffset-1,:));


                    case 2 % position relatif et angle absolue
                        this.quatList(i+this.icOffset,:) = this.qUtils.checkQuatFlip(q, this.quatList(i+this.icOffset-1,:));
                        this.pointList(i+this.icOffset,:) = this.pointList(i+this.icOffset-1,:) + this.qUtils.quatRotation(p,this.quatList(i+this.icOffset-1,:));

                    case 3 % position absolue et angle relatif
                        this.quatList(i+this.icOffset,:) = this.qUtils.getQuatDir(this.quatList(i+this.icOffset-1,:), q, this.MAPM.Pose(i).Rotation);
                        this.pointList(i+this.icOffset,:) = p;

                    case 4 % z absolue et reste relatif
                        this.quatList(i+this.icOffset,:) = this.qUtils.getQuatDir(this.quatList(i+this.icOffset-1,:), q, this.MAPM.Pose(i).Rotation);
                        this.pointList(i+this.icOffset,:) = this.pointList(i+this.icOffset-1,:) + this.qUtils.quatRotation(p,this.quatList(i+this.icOffset-1,:));
                        this.pointList(i+this.icOffset,3) = p(3);

                    otherwise % Référentiel obstacles

                        [pObst,qObst] = getObstacleFrame(this,this.MAPM.Pose(i).Frame);

                        if this.status >= 0
                            q =quatmultiply(qObst, q);
                            this.quatList(i+this.icOffset,:) = this.qUtils.checkQuatFlip( q, this.quatList(i+this.icOffset-1,:));
                            this.pointList(i+this.icOffset,:) = pObst + this.qUtils.quatRotation(p, qObst);
                        else
                            return ;
                        end


                end

                % copier le parametre de vitesse
                this.speedList(i + this.icOffset) = this.MAPM.Pose(i).Speed;

                % determiner le yaw pour le vecteur course
                this.courseList(i+this.icOffset) = this.getCourseAngle(this.quatList(i+this.icOffset,:));

                % verifier si faut arrondire la trajectoire.
                if i>1 && this.MAPM.Pose(i-1).Fine ~=0

                    [valid, p01, p12] = this.inscribedCircles(i+this.icOffset);

                    if ~valid
                        this.status = this.ERR_RADIUS_TO_LARGE;
                        fprintf('INFO : proc planner : Circle radius is to large.\n');
                        return

                    end

                    % Decaler les waypoints
                    this.pointList(i+this.icOffset+1,:) = this.pointList(i+this.icOffset,:);
                    this.pointList(i+this.icOffset,:) = p12;
                    this.pointList(i+this.icOffset-1,:) = p01;

                    this.quatList(i+this.icOffset+1,:) = this.quatList(i+this.icOffset,:);
                    this.quatList(i+this.icOffset,:) = this.quatList(i+this.icOffset-1,:);
                    this.quatList(i+this.icOffset-1,:) = this.quatList(i+this.icOffset-2,:);

                    this.speedList(i + this.icOffset + 1) =this.speedList(i + this.icOffset);
                    this.speedList(i + this.icOffset) = this.speedList(i + this.icOffset - 1 );

                    this.courseList(i+this.icOffset +1) = this.courseList(i+this.icOffset);
                    this.courseList(i+this.icOffset) = this.courseList(i+this.icOffset-1);
                    this.courseList(i+this.icOffset-1) = this.courseList(i+this.icOffset-2);

                    % nouveau waypoint. augmente le offset
                    this.icOffset =this.icOffset + 1;
                end
            end


            % Copier le dernier waypoint 2 fois pour éviter un comportement
            % du generateur de trajecteur
            this.pointList(end,:) = this.pointList(end-1,:);
            this.quatList(end,:) = this.quatList(end-1,:);
            this.courseList(end) = this.courseList(end-1);
            this.speedList(end) = this.speedList(end-1);

        end


        %==================================================================
        % Fonction qui vérifie frame obstacles

        function [p,q] = getObstacleFrame(this,id)

            % determiner le nombre d'obstacle
            obstCount = max(size(this.obstacleData.Obstacles))
            p = zeros(1,3);
            q = zeros(1,4);

            % check if obstacle exist
            if id  <= obstCount + this.obstacleOffset && id > this.obstacleOffset

                % check if obstacle is found
                if this.obstacleData.Obstacles(id - this.obstacleOffset).IsValid

                    p = [this.obstacleData.Obstacles(id - this.obstacleOffset).Pose.Position.X,...
                         this.obstacleData.Obstacles(id - this.obstacleOffset).Pose.Position.Y,...
                         this.obstacleData.Obstacles(id - this.obstacleOffset).Pose.Position.Z];

                    q = [this.obstacleData.Obstacles(id - this.obstacleOffset).Pose.Orientation.W,...
                         this.obstacleData.Obstacles(id - this.obstacleOffset).Pose.Orientation.X...
                         this.obstacleData.Obstacles(id - this.obstacleOffset).Pose.Orientation.Y...
                         this.obstacleData.Obstacles(id - this.obstacleOffset).Pose.Orientation.Z];
                else
                    this.status = this.ERR_OBSTACLE_IS_NOT_DETECT;
                    fprintf('INFO : proc planner : Desired obstacle is not detected.\n');
                end


            else
                this.status = this.ERR_INVALID_FRAME_REF;
                fprintf('INFO : proc planner : Invalid Reference Frame.\n');
            end

        end


        %==================================================================
        % Fonction qui retourne l'angle de course
         function angle = getCourseAngle(this, q)

            eul = rad2deg(quat2eul(q,"ZYX"));

            if eul(1)<0

                eul(1) = 360+eul(1);
            end

            angle = eul(1);
         end


        %==================================================================
        % Fonction qui arrondie les waypoints.

        function [status, p01, p12] = inscribedCircles(this,i)

            R_Bar = this.MAPM.Pose(i- this.icOffset-1).Fine;

            % Si rayon positif calculer la courbe
            if R_Bar > 0
                % Definition point.
                    P0 = this.pointList(i-2,:);
                    P1 = this.pointList(i-1,:);
                    P2 = this.pointList(i,:);

                % Determiner les vecteurs
                    v02 = P2-P0;
                    v01 = P1-P0;
                    v12 = P2-P1;

                % Determiner les longeures du triangle
                    a = norm(v02);
                    b = norm(v01);
                    c = norm(v12);

                % Calculer alpha 1 (loi de cos)
                    alpha_1 = (1/2) * acos((-(a^2)+b^2+c^2)/(2*b*c)); % radians

                % Calculer R
                    R_1 = R_Bar/tan(alpha_1);

                % Verifier que le rayon n'est pas trop grand
                if R_1 < b || R_1 < c

                % Calculer les points tangeant au cercle de rayon.
                    p01 = P0 + (v01./b)* (b-R_1);

                    p12 = P1 + (v12./c)* R_1;
                    status = true;

                else
                    p01 = zeros(1,3);
                    p12 = p01;
                    status = false;
                end

            % Si rayon negatif. copier le point 2 fois
            else
                p01 = this.pointList(i-1, :);
                p12 = this.pointList(i-1, :);
                status = true;
            end
        end

        %==================================================================
        % Fonnction qui calcul le temps entre chaque waypoint

        function  valid = computetimeArrival(this)

            valid = false;

            for i = 2 : this.n % pour chaques waypoints

                % Determiner le parametre de vitesse
                switch this.speedList(i)

                    case 0 % Vitesse normale
                        amax = this.param.normalSpeed.amax;
                        vlmax = this.param.normalSpeed.vlmax;
                        vamax = this.param.normalSpeed.vamax;

                    case 1 % Vitesse rapide
                        amax = this.param.highSpeed.amax;
                        vlmax = this.param.highSpeed.vlmax;
                        vamax = this.param.highSpeed.vamax;

                    case 2 % Vitesse lente
                        amax = this.param.lowSpeed.amax;
                        vlmax = this.param.lowSpeed.vlmax;
                        vamax = this.param.lowSpeed.vamax;

                    otherwise % mode non reconue.
                        this.status = this.ERR_INVALID_SPEED_PARAM;
                        fprintf('INFO : proc planner : Speed parameter is not recognized \n');
                        return
                end

                % Trouver la distance Eucledienne entre 2 points
                d = norm( this.pointList(i,:) - this.pointList(i-1,:));

                % Déterminer le temps selon aMax
                tl = (4 * sqrt(3 * d)) / (3 * sqrt(amax));

                % Déterminer la vitesse maximum de la trajectoire
                vl = (amax * tl) / 4;

                % Si la vitesse est plus grande que la vitesse maximum
                if vl > vlmax
                    % Calculer le temps selon vmax
                    tl = (4 * d) / (3 * vlmax);
                end

                % Déterminer l'angle entre les 2 quaternions
                qRel = quatmultiply( quatconj( this.quatList(i-1,:)), this.quatList(i,:));
                travelAngle = 2 * atan2(norm(qRel(2:4)),qRel(1));

                % Déterminer le temps angulaire
                ta = travelAngle / vamax;

                % Déterminer le temps maximale
                tmax = max([tl,ta,this.param.ts]);

                % Arrondire supperieur selont ts
                tresidual = mod(tmax,this.param.ts);

                if tresidual > 0
                    tmax = tmax + (this.param.ts - tresidual);
                end


                this.timeList(i) = this.timeList(i-1) + tmax;
            end

            valid = true;
        end

        %==================================================================
        % Fonction qui interpole les waypoints
        function interpolateWaypoints(this)

             % vecteur temps
             t = this.param.ts : this.param.ts : this.timeList(end);

             % Interpoler la trajectoire lineaire
             this.trajPosition(:,1) = this.interpStrategy(this.timeList,this.pointList(:,1),t,false).';
             this.trajPosition(:,2)  = this.interpStrategy(this.timeList,this.pointList(:,2),t,false).';
             this.trajPosition(:,3) = interp1(this.timeList,this.pointList(:,3),t,'pchip').'; % par sécurité, on ne veux pas de courbe en z. laissez pchip

             % Deriver la trajectoire pour avoir les vitesse linéare;
             this.trajBodyVelocity(:,1) = [0 ; diff(this.trajPosition(:,1))];
             this.trajBodyVelocity(:,2) = [0 ; diff(this.trajPosition(:,2))];
             this.trajBodyVelocity(:,3) = [0 ; diff(this.trajPosition(:,3))];

             % Deriver la vitesse pour avoir les acceleration linéare;
             this.trajLinearAcceleration(:,1) = [0 ; diff(this.trajBodyVelocity(:,1))];
             this.trajLinearAcceleration(:,2) = [0 ; diff(this.trajBodyVelocity(:,2))];
             this.trajLinearAcceleration(:,3) = [0 ; diff(this.trajBodyVelocity(:,3))];

             % Interpoler l'orientation avec pchip. résultat plus smooth/moins jerk que slerp.
             % De plus, pas d'oscillation
             this.trajQuat(:,1) = interp1(this.timeList,this.quatList(:,1),t,'pchip').'; % eta
             this.trajQuat(:,2) = interp1(this.timeList,this.quatList(:,2),t,'pchip').'; % epsilon 1
             this.trajQuat(:,3) = interp1(this.timeList,this.quatList(:,3),t,'pchip').'; % epsilon 2
             this.trajQuat(:,4) = interp1(this.timeList,this.quatList(:,4),t,'pchip').'; % epsilon 3

             % Dériver l'orientation
             qdot = zeros(this.nbPoint,4);
             qdot(:,1) = [0 ; diff(this.trajQuat(:,1))]; % eta_dot
             qdot(:,2) = [0 ; diff(this.trajQuat(:,2))]; % epsilon 1 dot
             qdot(:,3) = [0 ; diff(this.trajQuat(:,3))]; % epsilon 2 dot
             qdot(:,4) = [0 ; diff(this.trajQuat(:,4))]; % epsilon 3 dot

             % Post traitement
             for i = 1 : this.nbPoint

                % Normaliser les quaternions car l'interpolation de type spline ne le garentie pas.
                this.trajQuat(i,:) = this.qUtils.quatNorm(this.trajQuat(i,:));

                 % verifier la discontinuité du quaternion.
                 if i > 1 && dot(this.trajQuat(i-1,:), this.trajQuat(i,:)) < 0
                    this.trajQuat(i,:) = -this.trajQuat(i,:);

                end

                % Convertir les vitesse lineaire dans le ref sub
                this.trajBodyVelocity(i,:) = this.qUtils.quatRotation(this.trajBodyVelocity(i,:), this.trajQuat(i,:));

                % Convertir des quaternion instantané en vitesse angulaire
                this.trajAngulairRates(i,:) =  this.qUtils.qDot2angularRates(this.trajQuat(i,:),qdot(i,:));

                % Convertir les vitesse angulaire dans le ref sub
                this.trajAngulairRates(i,:) = - this.trajAngulairRates(i,:);

                % Convertire les accélération angulaire dans le ref sub
                this.trajLinearAcceleration(i,:) = this.qUtils.quatRotation(this.trajLinearAcceleration(i,:), this.trajQuat(i,:));

             end

             % Calucler les acceleration angulaire
             this.trajAngularAcceleration(:,1) = [0 ; diff(this.trajAngulairRates(:,1))]; % p_dot
             this.trajAngularAcceleration(:,2) = [0 ; diff(this.trajAngulairRates(:,2))]; % q_dot
             this.trajAngularAcceleration(:,3) = [0 ; diff(this.trajAngulairRates(:,3))]; % rs_dot
        end

        %==================================================================
        % Fonction qui envoie les message sur ros
        function trajList = interpStrategy(this, timeList, pointList, sample, verif)

            % Le parametre verif permet au constructeur de verifier si le mode existe sans interpoler.
            % Determiner le type d'imterpolation
            switch this.MAPM.InterpolationMethod

            case 0 % piecewise cubic interpolation
                if~(verif)
                     trajList = interp1(timeList,pointList,sample,'pchip');

                else
                    trajList = 1 ;

                end

            case 1 % spline
                if~(verif)
                    trajList = interp1(timeList,pointList,sample,'spline');

                else
                    trajList = 1 ;

                end

            case 2 % Cubic convolution
                if~(verif)
                    trajList = interp1(timeList,pointList,sample,'v5cubic');

                else
                    trajList = 1 ;

                end

            otherwise
                trajList = 0 ;

            end

        end

        %==================================================================
        % Fonction qui envoie les message sur ros

        function info = sendTrajectory(this, trajpub)

            % Initialiser le message trajectoire.
            trajMsg = rosmessage('trajectory_msgs/MultiDOFJointTrajectoryPoint',"DataFormat","struct"); % message point
            transformBuff  = rosmessage('geometry_msgs/Transform.msg',"DataFormat","struct"); % trajectoire
            twistBuff = rosmessage('geometry_msgs/Twist.msg',"DataFormat","struct"); % trajectoire

           % initialiser la dimention vecteur de points
            trajMsg.Transforms = repelem(transformBuff,this.nbPoint).';
            trajMsg.Velocities = repelem(twistBuff,this.nbPoint).';
            trajMsg.Accelerations = repelem(twistBuff,this.nbPoint).';

            % Remplire le message ROS
            for i=1 : this.nbPoint

                % Remplire le message Transform.
                transformBuff.Translation.X = this.trajPosition(i,1);
                transformBuff.Translation.Y = this.trajPosition(i,2);
                transformBuff.Translation.Z = this.trajPosition(i,3);

                transformBuff.Rotation.W = this.trajQuat(i,1);
                transformBuff.Rotation.X = this.trajQuat(i,2);
                transformBuff.Rotation.Y = this.trajQuat(i,3);
                transformBuff.Rotation.Z = this.trajQuat(i,4);

                trajMsg.Transforms(i) = transformBuff;

                % Remplire les vitesse
                twistBuff.Linear.X = this.trajBodyVelocity(i,1);
                twistBuff.Linear.Y = this.trajBodyVelocity(i,2);
                twistBuff.Linear.Z = this.trajBodyVelocity(i,3);

                twistBuff.Angular.X = this.trajAngulairRates(i,1);
                twistBuff.Angular.Y = this.trajAngulairRates(i,2);
                twistBuff.Angular.Z = this.trajAngulairRates(i,3);

                trajMsg.Velocities(i) = twistBuff;

               % Remplire les acceleration
                twistBuff.Linear.X = this.trajLinearAcceleration(i,1);
                twistBuff.Linear.Y = this.trajLinearAcceleration(i,2);
                twistBuff.Linear.Z = this.trajLinearAcceleration(i,3);

                twistBuff.Angular.X = this.trajAngularAcceleration(i,1);
                twistBuff.Angular.Y = this.trajAngularAcceleration(i,2);
                twistBuff.Angular.Z = this.trajAngularAcceleration(i,3);
                trajMsg.Accelerations(i) = twistBuff;

            end

            % Envoyer le message
            send(trajpub,trajMsg);
            fprintf('INFO : proc planner : Trajectory generation succeded with %d points. \n',int16(this.nbPoint));

            % Si on roule en simulation
            if coder.target('MATLAB')
                % Retourner la trajectoire
                info = trajMsg;
                Traj_viewer(trajMsg)

            else
                % Retourner true (sucess)
                info = 1;

            end
        end
        %==================================================================
        % Fonnction qui retoure le waypoint initial
        function status = getInitialWaypoint(this,icMsg)

                % Replire les listes.
                 this.pointList(1,:) = [icMsg.Position.X,...
                                        icMsg.Position.Y,...
                                        icMsg.Position.Z];

                 this.quatList(1,:) = [icMsg.Orientation.W,...
                                       icMsg.Orientation.X...
                                       icMsg.Orientation.Y...
                                       icMsg.Orientation.Z];

                 this.timeList(1) = 0;
                 this.speedList(1) = 0;

                 eul = rad2deg(quat2eul(this.quatList(1,:),"ZYX"));
                 this.courseList(1) = eul(1);

                % Copier le point 2 fois pour forcé accInit a 0.
                 this.pointList(2,:) = this.pointList(1,:);
                 this.quatList(2,:) = this.quatList(1,:);
                 this.timeList(2) = this.param.ts;
                 this.courseList(2) = eul(1);
                 this.speedList(2) = this.speedList(1);
                 status = true;
        end

    end
end

