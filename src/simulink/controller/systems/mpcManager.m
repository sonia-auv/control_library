classdef mpcManager < matlab.System
    % MPC Manager. Gere les modes et les paramètre du controleur.
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties
        
        Config10 = ones(1,29) % Configuration Mode 10
        Config19 = ones(1,29) % Configuration Mode 19
        
        Tmin= -ones(1,8) % Force min moteur
        Tmax= ones(1,8) % Force max moteur
        
        MecConst = ones(1,41) % Constantes Modèle physique
        
        xInit = zeros(1,13);
        mvInit = zeros(1,8);
        eInit = 0;
    end
    properties(DiscreteState)

    end

    % Pre-computed constants
    properties(Access = private)

    end
   
    methods(Access = protected)
        function setupImpl(this,mode)
            % Perform one-time calculations, such as computing constants
            
        end

        function [mvmin,mvmax,ywt,mvwt,dmwwt,mvInit,xInit, eInit] = stepImpl(this,mode)

            mvmin = this.Tmin;
            mvmax = this.Tmax;
            
            [ywt,mvwt,dmwwt] = this.getMpcWeigth(mode);
            
          % Conditions initial
            xInit = this.xInit;
            mvInit = this.mvInit;
            eInit = this.eInit;
            
        end
        %% Fonction qui détermine les gain
        function [OV, MV, MVR]= getMpcWeigth(this,mode)
            switch mode
                case 10
                    OV = this.Config10(1:13);
                    MV = this.Config10(14:21);
                    MVR = this.Config10(22:29);
                    
                case 19
                    OV = this.Config19(1:13);
                    MV = this.Config19(14:21);
                    MVR = this.Config19(22:29);
                    
                otherwise
                    OV = this.Config10(1:13);
                    MV = this.Config10(14:21);
                    MVR = this.Config10(22:29);        
            end
                
        end
      %% Definire outputs       
      function [mvmin,mvmax,ywt,mvwt,dmwwt,mvInit, xInit, eInit] = getOutputSizeImpl(this)
          mvmin = [1,8];
          mvmax = [1,8];
          ywt = [1,13];
          mvwt = [1,8];
          dmwwt = [1,8];
          
          xInit = [1,13];
          mvInit = [1,8];
          eInit = 1;
      end 
      
      function [mvmin,mvmax,ywt,mvwt,dmwwt,mvInit,xInit, eInit] = isOutputFixedSizeImpl(this)
          mvmin = true;
          mvmax = true;
          ywt = true;
          mvwt = true;
          dmwwt = true;
          
          xInit = true;
          mvInit = true;
          eInit = true;
      end
      
      function [mvmin,mvmax,ywt,mvwt,dmwwt,mvInit,xInit, eInit] = getOutputDataTypeImpl(this)
          mvmin = "double";
          mvmax = "double";
          ywt = "double";
          mvwt = "double";
          dmwwt = "double";
          
          xInit = "double";
          mvInit = "double";
          eInit = "double";
      end
      
     function [mvmin,mvmax,ywt,mvwt,dmwwt,mvInit,xInit, eInit] = isOutputComplexImpl(this)
         mvmin = false;
         mvmax = false;
         ywt = false;
         mvwt = false;
         dmwwt =false;
         
         xInit = false;
         mvInit = false;
         eInit = false;
     end
     
      
        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
    end
end
