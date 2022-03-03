classdef TrimPlant < matlab.System
    % Linéarise le modele pour le controleurs
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties(Nontunable)
    MPC;

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

        function [A, B, C, D, U, Y, X, DX] = stepImpl(this, u, x)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            [A, B, C, D, U, Y, X, DX] = this.trimPlantQuat(u,x);

        end
        
        function [A, B, C, D, U, Y, X, DX] = trimPlantQuat(this, u, x)

            % Lineariser le système
            [Ac, Bc, C, D] = AUVQuatJacobianMatrix(x,u);
    
            % Discrétiser le système.
            A = expm(Ac*this.MPC.Ts); % Fossen Eq B.10/B.9 page 662
    
            BT = Ac(8:13,8:13)\(A(8:13,8:13)-eye(6))*Bc(8:13,1:8); % Fossen Eq B.11 p 662
            B = [zeros(7,8); BT];
    
            % Calculer F(x(k),u(k))
            xk = x;
    
            % Intégration trapezoidale
            x_dot_kk = zeros(13,1);
        
    
            for i = 1 : this.MPC.dts 
              x_dot_k = AUVQuatSimFcn(xk,u);
        
              xk = xk + ((x_dot_k + x_dot_kk)*(this.MPC.Ts/this.MPC.dts ))/2;
        
              x_dot_kk = x_dot_k;
        
               % correct Quaternion
               d = norm(xk(4:7));
               xk(4:7) = xk(4:7)/d;
            end
            
            % Nominal conditions for discrete-time plant
            U = u.';
            Y = x.';%(Cc*x + Dc*u).';
            X = x.';
            DX = (xk-x).' ;

        end

       
        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end

         %% Definire outputs       
        function [A, B, C, D, U, Y, X, DX] = getOutputSizeImpl(this)
            A = [this.MPC.nx,this.MPC.nx];
            B = [this.MPC.nx,this.MPC.nu];
            C = [this.MPC.nx,this.MPC.nx];
            D = [this.MPC.nx,this.MPC.nu];
            U = [1,this.MPC.nu];
            Y = [1,this.MPC.nx];
            X = [1,this.MPC.nx];
            DX = [1,this.MPC.nx];

        end 
      
        function [A, B, C, D, U, Y, X, DX] = isOutputFixedSizeImpl(this)
            A = true;
            B = true;
            C = true;
            D = true;
            U = true;
            Y = true;
            X = true;
            DX = true;     
        end
      
        function [A, B, C, D, U, Y, X, DX] = getOutputDataTypeImpl(this)
            A = "double";
            B = "double";
            C = "double";
            D = "double";
            U = "double";
            Y = "double";
            X = "double";
            DX = "double";
        end
      
        function [A, B, C, D, U, Y, X, DX] = isOutputComplexImpl(this)
            A = false;
            B = false;
            C = false;
            D = false;
            U = false;
            Y = false;
            X = false;
            DX = false;         
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
