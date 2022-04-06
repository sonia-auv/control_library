classdef rosCommandManager < matlab.System
    % Ros Command Manager. Gere les commande recu via les message ros.
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties
       initial_mode =0;
       
    end
    
    properties(DiscreteState)
        m_initCond;
        m_mode;
        m_killStatus;
        m_simulation;
        m_reset;
        m_trajClear;
        m_notDryRun;
    
    end

    % Pre-computed constants
    properties(Access = private)
   
    end
   
    methods(Access = protected)
        
        function resetImpl(this)
            % Initialize / reset discrete-state properties
            this.m_initCond = zeros(1,7);
            this.m_mode = this.initial_mode;
            this.m_killStatus = 0;
            this.m_simulation = 0;
            this.m_reset = 0;
            this.m_trajClear = 0;
            this.m_notDryRun = 1;
            
        end
        function setupImpl(this,newSetmode, setMode, NewReset, reset, newKill, kill, newIC, ic,newDryRun,Dryrun, newTrajreset,sensorOn)
            % Perform one-time calculations, such as computing constants
            
        end

        function [initQuat, initPos, simEnable, reset, mode trajClear, notDryRun] = stepImpl...
                (this,newSetMode, setMode, newReset, reset, newKill, kill, newIc, ic,newDryRun,Dryrun,newTrajreset ,sensorOn)
            
          this.getDryRun(newDryRun,Dryrun);
          this.getIC(newIc, ic);
          this.getMode(newSetMode, setMode,newKill, kill, sensorOn);
          this.getReset(newReset, newIc);
          this.getTrajClear(newReset, newSetMode, newIc,newTrajreset);
          
          
          initPos = this.m_initCond(1:3).';
          initQuat = this.m_initCond(4:7).';
          mode = this.m_mode;
          simEnable = this.m_simulation;
          reset = this.m_reset;
          trajClear = this.m_trajClear;
          notDryRun = this.m_notDryRun;
            
        end
        
 
       
        %% Fonction qui détermine le mode
        function getMode(this,newSetMode, setMode,newKill, kill,sensorOn)
           
            this.getKill(newKill, kill); % regarder l'états de la kill
            
            if (newSetMode && ~this.m_killStatus &&  sensorOn)
               this.m_mode = cast(setMode,"double");
           
            end
            
            
            
            if this.m_killStatus || ~this.m_notDryRun
               this.m_mode =0;
            end
        end
        
         %% Fonction qui détermine l'arret d'urgence
        function getKill(this,newKill, kill)
           
            if (newKill)
               this.m_killStatus = cast(~kill,"double");
               
            end
        end
        
         %% Fonction qui détermine la condition initial
        function getIC(this,newIc, ic)
           
            if (newIc)
                this.m_simulation =1; % activer la simulation
                this.m_initCond(1:3) = ic(1:3);
                this.m_initCond(4:7) = this.checkQuaternion(ic(4:7));
            end
        end
        
         %% Fonction qui détermine si on reset
        function getReset(this,newReset, newIc)
           
            if (newReset || newIc)
                this.m_reset = 1; 
            else
                this.m_reset = 0;
            end
        end
       
         %% Fonction qui détermine si on clear la trajectoire
        function getTrajClear(this,newReset, newMode, newIc,newTrajreset)
           
            if (newReset || newIc || newMode ||newTrajreset)
                this.m_trajClear = 1; 
            else
                this.m_trajClear = 0;
            end
        end
        
        %% Fonction qui détermine si on est mode dry_run
        function getDryRun(this,newDryrun,dryrun)
            
            if newDryrun
                
                if dryrun ==1
                    this.m_notDryRun = 0;
                else
                    this.m_notDryRun = 1;
                end
            end
        end
        
        %% Fonction qui vérifie si le quaternion est unitaire
        function q = checkQuaternion(this,u)
            d=norm(u);
            n=u/d;
            if isnan(n)
                q=[1;0;0;0];
            else
                 q = n;
            end
        end
        
      %% Definire outputs       
      function [initQuat, initPos, simEnable, reset, mode, trajClear, sensorOn, notDryRun] = getOutputSizeImpl(this)
          initQuat = [4,1];
          initPos = [3,1];
          simEnable = [1,1];
          reset = [1,1];
          mode = [1,1];
          trajClear = [1,1];
          sensorOn = [1,1];
          notDryRun = [1,1];
    
      end 
      
      function [initQuat, initPos, simEnable, reset, mode, trajClear,sensorOn, notDryRun] = isOutputFixedSizeImpl(this)
          initQuat = true;
          initPos = true;
          simEnable = true;
          reset = true;
          mode = true;
          trajClear = true;
          sensorOn = true;
          notDryRun = true;    
          
      end
      
      function [initQuat, initPos, simEnable, reset, mode, trajClear, sensorOn, notDryRun] = getOutputDataTypeImpl(this)
          initQuat = "double";
          initPos = "double";
          simEnable = "double";
          reset = "double";
          mode = "double";
          trajClear = "double";
          sensorOn = "double";
          notDryRun = "double";
      end
      
     function [initQuat, initPos, simEnable, reset, mode, trajClear, sensorOn] = isOutputComplexImpl(this)
          initQuat = false;
          initPos = false;
          simEnable = false;
          reset = false;
          mode = false;
          trajClear = false;
          sensorOn = false;
          notDryRun = false;
          
     end
     function [sz,dt,cp] = getDiscreteStateSpecificationImpl(this,name)
         if strcmp(name,'m_initCond')
              sz = [1 7];
              dt = "double";
              cp = false;
         elseif strcmp(name,'m_mode')
              sz = [1 1];
              dt = "double";
              cp = false;
         elseif strcmp(name,'m_killStatus')
              sz = [1 1];
              dt = "double";
              cp = false;
         elseif strcmp(name,'m_simulation')
              sz = [1 1];
              dt = "double";
              cp = false;
         elseif strcmp(name,'m_reset')
              sz = [1 1];
              dt = "double";
              cp = false;
         elseif strcmp(name,'m_trajClear')
              sz = [1 1];
              dt = "double";
              cp = false;
         elseif strcmp(name,'m_notDryRun')
              sz = [1 1];
              dt = "double";
              cp = false;
         end
     end 
      
        
    end
end
