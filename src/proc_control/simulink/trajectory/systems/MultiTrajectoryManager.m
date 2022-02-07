classdef MultiTrajectoryManager < matlab.System
    % Traite les trajectoires recu par proc planner. Calcule aussi target reached.

    % Public, tunable properties
    properties(Nontunable)
         mpcParam;
    end
    
    properties(DiscreteState)
        poseBuffer; % Buffer de trajectoire
        bufferCount; % nombre de points dans le buffer
        done; % flag qui indique qu'il reste qu'un point dans le buffer
        targetReachedCount; % compteur du target reached
        initialPose;
        init;
    end

    % Pre-computed constants
    properties(Access = private)

        dummy;
        emptyArray;
    end

    methods(Access = protected)

        function  resetImpl(this)
            
           % Perform one-time calculations, such as computing constants
           this.dummy=999;% Chiffre NULL
           this.emptyArray= repmat(this.dummy, 1, this.mpcParam.nx); % Vecteur pose NULL
           this.targetReachedCount=0;
           this.initialPose = zeros(1,7);

           % Buffer trajectoire
           this.poseBuffer=repmat(this.dummy, this.mpcParam.trajectory.bufferSize, this.mpcParam.nx);
           this.bufferCount = 0 ;
           this.done = false;
           this.init = 0;
           
           
           
        end

        %% ================================================================
        % Main execute a chaque iteration.
        function [currentPose, isReached, isTrajDone initWpt] = stepImpl(this, isNew, trajMsg, reset,mesuredPose)
   
            
            if reset || ~this.init

                this.resetImpl();
                this.resetTrajectory(mesuredPose);
                this.init = 1;
            end
    
%              if this.init==0 
%                  % Conditions Initiales
%                  this.poseBuffer(1:this.mpcParam.p,:)=repmat([x0,0,0,0,0,0,0],this.mpcParam.p,1);%InitCond;
%                  this.bufferCount =1;
%                  this.init=1;
%              end
            
            
            % Add new pose if new arrive
            this.processNewPoses(trajMsg, isNew);
            
            currentPose = this.SendCurrentPoses();
            isReached = this.targetReached(mesuredPose);
            isTrajDone = this.done; 
            initWpt = this.initialPose(1:7);
        end      
        
        %% ================================================================
        % Fonction qui traites les nouveau poses.
        function processNewPoses(this,trajMsg,new)
           
             % Si il y a des noiveau points
             if new 
                
                % nombre de points recu.
                count = double(trajMsg.Transforms_SL_Info.ReceivedLength);         
                
                
                % si il y a asser de place dans le buffer.
                if count + this.bufferCount <  this.mpcParam.trajectory.bufferSize
                        
                    tamp = zeros(1,this.mpcParam.nx);
                     % Remplire le tampon
                     for i=1 : count
                         tamp(1) = trajMsg.Transforms(i).Translation.X;
                         tamp(2) = trajMsg.Transforms(i).Translation.Y;
                         tamp(3) = trajMsg.Transforms(i).Translation.Z;
                    
                         tamp(4) = trajMsg.Transforms(i).Rotation.W;
                         tamp(5) = trajMsg.Transforms(i).Rotation.X;
                         tamp(6) = trajMsg.Transforms(i).Rotation.Y;
                         tamp(7) = trajMsg.Transforms(i).Rotation.Z;
                    
                         tamp(8) = trajMsg.Velocities(i).Linear.X;
                         tamp(9) = trajMsg.Velocities(i).Linear.Y;
                         tamp(10) = trajMsg.Velocities(i).Linear.Z;
                         
                    
                         tamp(11) = trajMsg.Velocities(i).Angular.X;
                         tamp(12) = trajMsg.Velocities(i).Angular.Y;
                         tamp(13) = trajMsg.Velocities(i).Angular.Z;

                         this.bufferCount = this.bufferCount + 1;
                         this.poseBuffer(this.bufferCount,:) = tamp;
                         
                     end
                     
                    % Definir le pose initial pour la prochaine trajectoire
                    this.initialPose = tamp(1:7);
                  
                else
                    fprintf('WARNING : proc control : trajectory buffer overflow.');

                end    
            end  
        end

        %% ================================================================
        % Fonction qui retourne la pose actuelle
        function currPose = SendCurrentPoses(this)

            % Vérification des prédictions.
            index = 2;
            isempty =false;
            
            % Vérifier s'il reste au moins mpc.p points dans les buffers
            for i = 2 : this.mpcParam.p
                index = i;
                if this.poseBuffer(i,:) == this.emptyArray
                     isempty = true;
                     break;
                end
            end
            
            currPose = zeros(this.mpcParam.p, 13);
            
            currPose(1:index,:) = this.poseBuffer(1:index,:);
            
            % S'il ya moins de mpc.p points, padder avec le dernier points
            if isempty
                for i = index: this.mpcParam.p
                    currPose(i,:) = currPose(index - 1,:);
                end  
            end
                
            % Ne pas supprimer le point si c'est le dernier.
            if not(this.poseBuffer(2 , :) == this.emptyArray) %this.prediction+1
               this.poseBuffer=[this.poseBuffer(2:end,:); this.emptyArray];
               this.bufferCount = this.bufferCount - 1;
               this.done=false;
            else
                this.done=true;
            end 
        end
        
        %% ================================================================
        % Fonction qui verifie le target reached
    
        function isReached= targetReached(this, mesuredPose )
   
            isReached = false;
           
            % vérifier le traget reached si la trajectoire est terminé
            if this.done

                target = this.poseBuffer(1,:);

                 % calcule de l'angle entre les 2 quaternions
                 qRel = quatmultiply(quatconj(target(4:7)),mesuredPose(4:7).');
                 errAngle = 2 * atan2(norm(qRel(2:4)),qRel(1));
                
                % vérifier si le sub est dans la zone de convergence (sphérique / conique)
                if norm(target(1:3) - mesuredPose(1:3)) < this.mpcParam.targetReached.linearTol &&  errAngle < this.mpcParam.targetReached.angularTol
                   
                   this.targetReachedCount = this.targetReachedCount + 1;
                   
                   % si le sub est dans la zone de convergence depuis le temps demander
                   if this.targetReachedCount * this.mpcParam.Ts >= this.mpcParam.targetReached.timeInTol

                        isReached = true;    
                   end
                   
                else
                % Remettre le compteur a 0 si le sub n'est pas dans la zone
                this.targetReachedCount = 0;     
               end     
          
            end
        end

         %=================================================================  
         % Fonction qui reset la trajectoire 
         function resetTrajectory(this, initcond)
             
             % remove roll and pitch from initial condition
             eul = quat2eul(initcond(4:7).','XYZ').*[0,0,1];
             
             % Retransformer en quaternion
             initcond(4:7) = eul2quat(eul,'XYZ').';

             % Mettre les vitesse à 0;
             initcond(8:13) = zeros(1,6);

             % definir les conditions initiaux
             this.poseBuffer(1,:) = initcond ;%InitCond;
             this.bufferCount = 1;

             this.initialPose = initcond(1:7).';
         end
          
        
      
    end    
end
