 classdef mpcManager < matlab.System
    % MPC Manager. Gere les modes et les paramètre du controleur.
    % Regarde aussi l'etat des moteurs

    % Public, tunable properties
    properties (Nontunable)

        MPC; % Config MPC
        mode; % Definitions modes
        
        Tmim; % Force min moteur
        Tmax; % Force max moteur
        
    end
    
    properties(DiscreteState)
        init;     % is block initialise
        currentFaultCount; % Thurster
        isThrusterFault; 
       
        rosOV;
        rosMV;
        rosMVR;
    end 

    % Pre-computed constants
    properties(Access = private)
     
    end
   
    methods(Access = protected)
        
        %% Fonction Reset
        function resetImpl(this)
            % Initialize discrete state
            this.init=0;
            this.currentFaultCount= zeros(1,this.MPC.nu);
            this.isThrusterFault = false(1,this.MPC.nu);
            
            %initialiser les gains debug
            this.rosOV = this.MPC.gains.defaut.OV;
            this.rosMV = this.MPC.gains.defaut.MV;
            this.rosMVR = this.MPC.gains.defaut.MVR;
        end
        
        %% Fonction execute a chaque iteration
        function setupImpl(this,mode,x0)
            % Perform one-time calculations, such as computing constants
        end

        function [mvmin,mvmax,ywt,mvwt,dmwwt, tInfo, kill] = stepImpl(this, newRosGains, rosGains,mode,newReadCurrent,readCurrent, estimatedCurrent, mo)

            
            initMPCManager(this); % Init function
            
            this.readRosGains(newRosGains, rosGains); % traiter les gains recu via ros.
            [ywt,mvwt,dmwwt] = this.getMpcWeigth(mode, mo); % Avoir les gains selon le mode 
            
            this.checkThrustersCurrent(newReadCurrent, readCurrent, estimatedCurrent ); % Vérifier l'etats des thrusters
            [mvmin,  mvmax] = this.getThrusterSaturation();
            tInfo = ~this.isThrusterFault;
            kill = this.isAuvNeedToBeKill();
         
        end
        
        %% Fonction D'initialisation
        function initMPCManager(this)
       
          % Conditions initial
            if this.init==0
                this.init =1;
            end  
        end
        
        %% Fonction qui détermine les gain
        function [OV, MV, MVR]= getMpcWeigth(this, mode, q)
            
          % Vérifier si le mode existe
            corr = this.MPC.gainsList(:,1) == mode;
            
            if mode == this.mode.control.rosGains % Mode ros debug
                
                OV = this.rosOV(1,1:this.MPC.nx);
                MV = this.rosMV(1,1:this.MPC.nu);
                MVR = this.rosMVR(1,1:1:this.MPC.nu);
  
                
            elseif sum(corr) == 1 % mode existe et unique
     
                i = sum(find(corr == 1));
                OV = this.MPC.gainsList(i,2:14);
                MV = this.MPC.gainsList(i,15:22);
                MVR = this.MPC.gainsList(i,23:30);
                    
            else % mode non trouver. retourne defaut
                
                OV = this.MPC.gains.defaut.OV(1,1:this.MPC.nx);
                MV = this.MPC.gains.defaut.MV(1,1:this.MPC.nu);
                MVR = this.MPC.gains.defaut.MVR(1,1:this.MPC.nu);
                
            end

            %  Ajust gain if loosing dvl
            e = abs(quat2eul(q.','ZYX'));

            if(e(2) > deg2rad(20) || e(3) > deg2rad(20)) % If roll pitch exeed 20deg
    
                MV = ones(1,this.MPC.nu) * 0.2;
                
            end
            
        end
        
        %% Fonction qui vérifie l'états des moteurs.
        function checkThrustersCurrent(this,newReadCurrent, readCurrent, estimatedCurrent )
              
               if newReadCurrent
                    temps=zeros(1,8);
                    readCurrent(8) =0;
                % regarder si le courant est en dessou du seuil
                    temp = readCurrent(1:this.MPC.nu) < (estimatedCurrent .* this.MPC.thrusters.faultThres);           
                % Rénitialiser le compteur si thruster est bon
                    this.currentFaultCount = this.currentFaultCount .* temp;
                % Aditionner les échantillion défectueux
                    this.currentFaultCount = this.currentFaultCount + temp;

                % Condition qui vérifie si les thruster sont defectueux
                    temp = this.currentFaultCount >= this.MPC.thrusters.faultSample;
                % rajouter des moteur défecteux   
                    this.isThrusterFault = logical(this.isThrusterFault + temp); 
               end
            end
        
        %% Fonction qui applique la saturation des moteurs
        function [tmin, tmax] = getThrusterSaturation(this)
            
           % Enlever les thrusters defectueux
            tmin = this.Tmim .* cast(~this.isThrusterFault, "double");
            tmax = this.Tmax .* cast(~this.isThrusterFault, "double");
        end
      
      %% Fonction qui prend la decision de kill le sub 
      
      function k  = isAuvNeedToBeKill(this)
          
          k=false;
          
          if sum(this.isThrusterFault(:,1:4))>1 || sum(this.isThrusterFault(:,5:8))
              k = true;
          end
          
          
      end
      
      %% Fonction qui traite les gains recu via ros.
      function readRosGains(this, newRosGains, rosGains)
          
          if newRosGains
          
              if rosGains.OV_SL_Info.CurrentLength == this.MPC.nx % regarder la vaiditée des ov
                  this.rosOV = rosGains.OV(1:this.MPC.nx,1).';
              end
              
              if rosGains.MV_SL_Info.CurrentLength == this.MPC.nu % regarder la vaiditée des mv
                  this.rosMV = rosGains.MV(1:this.MPC.nu,1).';
              end
              
              if rosGains.MVR_SL_Info.CurrentLength == this.MPC.nu % regarder la vaiditée des mvr
                  this.rosMVR = rosGains.MVR(1:this.MPC.nu,1).';
              end
          end
          
      end
      
      %% Definire outputs       
      function [mvmin,mvmax,ywt,mvwt,dmwwt,tInfo,kill] = getOutputSizeImpl(this)
          mvmin = [1,this.MPC.nu];
          mvmax = [1,this.MPC.nu];
          ywt = [1,this.MPC.nx];
          mvwt = [1,this.MPC.nu];
          dmwwt = [1,this.MPC.nu];
          tInfo = [1, this.MPC.nu];
          kill = [1,1];
          
      end 
      
      function [mvmin,mvmax,ywt,mvwt,dmwwt,tInfo,kill] = isOutputFixedSizeImpl(this)
          mvmin = true;
          mvmax = true;
          ywt = true;
          mvwt = true;
          dmwwt = true;
          tInfo = true;
          kill = true;
          
      end
      
      function [mvmin,mvmax,ywt,mvwt,dmwwt,tInfo,kill] = getOutputDataTypeImpl(this)
          mvmin = "double";
          mvmax = "double";
          ywt = "double";
          mvwt = "double";
          dmwwt = "double";
          tInfo = "logical";
          kill = "logical";

      end
      
     function [mvmin,mvmax,ywt,mvwt,dmwwt,tInfo,kill] = isOutputComplexImpl(this)
         mvmin = false;
         mvmax = false;
         ywt = false;
         mvwt = false;
         dmwwt = false;
         tInfo = false;
         kill = false;
         
     end
     function [sz,dt,cp] = getDiscreteStateSpecificationImpl(this,name)
         if strcmp(name,'init')
              sz = [1 1];
              dt = "double";
              cp = false;
         elseif strcmp(name,'currentFaultCount')
              sz = [1 this.MPC.nu];
              dt = "double";
              cp = false;
         elseif strcmp(name,'isThrusterFault')
              sz = [1 this.MPC.nu];
              dt = "logical";
              cp = false;
         elseif strcmp(name,'rosOV')
              sz = [1 this.MPC.nx];
              dt = "double";
              cp = false;
         elseif strcmp(name,'rosMV')
              sz = [1 this.MPC.nu];
              dt = "double";
              cp = false;
         elseif strcmp(name,'rosMVR')
              sz = [1 this.MPC.nu];
              dt = "double";
              cp = false;
         end
     end 
     
     function obj = slexBusesMATLABSystemMathOpSysObj(varargin)
      % Support name-value pair arguments
      setProperties(obj,nargin,varargin{:});
     end    
    function validateInputsImpl(~, newRosGains, rosGains,mode,newReadCurrent,readCurrent, estimatedCurrent)
       if  ~isstruct(rosGains)
              error(message('simdemos:MLSysBlockMsg:BusInput'));
       end
       
    end    
    end
end
