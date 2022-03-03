classdef AuvDifferentialEquation < matlab.System
    % Calcule les équations d'états du sous-marin.
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties (Nontunable)
        mpc;
        physics;
    end

    properties(DiscreteState)

    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods(Access = protected)
        function setupImpl(this)
            % Perform one-time calculations, such as computing constants
        end

        function [Position_dot,Quaternion_dot,BodyVelocity_dot, AngularRates_dot] = stepImpl(this,thrust,perturbations, states )
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            Dynamics = AUVQuatPerturbedSimFcn(states,perturbations,thrust);

            Position_dot = Dynamics(1:3);
            Quaternion_dot = Dynamics(4:7);
            BodyVelocity_dot= Dynamics(8:10);
            AngularRates_dot = Dynamics(11:13);
        end

        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
      %% Definire outputs       
        function [Position_dot,Quaternion_dot,BodyVelocity_dot, AngularRates_dot] = getOutputSizeImpl(this)
            Position_dot = [3,1];
            Quaternion_dot = [4,1];
            BodyVelocity_dot = [3,1];
            AngularRates_dot = [3,1];
        end 
      
        function [Position_dot,Quaternion_dot,BodyVelocity_dot, AngularRates_dot] = isOutputFixedSizeImpl(this)
            Position_dot = true;
            Quaternion_dot = true;
            BodyVelocity_dot = true;
            AngularRates_dot = true;        
        end
      
        function [Position_dot,Quaternion_dot,BodyVelocity_dot, AngularRates_dot] = getOutputDataTypeImpl(this)
            Position_dot = "double";
            Quaternion_dot = "double";
            BodyVelocity_dot = "double";
            AngularRates_dot = "double";
        end
      
        function [Position_dot,Quaternion_dot,BodyVelocity_dot, AngularRates_dot] = isOutputComplexImpl(this)
            Position_dot = false;
            Quaternion_dot = false;
            BodyVelocity_dot = false;
            AngularRates_dot = false;
         
        end
        function [sz,dt,cp] = getDiscreteStateSpecificationImpl(this,name)
            if strcmp(name,'init')
                sz = [1 1];
                dt = "double";
                cp = false;
      
            end
        end 
     
    
    
    end
end
