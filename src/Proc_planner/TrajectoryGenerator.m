classdef TrajectoryGenerator < handle
    %TRAJECTORYGENERATOR Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        status = true;
    end

    properties (Access = private)

        % Parametres 
        nMAPM;
        n;         % Nombre de waypoints 
        pointList; % liste de position.
        quatList;  % liste de quaternion.
        timeList;  % liste de temp
        courseList; % Liste de courbe
        speedList; % parametre de vitesse 
        nbPoint = 1;   % Nombre de points dans la trajectoire
        lastConj = false;
        icOffset = 2; % nombre de point pour la condition initial
        % Structures
        MAPM; % Multi Add Pose Msg
        param % paramètre de trajectoire

    end
    
    methods
        %==================================================================
        % Constructeur
        function this = TrajectoryGenerator(multiAddposeMsg, param, icMsg)
            
            this.MAPM =multiAddposeMsg;
            this.nMAPM = max(size(multiAddposeMsg.Pose)); % matlab and cpp dont use same index. return max instead

             % Initialiser les parametres
             this.param = param;

            % point supplementaire pour l'arrondissement.
            suppPoint = 0;

            for i=1 : this.nMAPM
                
                if ~(this.MAPM.Pose(i).Fine == 0)
                    suppPoint =suppPoint + 1;
                end
            end

            % nombre de waypoints + iC + point supp
            this.n = this.nMAPM + suppPoint + this.icOffset + 1; 

            % Initialiser les tableaux
            this.pointList = zeros(this.n,3);
            this.quatList = zeros(this.n,4);
            this.timeList = zeros(this.n,1);
            this.courseList = zeros(1, this.n);
            this.speedList = zeros(1, this.n);

            % trouver le waypoint initial
            if ~this.getInitialWaypoint(icMsg)
                this.status = false;
                fprintf('INFO : proc planner : initial waypoint not received \n');
                
            end

            % Process le message addpose
            if ~logical(this.processWpt())
                this.status = false;
                fprintf('INFO : proc planner : Waypoints are not valid  \n');
              
            end
            
            if this.status
                % Calculer les temps entre chaque waypoints

                 if logical(this.computetimeArrival());
                    % Déterminer le nombre de points
                    this.nbPoint = floor(this.timeList(end) / this.param.ts);
                
                 else
                    fprintf('INFO : proc planner : Speed parameter not recognized \n');
                    this.status = false;
                 end
    
                
            end
           
        end
        %==================================================================
        % Fonction Main qui génère les waypoints
        function status = Compute(this,trajpub)

            % Interpoler les waypoints
            status = this.interpolateWaypoints(trajpub);  
            
        end
            
    end

%% ========================================================================
    % Private function

    methods (Access = private)

        %==================================================================
        % Fonction qui interprete les waypoints reçu par ROS
        function status = processWpt(this)
            
           states = true; 

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
                        this.quatList(i+this.icOffset,:) = q;
                        this.pointList(i+this.icOffset,:) = p; 
        
                    case 1 % position et angle relatif
                        this.quatList(i+this.icOffset,:) = this.getQuatDir(this.quatList(i+this.icOffset-1,:), q, this.MAPM.Pose(i).Rotation);
                        this.pointList(i+this.icOffset,:) = this.pointList(i+this.icOffset-1,:) + this.quatrotation(p,this.quatList(i+this.icOffset-1,:));
                        
        
                    case 2 % position relatif et angle absolue             
                        this.quatList(i+this.icOffset,:) = q;
                        this.pointList(i+this.icOffset,:) = this.pointList(i+this.icOffset-1,:) + this.quatrotation(p,this.quatList(i+this.icOffset-1,:));
        
                    case 3 % position absolue et angle relatif
                        this.quatList(i+this.icOffset,:) = this.getQuatDir(this.quatList(i+this.icOffset-1,:), q, this.MAPM.Pose(i).Rotation);
                        this.pointList(i+this.icOffset,:) = p;
        
                    otherwise % Le referentiel n'est pas valide
                        states = false;
                        status = states;
                        return
                end

                % copier le parametre de vitesse
                this.speedList(i + this.icOffset) = this.MAPM.Pose(i).Speed;

                % determiner le yaw pour le vecteur course
                this.courseList(i+this.icOffset) = this.getCourseAngle(this.quatList(i+this.icOffset,:));

                % verifier si faut arrondire la trajectoire.
                    if i>1 && this.MAPM.Pose(i-1).Fine ~=0

                        [status, p01, p12] = this.inscribedCircles(i+this.icOffset);

                        if ~status
                            status = false;
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
            %this.pointList(end,1) = -0.1;
            this.quatList(end,:) = this.quatList(end-1,:);
            this.courseList(end) = this.courseList(end-1);
            this.speedList(end) = this.speedList(end-1);
            status = states;
        end

        %================================================================== 
        % Fonnction qui retoure le quaternion le plus court/long selon
        % l'utilisateur
     
         function rq =  getQuatDir(this,lq,q,dir)    


