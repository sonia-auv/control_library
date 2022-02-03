classdef MultiTrajectoryManager < matlab.System
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties(Nontunable)

         SampleTime = 0.1;  % Sample time du controlleur
         prediction = 10;   % prediction controlleur
         bufferSize = 6001; % Taille statique
         mpcParam;
    end
    
    properties 
         linearConvergence= .2;    % Metre
         quaternionConvergence=.1; % Radian
         TargetThreshold = 3;      % seconde
    end
    
    properties(DiscreteState)
        poseBuffer;
        generationNumber;
        bufferCount;
        %pMax;
        done;
        targetReachedCount;
        init;
    end

    % Pre-computed constants
    properties(Access = private)

        dummy;
        emptyArray;
    end

    methods(Access = protected)

        function  resetImpl(this, pose, isNew, reset)
            
           % Perform one-time calculations, such as computing constants
           this.generationNumber=0;
           this.dummy=999;% Chiffre NULL
           this.emptyArray= repmat(this.dummy, 1, this.mpcParam.nx); % Vecteur pose NULL
           this.targetReachedCount=0;

           % Buffer trajectoire
           this.poseBuffer=repmat(this.dummy, this.bufferSize, this.mpcParam.nx);
           this.bufferCount =0;
           this.done=false;
           this.init=0;
           
           
           
        end

        %% ================================================================
        % Main execute a chaque iteration.
        function [currentPose, isReached, isTrajDone] = stepImpl(this, poses, isNew, reset,x0,mesuredPose)
            % Implement algorithm. Calculate y as a function of input u and
            new = 1;
            count = 1;
            mp =zeros(1,7);
            mp=mesuredPose(1:7);
            
            if reset == 1
                this.init = 0;
            end
    
             if this.init==0 
                 % Conditions Initiales
                 this.poseBuffer(1:this.prediction,:)=repmat([x0,0,0,0,0,0,0],this.prediction,1);%InitCond;
                 this.bufferCount =1;
                 this.init=1;
             end
            
            
            %this.BufferReset(reset,mp);
            this.processNewPoses(poses,count,new);
            
            currentPose=this.SendCurrentPoses();
            
            isReached= this.targetReached(mp,poses, target);
                   
        end      
        
        %% ================================================================
        % Fonction qui traites les nouveau poses.
        function processNewPoses(this,pose,count,new)
           % Insertion des nouveaux points.
           
             if new == 1
            %if new == this.generationNumber %new>
                
                if count + this.bufferCount < this.bufferSize
                   this.poseBuffer(count + this.bufferCount,:) = pose();
                   %this.poseBuffer(this.bufferCount:count + this.bufferCount,:) = pose(1:count+1,:)
                   this.bufferCount = count + this.bufferCount;
                   this.generationNumber = this.generationNumber+1; 
                else
                    disp("Problem");
                end    
            end  
        end

        %% ================================================================
        % Fonction qui retourne la pose actuelle
        function currPose = SendCurrentPoses(this)
            %   Vérification des prédictions.
            index = 2;
            isempty =false;
            
            for i = 2 : this.prediction
                index = i;
                if this.poseBuffer(i,:) == this.emptyArray
                    isempty =true;
                     break;
                end
            end
            
            currPose = zeros(this.prediction, 13);
            
            currPose(1:index,:) = this.poseBuffer(1:index,:);
            
            if isempty
                for i = index: this.prediction
                    currPose(i,:) = currPose(index - 1,:);
                end  
            end
                
            % Ne pas supprimer le point si c'est le dernier.
            if not(this.poseBuffer(this.prediction+1,:) == this.emptyArray)
               this.poseBuffer=[this.poseBuffer(2:end,:); this.emptyArray];
               this.bufferCount = this.bufferCount - 1;
               this.done=false;
            else
                this.done=true;
            end 
        end
        
        %% ================================================================
        % Fonction qui verifie le target reached
    
        function isReached= targetReached(this, mesuredPose, poses, target)
            
            % vérifier si la trajectoire est fini
            if abs(poses(1:7) - target(1:7)) < 0.001
               this.done = true;
            else
                this.done = false;
            end   
            isReached = false;
           
            % vérifier le traget reached si la trajectoire est terminé
            if this.done
                
                 % calcule de l'angle entre les 2 quaternions
                 qRel = quatmultiply(quatconj(target(4:7)),mesuredPose(4:7));
                 errAngle = 2 * atan2(norm(qRel(2:4)),qRel(1));
                
                % vérifier si le sub est dans la zone de convergence (sphérique / conique)
                if norm(target(1:3) - mesuredPose(1:3)) < this.linearConvergence ...
                   &&  errAngle < this.quaternionConvergence
               
                   this.targetReachedCount = this.targetReachedCount+1;
                   
                   if this.targetReachedCount * this.SampleTime >= this.TargetThreshold
                        isReached = true;    
                   end
                   
                else
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
             this.initcond = initcond.';

             % definir les conditions initiaux
             this.poseList(2:end,:) = repmat(999, this.buffSize-1, this.elementSize);
             this.poseList(1,:) = [this.initcond,0,0];
             this.poseList(2,:) = [this.initcond,1,0];
             this.i = 2;
         end

        %% Fonction Qui reset le buffer
        function BufferReset(this,reset,mesuredPose)
         
          if reset == 1
              this.poseBuffer=repmat(this.dummy, this.bufferSize, 13);
              this.poseBuffer(1,:)= [mesuredPose,0,0,0,0,0,0];
              %this.poseBuffer(1:this.prediction,:)= repmat([mesuredPose,0,0,0,0,0,0],this.prediction,1);
              %this.bufferCount=4;
          end
          
        end
      
    end    
end
