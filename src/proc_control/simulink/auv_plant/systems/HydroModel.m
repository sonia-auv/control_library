classdef HydroModel < matlab.System
    % Simules la valeurs retourner via les hydrophones


    % Public, tunable properties
    properties (Nontunable)
    Physics;
    pingerStartPosition;

    end
    
    properties(DiscreteState)

    end

    % Pre-computed constants
    properties(Access = private)
       pingerPosition = rosmessage('geometry_msgs/Vector3',"DataFormat","struct");; 
    end

    methods(Access = protected)
        function setupImpl(this)
            % Perform one-time calculations, such as computing constants
        end

        function [pingerPosition,HydroMesurements] = stepImpl(this,isNewPosition,pingerPosition,worldPosition,quaternion)
           
            if isNewPosition
                this.updatePignerPosition(pingerPosition);
            end
            p =[this.pingerPosition.X ;
                this.pingerPosition.Y ;
                this.pingerPosition.Z ];

            HydroMesurements = pinger2hydroAngles(worldPosition, quaternion.' ,this.Physics.hydroPose.', p);
            pingerPosition = this.pingerPosition;
        end

        function resetImpl(this)
            % Initialize / reset discrete-state properties
            %this.pingerPosition = this.pingerStartPosition;
            this.pingerPosition = rosmessage('geometry_msgs/Vector3',"DataFormat","struct");
            this.pingerPosition.X = this.pingerStartPosition(1);
            this.pingerPosition.Y = this.pingerStartPosition(2);
            this.pingerPosition.Z = this.pingerStartPosition(3);
        end

        function updatePignerPosition(this,msg )
            this.pingerPosition.X = msg.X;
            this.pingerPosition.Y = msg.Y;
            this.pingerPosition.Z = msg.Z;
        end
    end
end
