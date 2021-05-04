[simulation, physics, thrusters, mpc] = ConfigAUV8();
% Modèle du thruster
    %load('T200_Identification.mat');
    load('T200-Spec-16V.mat');
% Données pour lookup table.
    N = T200Spec16V{:,6};% Force en Newton
    PWM = T200Spec16V{:,1};% PWM
    RPM = T200Spec16V{:,2}; % RPM

%Forces Minmax Thrusters initailes
    TMIN ={mpc.tmin; mpc.tmin; mpc.tmin; mpc.tmin; mpc.tmin; mpc.tmin; mpc.tmin; mpc.tmin};
    TMAX ={mpc.tmax; mpc.tmax; mpc.tmax; mpc.tmax; mpc.tmax; mpc.tmax; mpc.tmax; mpc.tmax};

%Vitesse Max
    VMIN ={-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2};
    VMAX ={ 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2};

%% Définitions des modes 
    % controlleur
        mpcMode = [10 19];
        openLoopMode = [20 21];
    
    % Trajectory
        trajMode = [10];
        SpaceMouseMode = [19 20 21];
    
    % Gain pour MPC mode trajectoire 10
        Config10=[mpc.gains.c10.OV, mpc.gains.c10.MV, mpc.gains.c10.MVR];
    
    % Gain pour MPC mode spacemouse 19
        Config19=[mpc.gains.c19.OV, mpc.gains.c19.MV, mpc.gains.c19.MVR];
        
 %% Définire le vecteur constante mec
    constValues = [
                 physics.mass ...
                 physics.volume ...
                 physics.height...
                 physics.AF ...
                 physics.I(1,:) ...
                 physics.I(2,:) ...
                 physics.I(3,:) ...
                 physics.RG ...
                 physics.RB ...
                 physics.CDL...
                 physics.CDQ...
                 physics.AddedMass...
                 physics.rho ...
                 physics.g];
             
%% Crée la matrice thrusters 
    Tm=zeros(6,size(thrusters.T,1));   
    
    for i=1:size(thrusters.T,1)
        
       qt= eul2quat(deg2rad(thrusters.T(i,4:6)),'ZYX');% convertir les angle d'euler en uaternion
       Tm(:,i)=ThrusterVector(thrusters.T(i,1:3),qt);  % Calculer le vecteur thrusters     
    end
    
    % crée la matrice inverse 
    binv=pinv(Tm);
%% Calcules des gains pour filtre ordre 2 space mouse.

xi_l = 1; % dépassement null

Tr = 5; 
wn_l = (0.9257/Tr)*exp(1.6341*xi_l);

Z2_l = 1;
Z1_l = -2*exp(-xi_l*wn_l*mpc.Ts)*cos(wn_l*mpc.Ts*sqrt(1-xi_l^2));
Z0_l = exp(-2*xi_l*wn_l*mpc.Ts);
%% Initialiser le comtrolleur MPC non lineaire

% conditions initial
Ui =[0 0 0 0 0 0 0 0];
Xi=[0;0;-.2270;1;0;0;0;0;0;0;0;0;0];

nlobj = nlmpc(mpc.nx, mpc.ny, mpc.nu);
% Definire les fonctions différentielles et les matrices jacobienne
nlobj.Model.StateFcn = "AUVQuatSimFcn";
nlobj.Jacobian.OutputFcn="AUVQuatSimFcn";
nlobj.Jacobian.StateFcn = @AUVQuatJacobianMatrix;

nlobj.Ts = mpc.Ts;
nlobj.PredictionHorizon = mpc.p;
nlobj.ControlHorizon = mpc.m;

nlobj.MV = struct('Min',TMIN,'Max',TMAX);%,'Target',MvTarget);
nlobj.Weights.OutputVariables = mpc.gains.defaut.OV;
nlobj.Weights.ManipulatedVariables = mpc.gains.defaut.MV;
nlobj.Weights.ManipulatedVariablesRate = mpc.gains.defaut.MVR;

% Parametre du solveur
nlobj.Optimization.SolverOptions.ConstraintTolerance = 0.02;
nlobj.Optimization.SolverOptions.OptimalityTolerance = 0.02;
nlobj.Optimization.SolverOptions.FunctionTolerance = 0.02;
nlobj.Optimization.SolverOptions.StepTolerance=0.1;
nlobj.Optimization.SolverOptions.UseParallel=true();
nlobj.Optimization.SolverOptions.Algorithm='sqp';
nlobj.Optimization.RunAsLinearMPC='adaptive';%'timevarying';

%nlobj.Optimization.MVInterpolationOrder=1;cell
%nlobj.Optimization.SolverOptions.HessianApproximation='finite-difference';
%nlobj.Optimization.UseSuboptimalSolution=true();
%nlobj.Optimization.SolverOptions.SubproblemAlgorithm='direct';
%nlobj.Optimization.SolverOptions.MaxIterations=2

validateFcns(nlobj,Xi,Ui);
