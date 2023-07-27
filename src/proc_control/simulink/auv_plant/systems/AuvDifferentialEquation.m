classdef AuvDifferentialEquation < matlab.System
    % Calcule les équations d'états du sous-marin.
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties (Nontunable)
        simulation;
        MPC;
        useDynamicsConst (1,1) logical = false; % Use dynamic physics constants
    end

    properties(DiscreteState)
        init;
        constValues;
        Bc;
    end

    % Pre-computed constants
    properties(Access = private)
        f; % state function

    end

    methods(Access = protected)
        
        % reset  fonction
        %------------------------------------------------------------------------------
        function resetImpl(this)
            % Initialize / reset discrete-state properties
            this.f = str2func(this.simulation.stateFnc);
            this.init = false;
            this.constValues = zeros(1,38);
            this.Bc = zeros(this.MPC.nx, this.MPC.nu);
        end

        function setupImpl(this)
            % Perform one-time calculations, such as computing constants
        end

        % Step fonction
        %------------------------------------------------------------------------------
        function [Position_dot,Quaternion_dot,BodyVelocity_dot, AngularRates_dot] = stepImpl(this,mecConst, thrust,perturbations, states )
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.

            % check if block need to be init
            this.initBloc(mecConst);

            if ~ this.useDynamicsConst
                Dynamics = this.f(states,perturbations,thrust); % legacy
            else
                % xdot = f(x) +Bu
                Dynamics = AUVQuatPerturbedSimFcn(states,perturbations,this.constValues) + (this.Bc * thrust);
            end

            Position_dot = Dynamics(1:3);
            Quaternion_dot = Dynamics(4:7);
            BodyVelocity_dot= Dynamics(8:10);
            AngularRates_dot = Dynamics(11:13);
        end

        % fonction qui initialise les constante mec
        %------------------------------------------------------------------------------
        function initBloc(this,physics)
            if ~this.init
                 this.constValues = [physics.mass ...
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
                this.generateBmatrix(physics.thrusters,physics.rg);
                this.init = true; 
            end
        end

        % Fonction qui genere la matrice B
        %------------------------------------------------------------------------------
        function generateBmatrix(this, T, rg)

            % Crée la matrice thrusters 
            Tm=zeros(6,this.MPC.nu);   
        
            for i=1:this.MPC.nu
                    
                qt= eul2quat(deg2rad(T(i,4:6)),'ZYX');% convertir les angle d'euler en uaternion
                 Tm(:,i)=ThrusterVector(T(i,1:3),qt,rg);  % Calculer le vecteur thrusters     
            end
            
            % prendre la matrice M
            [M,~,~,~] = AUVModelMatrices(this.MPC.Xi,this.constValues);

            % M inverse * Tm
            this.Bc = [zeros(7,this.MPC.nu) ; M\Tm];
           
        end
      %% Definire outputs
      %------------------------------------------------------------------------------       
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
            elseif strcmp(name,'constValues')
                sz = [1 38];
                dt = "double";
                cp = false;
            elseif strcmp(name,'Bc')
                sz = [this.MPC.nx, this.MPC.nu];
                dt = "double";
                cp = false;
            end
        end 
     
    
    
    end
end
