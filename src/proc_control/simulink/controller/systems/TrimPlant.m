classdef TrimPlant < matlab.System
    % Linéarise le modele pour le controleurs
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties(Nontunable)
    MPC;
    simulation
    end

    properties(DiscreteState)
        qkm; % mesured Quaternion of last step
        qkt; % trajectory Quaternion of last step
        xl;
    end

    % Pre-computed constants
    properties(Access = private)
        J; % Jacobian function 
        f; % state function
        qUtils; % quatUtil class
        
    end

    methods(Access = protected)

        function resetImpl(this)
            % Initialize / reset discrete-state properties
            this.qkm = this.MPC.Xi(4:7).';
            this.qkt = this.MPC.Xi(4:7).';
            this.J = str2func(this.MPC.JacobianFnc);
            this.f = str2func(this.MPC.StateFnc);
            this.xl = this.MPC.Xi.';
        end

        function setupImpl(this)
            % Perform one-time calculations, such as computing constants
            this.qUtils = quatUtilities();
        end

        function [A, B, C, D, U, Y, X, DX, ref, Z] = stepImpl(this, u, y, ref)
            
            % Regarder la discontinuité entre le qk et qk-1 pour la mesure
            y(4:7) = this.qUtils.checkQuatFlip(y(4:7).', this.qkm).';
            this.qkm = y(4:7).';

            % Regarder la discontinuité entre le qk et qk + p pour la trajectoire
            ref = this.checkTrajectory(ref);

            % Calculer le residue de mesure
            Z = y - this.xl.';

            % Linéariser le systeme.
            [A, B, C, D, U, Y, X, DX] = this.trimPlantQuat(u,y);


        end
        
        function [A, B, C, D, U, Y, X, DX] = trimPlantQuat(this, u, y)

            % Lineariser le système
            [Ac, Bc, C, D] = this.J(y,u);
    
            % Discrétiser le système.
            A = expm(Ac*this.MPC.Ts); % Fossen Eq B.10/B.9 page 662
    
            BT = Ac(8:13,8:13)\(A(8:13,8:13)-eye(6))*Bc(8:13,1:8); % Fossen Eq B.11 p 662
            B = [zeros(7,8); BT];
    
            % Calculer F(x(k),u(k))
            xk = y;
    
            % Intégration trapezoidale
            x_dot_kk = zeros(13,1);
        
    
            for i = 1 : this.MPC.dts 
              x_dot_k = this.f(xk,u);
        
              xk = xk + ((x_dot_k + x_dot_kk)*(this.MPC.Ts/this.MPC.dts ))/2;
        
              x_dot_kk = x_dot_k;
        
               % correct Quaternion
               xk(4:7)=this.qUtils.quatNorm(xk(4:7));
               
            end
            
            % Nominal conditions for discrete-time plant
            U = u.';
            Y = y.';%(Cc*x + Dc*u).';
            X = y.';
            DX = (xk-y).' ;
            
            % save prediction for next step
            this.xl =xk.';
        end

        function traj = checkTrajectory(this, traj)

            % check fist ref 
            traj(1,4:7) = this.qUtils.checkQuatFlip(traj(1,4:7), this.qkt);

            for i = 2 : this.MPC.p
                traj(i,4:7) = this.qUtils.checkQuatFlip(traj(i,4:7), traj(i-1,4:7));
            end

            % save quat for next step
            this.qkt = traj(1,4:7);

        end
      
         %% Definire outputs       
        function [A, B, C, D, U, Y, X, DX, ref Z] = getOutputSizeImpl(this)
            A = [this.MPC.nx,this.MPC.nx];
            B = [this.MPC.nx,this.MPC.nu];
            C = [this.MPC.nx,this.MPC.nx];
            D = [this.MPC.nx,this.MPC.nu];
            U = [1,this.MPC.nu];
            Y = [1,this.MPC.nx];
            X = [1,this.MPC.nx];
            DX = [1,this.MPC.nx];
            ref = [this.MPC.p, this.MPC.nx];
            Z = [this.MPC.nx,1];

        end 
      
        function [A, B, C, D, U, Y, X, DX, ref, Z] = isOutputFixedSizeImpl(this)
            A = true;
            B = true;
            C = true;
            D = true;
            U = true;
            Y = true;
            X = true;
            DX = true;   
            ref = true  
            Z = true; 
        end
      
        function [A, B, C, D, U, Y, X, DX, ref, Z] = getOutputDataTypeImpl(this)
            A = "double";
            B = "double";
            C = "double";
            D = "double";
            U = "double";
            Y = "double";
            X = "double";
            DX = "double";
            ref = "double";
            Z = "double";
        end
      
        function [A, B, C, D, U, Y, X, DX, ref, Z] = isOutputComplexImpl(this)
            A = false;
            B = false;
            C = false;
            D = false;
            U = false;
            Y = false;
            X = false;
            DX = false;  
            ref = false;
            Z = false;
        end
        function [sz,dt,cp] = getDiscreteStateSpecificationImpl(this,name)
            if strcmp(name,'qkm')
                sz = [1 4];
                dt = "double";
                cp = false;
            elseif strcmp(name,'qkt')
                sz = [1 4];
                dt = "double";
                cp = false;
            elseif strcmp(name,'xl')
                sz = [1 this.MPC.nx];
                dt = "double";
                cp = false;
            end
        end 
    end
end
