%% Determiner les specification du système
    nx = 13;  % nombre d'états
    ny = 13;  % Nombre de sorties
    nu = 8;   % Nombre d'entré
    Ts = 0.25; % Période d'echantillionage
    p = 4;   % Horizon de prediction
    m =2;    % Horizon de Controle

% Modèle du thruster
    %load('T200_Identification.mat');
    load('T200-Spec-16V.mat');
% Données pour lookup table.
    N = T200Spec16V{:,6};% Force en Newton
    PWM = T200Spec16V{:,1};% PWM
    RPM = T200Spec16V{:,2}; % RPM

%Forces Minmax Thrusters initailes
    tmax=29;
    tmin=-24;
    TMIN ={tmin; tmin; tmin; tmin; tmin; tmin; tmin; tmin};
    TMAX ={tmax; tmax; tmax; tmax; tmax; tmax; tmax; tmax};
    MvTarget={0; 0; 0 ;0 ;-17.5 ;17.5 ;-17.5; 17.5};
%Vitesse Max
    VMIN ={-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2};
    VMAX ={ 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2};

% Poids du controleur initiales
    dOV =[ 70 60 70 50 50 50 50 0 0 0 0 0 0 ];  %OutputVariables 
    dMV =[.2 .2 0.2 .2 0.2 0.2 0.2 0.2]; %ManipulatedVariables
    dMVR=[.1,.1 .1 .1 .3 .3 .3 .3]; %.ManipulatedVariablesRates
    


%% Définitions des modes 
    % controlleur
        mpcMode = [10 19];
        openLoopMode = [20 21];
    
    % Trajectory
        trajMode = [10];
        SpaceMouseMode = [19 20 21];
    
    % Gain pour MPC mode trajectoire 10
        OV10 = [70 60 70 50 50 50 50 0 0 0 0 0 0];
        MV10 = [.2 .2 0.2 .2 0.2 0.2 0.2 0.2];
        MVR10 = [.1,.1 .1 .1 .3 .3 .3 .3];
        Config10=[OV10,MV10,MVR10];
    
    % Gain pour MPC mode spacemouse 19
        OV19 = [ 0 0 0 0 0 0 0 70 60 70  50 50 50];
        MV19 = dMV;
        MVR19 = dMVR;
        Config19=[OV19,MV19,MVR19];
%% Initialiser le comtrolleur MPC non lineaire

% conditions initial
Ui =[0 0 0 0 0 0 0 0];
Xi=[0;0;-.2270;1;0;0;0;0;0;0;0;0;0];

nlobj = nlmpc(nx, ny, nu);
% Definire les fonctions différentielles et les matrices jacobienne
nlobj.Model.StateFcn = "AUVQuatSimFcn";
nlobj.Jacobian.OutputFcn="AUVQuatSimFcn";
nlobj.Jacobian.StateFcn = @AUVQuatJacobianMatrix;



nlobj.Ts = Ts;
nlobj.PredictionHorizon = p;
nlobj.ControlHorizon = m;

nlobj.MV = struct('Min',TMIN,'Max',TMAX);%,'Target',MvTarget);
nlobj.Weights.OutputVariables = dOV;
nlobj.Weights.ManipulatedVariables = dMV;
nlobj.Weights.ManipulatedVariablesRate = dMVR;

% Parametre du solveur
nlobj.Optimization.SolverOptions.ConstraintTolerance = 0.02;
nlobj.Optimization.SolverOptions.OptimalityTolerance = 0.02;
nlobj.Optimization.SolverOptions.FunctionTolerance = 0.02;
nlobj.Optimization.SolverOptions.StepTolerance=0.1;
nlobj.Optimization.SolverOptions.UseParallel=true();
nlobj.Optimization.SolverOptions.Algorithm='sqp';
nlobj.Optimization.RunAsLinearMPC='adaptive';%'timevarying';

%nlobj.Optimization.MVInterpolationOrder=1;
%nlobj.Optimization.SolverOptions.HessianApproximation='finite-difference';
%nlobj.Optimization.UseSuboptimalSolution=true();
%nlobj.Optimization.SolverOptions.SubproblemAlgorithm='direct';
%nlobj.Optimization.SolverOptions.MaxIterations=2;




validateFcns(nlobj,Xi,Ui);



