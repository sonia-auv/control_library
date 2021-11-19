classdef TrajectoryManager < matlab.System
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties(Nontunable)
     SampleTime=.25;
     OffsetTime = 0; % Offset Time
     prediction =4;  % prediction controlleur
     bufferSize=6001; % Taille statique 
    
     SampleTimeTypeProp (1, 1) {mustBeMember(SampleTimeTypeProp, ...
            ["Discrete","FixedInMinorStep","Controllable",...
            "Inherited","InheritedNotControllable",...
            "InheritedErrorConstant"])} = "Inherited"
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
        function  setupImpl(this, pose, isNew, reset)
            
            % Perform one-time calculations, such as computing constants
           this.generationNumber=0;
           this.dummy=999;% Chiffre NULL
           this.emptyArray= repmat(this.dummy, 1, 13); % Vecteur pose NULL
           this.targetReachedCount=0;
           % Buffer trajectoire
           this.poseBuffer=repmat(this.dummy, this.bufferSize, 13);
           this.bufferCount =0;
           this.done=false;
           this.init=0;
           
           
           
        end
%% Main execute a chaque iteration.
        function [currentPose, isReached] = stepImpl(this, poses, target, reset,x0,mesuredPose)
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
            
            isReached= this.targetReached(mp, target);
           
        end

%% Fonction reset
        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
      
        
%% Fonction qui traites les nouveau poses.
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
%% Fonction qui retourne la pose actuelle
    function currPose = SendCurrentPoses(this)
         % Vérification des prédictions.
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
%% Fonction qui verifie le target reached

function isReached= targetReached(this, mesuredPose, target)
    
    isReached = false;
    
    % vérifier le traget reached si la trajectoire est terminé
    if ~this.done
        
         % calcule de l'erreur de langle en 3D avec le quaternion
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
 %% Fonction qui gere le sample time  
      function sts = getSampleTimeImpl(obj)
            switch char(obj.SampleTimeTypeProp)
                case 'Inherited'
                    sts = createSampleTime(obj,'Type','Inherited');
                case 'InheritedNotControllable'
                    sts = createSampleTime(obj,'Type','Inherited',...
                        'AlternatePropagation','Controllable');
                case 'InheritedErrorConstant'
                    sts = createSampleTime(obj,'Type','Inherited',...
                        'ErrorOnPropagation','Constant');
                case 'FixedInMinorStep'
                    sts = createSampleTime(obj,'Type','Fixed In Minor Step');
                case 'Discrete'
                    sts = createSampleTime(obj,'Type','Discrete',...
                      'SampleTime',obj.SampleTime, ...
                      'OffsetTime',obj.OffsetTime);
              
            end
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
