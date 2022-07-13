classdef AuvDifferentialEquation < matlab.System
    % Calcule les équations d'états du sous-marin.
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties (Nontunable)
        physics;
        simulation;
        useDynamicsConst (1,1) logical = false; % Use dynamic physics constants
    end

    properties(DiscreteState)
        init;
    end

    % Pre-computed constants
    properties(Access = private)
        f; % state function

    end

    methods(Access = protected)

        function resetImpl(this)
            % Initialize / reset discrete-state properties
            this.f = str2func(this.simulation.stateFnc);
            this.init = false;
        end

        function setupImpl(this)
            % Perform one-time calculations, such as computing constants
        end

        function [Position_dot,Quaternion_dot,BodyVelocity_dot, AngularRates_dot] = stepImpl(this,thrust,perturbations, states, mecConst )
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.

            if ~ this.useDynamicsConst
                Dynamics = this.f(states,perturbations,thrust);
            else
                const = this.getConstVector(mecConst);
                Dynamics = AUVQuatPerturbedSimFcn(states,perturbations,thrust,const);
            end

            Position_dot = Dynamics(1:3);
            Quaternion_dot = Dynamics(4:7);
            BodyVelocity_dot= Dynamics(8:10);
            AngularRates_dot = Dynamics(11:13);
        end

        function constValues = getConstVector(this,physics)
                 constValues = [physics.mass ...
                                physics.volume ...
                                physics.sub_height...
                                physics.I ...
                                physics.rg ...
                                physics.rb ...
                                physics.cdl ...
                                physics.cdq...
                                physics.added_mass...
                                physics.rho ...
                                physics.g]; 
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
                dt = "logical";
                cp = false;
            end
        end 
     
    
    
    end
end
