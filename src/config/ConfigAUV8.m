classdef ConfigAUV8
    %CONFIGAUV8 class.
    properties
        
        psl             % Power supply limitation
        nbt             % nombre de thrusters
        RG              % Centre de masse
        RB              % Centre de flotaison
        dvlCenterDist   % Distance entre le dvl et le centre geometrique(z)
        I               % Inertie
        mass            % Masse du sous marin
        volume          % Volume du sous marin
        rho             % Densite de l'eau
        g               % Masse du sous marin
        
        CDL             % Coefficient de drag linéaire
        CDQ             % Coefficient de drag Quadratique
        
        height          % hauteur sous marin
        AF              % Aire de la surface
        referenceFrame  % Constante du frame pour Gazebo 
        modelName       % Nom du model Gazebo.
        
        AddedMass       % Masse ajoutée
        ThrusterConfig  % Configuration thrusters
    end
    methods
        function this = ConfigAUV8()
            % Constructor
                             
            this.referenceFrame = uint8('world');
            this.modelName = uint8('auv8');
                    
            this.psl = 0.5;
            this.nbt = 8;
            
            this.RG =[0.001,... x
                     -0.003,... y
                      0.027]; % z
                  
            this.RB =[0.00,... x
                      0.00,... y
                      -0.1]; % z
                  
           this.mass = 33.95;
           this.volume = 0.037;
           
           this.I = [1.5, 0.001, 0.01;... Ixx Ixy Ixz 0.5358
                     0.002, 1.8, 0.005;... Iyx Iyy Iyz 1.47
                     0.01, 0.005,1.45]; % Izx Izy Izz1.68
           this.rho = 998;
           this.g = 9.81;
           
           this.CDL=[45, 60, 70, 10, 7, 15];
           
           this.CDQ=[1.17, 0.82, 0.756, 0.167, 0.1, 0.102];
                
           this.dvlCenterDist =0.1435;
           this.height=.3;
           
           this.AF = [0.12, 0.22, 0.292];
           
           this.AddedMass=[0,0,0,0,0,0];
           
           this.ThrusterConfig=[ 0.292, 0.173, 0.082,-45,-90, 0;    % T1
                                -0.292, 0.173, 0.082, 45,-90, 0;    % T2
                                -0.292,-0.173, 0.082,-45,-90, 0;    % T3
                                 0.292,-0.173, 0.082, 45,-90, 0;    % T4
                                 0.181, 0.159, 0.082,  0,  0, 0;    % T5
                                -0.181, 0.159, 0.082,  0,180, 0;    % T6
                                -0.181,-0.159, 0.082,  0,  0, 0;    % T7
                                 0.181,-0.159, 0.082,  0,180, 0];   % T8
        end
    end
end