%           norm = dot(lq,q);
%             % conjuger le quaternion au besoin
%             %if  norm > 1 && dir == 0 || norm < 1 && dir == 1
%            if  norm < 0  && dir == 0 || norm >= 0 && dir == 1
%                 q = quatconj(q);    
%                 this.lastConj =true;
% 
%             end
            
            rq = quatmultiply(lq,q);
            
         end
         %=================================================================
         % Fonction qui tourne un vecteur selon un quaternion.
         function rp = quatrotation(this,p,q)

             qs = q(1);   % quaternion partie scalaire
             qu = q(2:4); % quaternion partie vectoriel

             % QuatRotate n'est pas compilable
             rp= (2*dot(qu,p)*qu +(qs^2-dot(qu,qu))*p + 2*qs*cross(qu,p)); 
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

                % Calculer alpha 1
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
                p01 = this.pointList(i-1,:);
                p12 = this.pointList(i-1,:);
                status = true; 
            end
        end

        %================================================================== 
        % Fonnction qui calcul le temps entre chaque waypoint

        function  status = computetimeArrival(this)

            status = false;

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

                this.timeList(i) = this.timeList(i-1) + max([tl,ta,this.param.ts]);
            end

            status = true;

        end

        %================================================================== 
        % Fonction qui interpole les waypoints

        function info = interpolateWaypoints(this, trajpub)  

            % Crée l'objet waypoint trajectory
            trajObj = waypointTrajectory(this.pointList, this.timeList,...
                                         'SampleRate', 1/this.param.ts,...
                                         'SamplesPerFrame',1,...
                                         'Orientation', quaternion(this.quatList), ...
                                         'Course',this.courseList);

            % Initialiser le message trajectoire.
            trajMsg = rosmessage('trajectory_msgs/MultiDOFJointTrajectoryPoint',"DataFormat","struct"); % message point
            transformBuff  = rosmessage('geometry_msgs/Transform.msg',"DataFormat","struct"); % trajectoire
            twistBuff = rosmessage('geometry_msgs/Twist.msg',"DataFormat","struct"); % trajectoire

           % initialiser la dimention vecteur de points 
            trajMsg.Transforms = repelem(transformBuff,this.nbPoint).';
            trajMsg.Velocities = repelem(twistBuff,this.nbPoint).';
            trajMsg.Accelerations = repelem(twistBuff,this.nbPoint).';

            lastQuat =zeros(1,4);

            % Générer les points de la trajectoire
            for i=1 : this.nbPoint
                [BufferPose, bufferQuat, bufferVelocity ,bufferAcc ,bufferAngRate] = trajObj();

                % Remplire le message Transform.
                transformBuff.Translation.X = BufferPose(1);
                transformBuff.Translation.Y = BufferPose(2);
                transformBuff.Translation.Z = BufferPose(3);
                
                % Convertir l'objet quaternion en vecteur
                bufferQuat = compact(bufferQuat);
                
                % Verifier de retourner la rotation la plus petite
                if i > 1 && dot(lastQuat,bufferQuat) < 0
                    bufferQuat = -bufferQuat;
                end
                lastQuat = bufferQuat;

                transformBuff.Rotation.W = bufferQuat(1);
                transformBuff.Rotation.X = bufferQuat(2);
                transformBuff.Rotation.Y = bufferQuat(3);
                transformBuff.Rotation.Z = bufferQuat(4);

                trajMsg.Transforms(i) = transformBuff;
                
                % Convertir les vitesse dans le ref sub
                bufferVelocity = this.quatrotation(bufferVelocity, bufferQuat);
               
                % Remplire les vitesse
                twistBuff.Linear.X = bufferVelocity(1);
                twistBuff.Linear.Y = bufferVelocity(2);
                twistBuff.Linear.Z = bufferVelocity(3);

                twistBuff.Angular.X = -bufferAngRate(1); % (-) pour convertir les vitesse angulaire dans le ref sub
                twistBuff.Angular.Y = -bufferAngRate(2);
                twistBuff.Angular.Z = -bufferAngRate(3);
                
                trajMsg.Velocities(i) = twistBuff;
                % Ecrire le point dans le message
                
                % Convertir les accels dans le ref sub
                bufferAcc = this.quatrotation(bufferAcc,bufferQuat);

               % Remplire les acceleration
                twistBuff.Linear.X = bufferAcc(1);
                twistBuff.Linear.Y = bufferAcc(2);
                twistBuff.Linear.Z = bufferAcc(3);

                twistBuff.Angular.X = 0;
                twistBuff.Angular.Y = 0;
                twistBuff.Angular.Z = 0;
                trajMsg.Accelerations(i) = twistBuff;

            end
            % Envoyer le message
            send(trajpub,trajMsg);
            fprintf('INFO : proc planner : Trajectory generation succeded with %d points. \n',int16(this.nbPoint));
            % Si on roule en simulation
            if coder.target('MATLAB')
                % Retourner la trajectoire
                info = trajMsg;
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

