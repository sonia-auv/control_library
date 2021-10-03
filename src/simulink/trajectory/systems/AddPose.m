classdef AddPose < matlab.System
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties (Nontunable)
        buffSize = 21;
        elementSize=8;
    end

    properties(DiscreteState)
        i;
        poseList;
    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods(Access = protected)
%==========================================================================
% Fonctions Principales
%==========================================================================
%% Fonction appeler a l'initialisation
    function setupImpl(this, compute, clearBuffer, isNew, waypoint,initCond, reset)
        % Perform one-time calculations, such as computing constants   

        this.poseList = repmat(999, this.buffSize, this.elementSize);
        this.poseList(1,:)=[0,0,0,1,0,0,0,0,0];%initCond(1,1:7);
        this.i = 2;
    end
%% Main appeller à chaque exécution
    function [waypoints, count] = stepImpl(this, compute, clearBuffer, isNew, waypoint,initCond, reset)
        % Suppression du buffer.
        this.CheckEvent(compute, clearBuffer, isNew,waypoint, initCond, reset);

        count = this.i;
        waypoints = this.poseList;
    end
%% Fonction Reset
    function resetImpl(this)
        % Initialize / reset discrete-state properties
    end
%% ========================================================================
% Sous Routines
%==========================================================================        
% Fonction qui interprete les message ROS
        
    function CheckEvent(this,compute, clearBuffer, isNew,waypoint,initCond, reset )


        if clearBuffer == 1 % supprimer le buffer de way points

                this.poseList(2:end,:) = repmat(999, this.buffSize-1, this.elementSize);
                this.i = 2;

        end
        % Ajout d'un waypoint provenant de ROS.
        if isNew == 1
           if this.i <= this.buffSize
                    %this.poseList(this.i-1,:) = this.processWpt(waypoint.').';
                    this.poseList(this.i,:) = this.processWpt(waypoint.').';
                    this.i = this.i + 1;
           end
        end 

       if   compute == 1
            this.poseList(1,:)= this.poseList(this.i-1,:);
            this.poseList(2:end,:) = repmat(999, this.buffSize-1, this.elementSize);
            this.i = 2;
        end

        if reset
            this.poseList(2:end,:) = repmat(999, this.buffSize-1, this.elementSize);
            this.poseList(1,:) = [initCond,0,0];
            this.poseList(2,:) = [initCond,1,0];
            this.i = 2;
        end
    end
    
%==========================================================================   
% Fonction qui interprete les waypoints reçu par ROS
    function pwpt = processWpt(this, wpt)
        % Determiner le quaternion en fonction des angles d'euler.
        % Orde de rotation : ZYX.
        % Reel
        twpt = zeros(1, this.elementSize);
        twpt(8)=wpt(8);
        % twpt(9)=wpt(9);
        p= wpt(1:3);
        dir= wpt(9);
    
        % Pre calculs
        q = eul2quat(deg2rad(wpt(4:6)),'ZYX');

        lp = this.poseList(this.i-1,1:3);
        lq = this.poseList(this.i-1,4:7);


        % rp = quatrotate(quatinv(lq),wpt(1:3)) + lp;
        %rp = rotatepoint(quatinv(lq),wpt(1:3)) + lp;
         qs = lq(1);   % quaternion partie scalaire
         qu = lq(2:4); % quaternion partie vectoriel
         rp= lp + (2*dot(qu,p)*qu +(qs^2-dot(qu,qu))*p + 2*qs*cross(qu,p));


        % choisir sens du quaternion
        rq =  this.getQuatDir(lq,q,dir);
%         if dot(lq,q)>1
%             rq= quatmultiply(lq,quatconj(q));
%            %rq= quatmultiply(lq,quatconj(q));
%           % rq= quatmultiply(quatinv(lq),quatconj(q));
% 
%         else
%              rq = quatmultiply(lq,((q)));
%             %rq = quatmultiply(lq,quatinv(quatinv(q)));
%            % rq = quatmultiply(quatinv(lq),q);
% 
%         end

        % transformer le point en fonction du frame
        switch cast(wpt(7),'uint8')

            case 0 % position et angle absolue
                twpt(1:3)= wpt(1:3);
                twpt(4:7)=q;

            case 1 % position et angle relatif
                twpt(1:3)= rp;
                twpt(4:7)= rq;

            case 2 % position relatif et angle absolue
                twpt(1:3)= rp;
                twpt(4:7)=q;

            case 3 % position absolue et angle relatif
                twpt(1:3)= wpt(1:3);
                twpt(4:7)= rq;

            otherwise % retourne le point précédent
                twpt(1:3)= lp;
                twpt(4:7)= lq;
        end


        pwpt =twpt;
    end
%==========================================================================   
 % Fonnction qui retoure le quaternion le plus court/long selon
 % l'utilisateur
 
     function rq =  getQuatDir(this,lq,q,dir)    
         
         norm = dot(lq,q);
        
        % conjuger le quaternion au besoin
        if  norm > 1 && dir == 0 || norm < 1 && dir == 1
            q = quatconj(q);      
        end
        
        rq = quatmultiply(lq,q);
     end
 
%%=========================================================================          
 % Definire outputs   
%==========================================================================    
      function [waypoints, count] = getOutputSizeImpl(this)
      waypoints = [this.buffSize this.elementSize];
      count = [1 1];
      end 
      
      function [waypoints, count] = isOutputFixedSizeImpl(this)
          waypoints = true;
          count = true;
      end
      function [waypoints, count] = getOutputDataTypeImpl(this)
          waypoints = "double";
          count = "double";
      end
      
     function [waypoints, count] = isOutputComplexImpl(this)
         waypoints = false;
         count = false;
     end
     
     function [sz,dt,cp] = getDiscreteStateSpecificationImpl(this,name)
         if strcmp(name,'i')
              sz = [1 1];
              dt = "double";
              cp = false;
         
         elseif strcmp(name,'poseList')
             sz = [this.buffSize this.elementSize];
             dt = "double";
             cp = false;
         end
     end 
      
         

     
    end
end
