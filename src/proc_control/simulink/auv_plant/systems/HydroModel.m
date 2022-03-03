classdef HydroModel < matlab.System
    % Simules la valeurs retourner via les hydrophones


    % Public, tunable properties
    properties (Nontunable)
    Physics;
    simulation;
    pingerStartPosition;

    end
    
    properties(DiscreteState)

    end

    % Pre-computed constants
    properties(Access = private)
       pingerPosition = rosmessage('geometry_msgs/Vector3',"DataFormat","struct");
    end

    methods(Access = protected)
        function setupImpl(this)
            % Perform one-time calculations, such as computing constants
        end

        function [pingerPosition,HydroMesurements] = stepImpl(this,isNewPosition,pingerPosition,worldPosition,quaternion)
           
            if isNewPosition
                this.updatePignerPosition(pingerPosition);
            end
            % Ajout du bruit sur la position du pinger.
            p =[this.pingerPosition.X ;
                this.pingerPosition.Y ;
                this.pingerPosition.Z ] + (rand(3,1)  *this.simulation.hydro.maxDeviation);
            
            % Calculer les angles des hydros.
            HydroMesurements = pinger2hydroAngles(worldPosition, quaternion.' ,this.Physics.hydroPose.', p);
            pingerPosition = this.pingerPosition;
        end

        function resetImpl(this)
            % Initialize / reset discrete-state properties
            %this.pingerPosition = this.pingerStartPosition;
            this.pingerPosition = struct('X',0,'Y',0,'Z',0);
            this.pingerPosition.X = this.pingerStartPosition(1);
            this.pingerPosition.Y = this.pingerStartPosition(2);
            this.pingerPosition.Z = this.pingerStartPosition(3);
        end

        function updatePignerPosition(this,msg )
            this.pingerPosition.X = msg.X;
            this.pingerPosition.Y = msg.Y;
            this.pingerPosition.Z = msg.Z;
        end

      %% Definire outputs       
      function [pingerPosition,HydroMesurements] = getOutputSizeImpl(this)
          pingerPosition = [1,1];
          HydroMesurements = [3,1];
          
      end 
      
      function [pingerPosition,HydroMesurements] = isOutputFixedSizeImpl(this)
          pingerPosition = true;
          HydroMesurements = true;
          
      end
      
      function [pingerPosition,HydroMesurements] = getOutputDataTypeImpl(this)
          pingerPosition = "SL_Bus_proc_control_node_geometry_msgs_Vector3";
          HydroMesurements = "double";

      end
      
     function [pingerPosition,HydroMesurements] = isOutputComplexImpl(this)
         pingerPosition = false;
         HydroMesurements = false;
         
     end
     function [sz,dt,cp] = getDiscreteStateSpecificationImpl(this,name)
         if strcmp(name,'init')
              sz = [1 1];
              dt = "double";
              cp = false;
      
         end
     end 
     
     function this = slexBusesMATLABSystemMathOpSysObj(varargin)
      % Support name-value pair arguments
      setProperties(this,nargin,varargin{:});
     end    
         
    end
end
