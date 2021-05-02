classdef OpenLoopController < matlab.System
    % Mode manuel Sanchez
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties
        k = 20; % Gain truster sur directe inverse B
        binv ; % Matrice pseudo inverse thruster
        mass = 31; % Masse
        volume = 32; % Volume
        height = .3; % Hauteur
        I = eye(3); % Tenseur d'inertie
        RG = ones(1,3) % Centre de masse
        RB = ones(1,3) % Centre de flottaison
        AddedMass = ones(1,6); % Masse ajouté
        CDL = ones(1,6); % Constante de drag linéaire
        CDQ = ones(1,6); % Constante de drag quadratique
        AF = ones(1,3); % Aire de surfaces
        g = 9.81 % constante gravitationel
        rho = 998; % Masse volumique du fluide
        
        
    end

    properties(DiscreteState)
       
    end

    % Pre-computed constants
    properties(Access = private)
        Binv
    end

    methods(Access = protected)
        function setupImpl(this)
            % Perform one-time calculations, such as computing constants
            %[M,C,D,Gq] = AUVModelMatrices(in1,in2)
        end

        function mv = stepImpl(this,ref,ref_dot,mo,mode)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            mv = this.computeCommand(ref, ref_dot, mo, mode).';
        end
        
        function mv = computeCommand(this, ref, ref_dot, mo, mode)
           switch mode
               case 20 % Open loop avec modèle physique
                   
                   % Construire le vecteur constantes
                    constValues = [
                         this.mass ...
                         this.volume ...
                         this.height...
                         this.AF ...
                         this.I(1,:) ...
                         this.I(2,:) ...
                         this.I(3,:) ...
                         this.RG ...
                         this.RB ...
                         this.CDL...
                         this.CDQ...
                         this.AddedMass...
                         this.rho ...
                         this.g];
                   % construire le vecteur state avec la imu et spaceNAV
                    state = [0;0;0;mo(4:7);ref.'];
                    
                   % Déterminer les matrices du modèle physique
                   
                   [M,C,D,Gq] = AUVModelMatrices(state,constValues);
                   % CAlculer la comande
                   mv= this.binv*(M*ref_dot.'+(C + D)*ref.'+ Gq);
                   
               case 21% Open loop matrice b invese directe
                   mv = (this.binv*ref.')*this.k;
                   
               otherwise
                   mv = zeros(8,1);
           end
           
        end
       
        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
    end
end
