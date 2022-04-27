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
        lastQuat; % Quaternion of last step
        xl;
    end

    % Pre-computed constants
    properties(Access = private)
        J; % Jacobian function 
        f; % state function
        
    end

    methods(Access = protected)

        function resetImpl(this)
            % Initialize / reset discrete-state properties
            this.lastQuat = this.MPC.Xi(4:7).';
            this.J = str2func(this.MPC.JacobianFnc);
            this.f = str2func(this.MPC.StateFnc);
            this.xl = this.MPC.Xi;
        end

        function setupImpl(this)
            % Perform one-time calculations, such as computing constants
        end

        function [A, B, C, D, U, Y, X, DX, Z] = stepImpl(this, u, y)
            
            % Regarder la discontinuité entre le qk et qk-1
            y = this.checkQuatFlip(y);

            Z = y - this.xl;

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
               d = norm(xk(4:7));
               xk(4:7) = xk(4:7)/d;
            end
            
            % Nominal conditions for discrete-time plant
            U = u.';
            Y = y.';%(Cc*x + Dc*u).';
            X = y.';
            DX = (xk-y).' ;
            
            % save prediction for next step
            this.xl =xk;
        end

        function x = checkQuatFlip(this, x)

            % Regarder la discontinuité entre le qk et qk-1
            if  dot(this.lastQuat,x(4:7).') < 0
                x(4:7) = -x(4:7);

            end
            this.lastQuat = x(4:7).';
        end

         %% Definire outputs       
        function [A, B, C, D, U, Y, X, DX, Z] = getOutputSizeImpl(this)
            A = [this.MPC.nx,this.MPC.nx];
            B = [this.MPC.nx,this.MPC.nu];
            C = [this.MPC.nx,this.MPC.nx];
            D = [this.MPC.nx,this.MPC.nu];
            U = [1,this.MPC.nu];
            Y = [1,this.MPC.nx];
            X = [1,this.MPC.nx];
            DX = [1,this.MPC.nx];
            Z = [this.MPC.nx,1];

        end 
      
        function [A, B, C, D, U, Y, X, DX, Z] = isOutputFixedSizeImpl(this)
            A = true;
            B = true;
            C = true;
            D = true;
            U = true;
            Y = true;
            X = true;
            DX = true;     
            Z = true; 
        end
      
        function [A, B, C, D, U, Y, X, DX, Z] = getOutputDataTypeImpl(this)
            A = "double";
            B = "double";
            C = "double";
            D = "double";
            U = "double";
            Y = "double";
            X = "double";
            DX = "double";
            Z = "double";
        end
      
        function [A, B, C, D, U, Y, X, DX, Z] = isOutputComplexImpl(this)
            A = false;
            B = false;
            C = false;
            D = false;
            U = false;
            Y = false;
            X = false;
            DX = false;  
            Z = false;
        end
        function [sz,dt,cp] = getDiscreteStateSpecificationImpl(this,name)
            if strcmp(name,'lastQuat')
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
