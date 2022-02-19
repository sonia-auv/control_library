classdef TrajectoryGenerator < handle
    %TRAJECTORYGENERATOR Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        status = true;
    end

    properties (Access = private)

        % Parametres
        n;         % Nombre de waypoints
        pointList; % liste de position.
        quatList;  % liste de quaternion.
        timeList;  % liste de temp
        nbPoint = 1;   % Nombre de points dans la trajectoire
       lastConj = false;
        % Structures
            MAPM; % Multi Add Pose Msg
            param % paramètre de trajectoire

    end
    
    methods
        %==================================================================
        % Constructeur
        function this = TrajectoryGenerator(multiAddposeMsg, param, icMsg)
            
            this.MAPM =multiAddposeMsg;

            % nombre de waypoints + iC
            this.n = max(size(multiAddposeMsg.Pose))+3; % matlab and cpp dont use same index. return max instead
            
            % Initialiser les tableaux
            this.pointList = zeros(this.n,3);
            this.quatList = zeros(this.n,4);
            this.timeList = zeros(this.n,1);

            % Initialiser les parametres
            this.param = param;

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
                this.computetimeArrival();
    
                % Déterminer le nombre de points
                this.nbPoint = floor(this.timeList(end) / this.param.ts);
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

            for i = 1 : this.n - 3 % pour chaques waypoints

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
                        this.quatList(i+2,:) = q;
                        this.pointList(i+2,:) = p; 
        
                    case 1 % position et angle relatif
                        this.quatList(i+2,:) = this.getQuatDir(this.quatList(i+1,:), q, this.MAPM.Pose(i).Rotation);
                        this.pointList(i+2,:) = this.pointList(i+1,:) + this.quatrotation(p,this.quatList(i+2,:));
                        
        
                    case 2 % position relatif et angle absolue             
                        this.quatList(i+2,:) = q;
                        this.pointList(i+2,:) = this.pointList(i+1,:) + this.quatrotation(p,q);
        
                    case 3 % position absolue et angle relatif
                        this.quatList(i+2,:) = this.getQuatDir(this.quatList(i+1,:), q, this.MAPM.Pose(i).Rotation);
                        this.pointList(i+2,:) = p;
        
                    otherwise % Le referentiel n'est pas valide
                        states = false;
                        status = states;
                        return
                end
            end

            % Copier le dernier waypoint 2 fois pour éviter un comportement
            % du generateur de trajecteur
            this.pointList(end,:) = this.pointList(end-1,:); 
            this.quatList(end,:) = this.quatList(end-1,:);
            status = states;
        end

        %================================================================== 
        % Fonnction qui retoure le quaternion le plus court/long selon
        % l'utilisateur
     
         function rq =  getQuatDir(this,lq,q,dir)    
             
            
            
            norm = dot(lq,q);
            if this.lastConj
                lq = quatconj(lq);
                this.lastConj =false;
            
            

            % conjuger le quaternion au besoin
            %if  norm > 1 && dir == 0 || norm < 1 && dir == 1


            elseif  norm < 0  && dir == 0 || norm >= 0 && dir == 1
                q = quatconj(q);    
                this.lastConj =true;

            end
            
            

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
        % Fonnction qui calcul le temps entre chaque waypoint

        function  computetimeArrival(this)

            for i = 2 : this.n % pour chaques waypoints

                % Trouver la distance Eucledienne entre 2 points
                d = norm( this.pointList(i,:) - this.pointList(i-1,:));

                % Déterminer le temps selon aMax
                tl = (4 * sqrt(3 * d)) / (3 * sqrt(this.param.amax));

                % Déterminer la vitesse maximum de la trajectoire
                vl = (this.param.amax * tl) / 4;

                % Si la vitesse est plus grande que la vitesse maximum
                if vl > this.param.vlmax
                    % Calculer le temps selon vmax
                    tl = (4 * d) / (3 * this.param.vlmax);
                end

                % Déterminer l'angle entre les 2 quaternions
                qRel = quatmultiply( quatconj( this.quatList(i-1,:)), this.quatList(i,:));
                travelAngle = 2 * atan2(norm(qRel(2:4)),qRel(1));

                % Déterminer le temps angulaire 
                ta = travelAngle/this.param.vamax;

                this.timeList(i) = this.timeList(i-1) + max([tl,ta,this.param.ts]);
            end
        end
        %================================================================== 
        % Fonnction qui interpole les waypoints

        function info = interpolateWaypoints(this, trajpub)  

            % Crée l'objet waypoint trajectory
            trajObj = waypointTrajectory(this.pointList, this.timeList,...
                                         'SampleRate', 1/this.param.ts,...
                                         'SamplesPerFrame',1,...
                                         'Orientation', quaternion(this.quatList));

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

            % lire la position initale
            % [this.icMsg, status] = receive(this.icSub,5);
            %this.icMsg = this.icSub.LatestMessage;
            
            %status = ~isempty(this.icMsg);
            
         
                % Replire les listes.
                 this.pointList(1,:) = [icMsg.Position.X,...
                                        icMsg.Position.Y,...
                                        icMsg.Position.Z];
    
                 this.quatList(1,:) = [icMsg.Orientation.W,...
                                       icMsg.Orientation.X...
                                       icMsg.Orientation.Y...
                                       icMsg.Orientation.Z];

                 this.timeList(1) = 0;
                 
                % Copier le point 2 fois pour forcé accInit a 0.
                 this.pointList(2,:) = this.pointList(1,:);
                 this.quatList(2,:) = this.quatList(1,:);
                 this.timeList(2) = this.param.ts;

                 status = true;
        end
        

    end
end

