classdef AuvConfig
    %AUVCONFIG Summary of this class goes here
    %   Detailed explanation goes here

    properties
        auv;
        simulink;
        simulation;
        physics;
        kalman;
        MPC;
        mode;
        B;
        Jauv7; % Jacobian function
        fauv7; % state function
        Jauv8; % Jacobian function
        fauv8; % state function

    end

    methods

        function this = AuvConfig()
            %AUVCONFIG Construct an instance of this class
            %   Detailed explanation goes here

            if coder.target('MATLAB')
                % Definir AUV pour mode interprété
                setenv("AUV","AUV8");
            end

            this.auv = getenv("AUV");

            switch this.auv
                case 'AUV8'
                    [this.simulink, this.simulation, this.physics, this.kalman, this.MPC, this.mode] = ConfigAUV8();
                    this.Jauv8 = str2func(this.MPC.JacobianFnc);
                    this.fauv8 = str2func(this.MPC.StateFnc);
                case 'AUV7'
                    [this.simulink, this.simulation, this.physics, this.kalman, this.MPC, this.mode] = ConfigAUV7();
                    this.Jauv7 = str2func(this.MPC.JacobianFnc);
                    this.fauv7 = str2func(this.MPC.StateFnc);

                otherwise
                    fprintf('!!!WARNING!!!: proc control :AUV variable not defined.  %s is selected. \n', this.auv);
                    [this.simulink, this.simulation, this.physics, this.kalman, this.MPC, this.mode] = ConfigAUV8();
                    this.Jauv8 = str2func(this.MPC.JacobianFnc);
                    this.fauv8 = str2func(this.MPC.StateFnc);

            end

            % Définire la matrice B
            this.B = this.getBMatrix();

            % z transform of the thruster 1st order transfert function.
            % this.physics.thruster.b0 = -exp(-(1/this.physics.thruster.tau) * this.simulink.sampletime);
            % this.physics.thruster.a1 = 1 + this.physics.thruster.b0;
        end

    end
    methods (Access = private)

        function B = getBMatrix(this)

            %% Crée la matrice thrusters
            Tm=zeros(6,size(this.physics.thruster.T,1));
            for i=1:size(this.physics.thruster.T,1)

                qt= eul2quat(deg2rad(this.physics.thruster.T(i,4:6)),'ZYX');% convertir les angle d'euler en quaternion
                Tm(:,i)=ThrusterVector(this.physics.thruster.T(i,1:3),qt);  % Calculer le vecteur thrusters
            end

            B = [zeros(7,8);Tm];
        end
    end


end

