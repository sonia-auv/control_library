[simulation, physics, thrusters, MPC] = ConfigAUV8();
% Modèle du thruster
    %load('T200_Identification.mat');
    load('T200-Spec-16V.mat');
% Données pour lookup table.
    N = T200Spec16V{:,6};% Force en Newton
    PWM = T200Spec16V{:,1};% PWM
    RPM = T200Spec16V{:,2}; % RPM

%Forces Minmax Thrusters initailes
    TMIN ={MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin};
    TMAX ={MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax};

%Vitesse Max
    VMIN ={-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2};
    VMAX ={ 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2};

%% Définitions des modes 
    % controlleur
        NlmpcMode = [10 11 19];
        openLoopMode = [20 21];
        adapMpcMode = [31];
    % Trajectory
        trajMode = [10];
        singleWpts = [11,31];
        SpaceMouseMode = [19 20 21];
    
    % Gain pour MPC mode trajectoire 10
        Config10=[MPC.gains.c10.OV, MPC.gains.c10.MV, MPC.gains.c10.MVR];
    
    % Gain pour MPC mode spacemouse 19
        Config19=[MPC.gains.c19.OV, MPC.gains.c19.MV, MPC.gains.c19.MVR];
        
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

zeta_l = .99; % dépassement null

Tr = 3; 
wn_l = (0.9257/Tr)*exp(1.6341*zeta_l);



% transforme en z
gain_l = wn_l/(sqrt(1-zeta_l^2));

num_l = exp(-zeta_l*wn_l*MPC.Ts) * sin(wn_l*sqrt(1-zeta_l^2)*MPC.Ts);
Z2_l = 1;
Z1_l = -2*exp(-zeta_l*wn_l*MPC.Ts)*cos(wn_l*MPC.Ts*sqrt(1-zeta_l^2));
Z0_l = exp(-2*zeta_l*wn_l*MPC.Ts);

%% Initialiser le comtrolleur MPC
% Conditions initiales
Xi=[0;0;0.3;0;0;0;0;0;0;0;0;0];%repmat(0.01,nx,1); % états initials
Ui= [0;0;0;0;0;0;0;0];%repmat(0.0,nu,1);   % Commande initials

%liniéarisation du modèle aux conditions initales.
[Ac,Bc,Cc,Dc] = AUVEULJacobianMatrix(Xi,Ui);   

% création de l'objet state space.
% Generate discrete-time model
nx = size(Ac,1);
nu = size(Bc,2);
M = expm([[Ac Bc]*MPC.Ts; zeros(nu,nu+nx)]);
A = M(1:nx,1:nx);
B = M(1:nx,nx+1:nx+nu);
C = Cc;
D = Dc;

IntitalPlant=ss(A,B,C,D,MPC.Ts);
%IntitalPlant = setmpcsignals(IntitalPlant,'UD',[1:8]);
pole(IntitalPlant)
%pzplot(IntitalPlant)

% Création du controleur MPC.
mpcobj =mpc(IntitalPlant);
mpcobj.PredictionHorizon =MPC.p;
mpcobj.ControlHorizon=MPC.m;

mpcobj.Model.Nominal.X =Xi;
mpcobj.Model.Nominal.Y=Xi;
%Ajout des poids et gains
mpcobj.Weights.OutputVariables = [ 30, 30, 30,45, 45, 45, 0, 0, 0, 0, 0, 0 ];
mpcobj.Weights.ManipulatedVariables = [ 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2 ];
mpcobj.Weights.ManipulatedVariablesRate = [ 0.4, 0.4, 0.4, 0.4, 0.6, 0.6, 0.6, 0.6];
mpcobj.MV = struct('Min',TMIN,'Max',TMAX);
% mpcobj.OutputVariables=struct('Min',VMIN,'Max',VMAX);%
setEstimator(mpcobj,'custom');
mpcobj.Optimizer.ActiveSetOptions.ConstraintTolerance=0.01;
%options = mpcmoveopt;
%xss=mpcstate(mpcobj);
%results = review(mpcobj);
%options.MVTarget = [0 0 0 0 -4 4 -4 4]; 

%% Initialiser le comtrolleur MPC non lineaire
% 
% % conditions initial
Ui =[0 0 0 0 0 0 0 0];
Xi=[0;0;-0.3;1;0;0;0;0;0;0;0;0;0];

nlobj = nlmpc(MPC.nx, MPC.ny, MPC.nu);
% Definire les fonctions différentielles et les matrices jacobienne
nlobj.Model.StateFcn = "AUVQuatSimFcn";
nlobj.Jacobian.OutputFcn="AUVQuatSimFcn";
%nlobj.Optimization.CustomSolverFcn = @LinearNlMpcSolver;
nlobj.Jacobian.StateFcn = @AUVQuatJacobianMatrix;

nlobj.Ts = MPC.Ts;
nlobj.PredictionHorizon = MPC.p;
nlobj.ControlHorizon = MPC.m;

nlobj.MV = struct('Min',TMIN,'Max',TMAX);%,'Target',MvTarget);
nlobj.Weights.OutputVariables = MPC.gains.defaut.OV;
nlobj.Weights.ManipulatedVariables = MPC.gains.defaut.MV;
nlobj.Weights.ManipulatedVariablesRate = MPC.gains.defaut.MVR;
% Parametre du solveur
 nlobj.Optimization.SolverOptions.ConstraintTolerance = 0.02;
 nlobj.Optimization.SolverOptions.OptimalityTolerance = 0.02;
 nlobj.Optimization.SolverOptions.FunctionTolerance = 0.02;
 nlobj.Optimization.SolverOptions.StepTolerance=0.1;
 nlobj.Optimization.SolverOptions.UseParallel=true();
 nlobj.Optimization.SolverOptions.Algorithm='sqp'; 
nlobj.Optimization.RunAsLinearMPC='adaptive';%'timevarying';
%nlobj.Optimization.UseSuboptimalSolution=true();
%nlobj.Optimization.MVInterpolationOrder=1;cell
%nlobj.Optimization.SolverOptions.HessianApproximation='finite-difference';

%nlobj.Optimization.SolverOptions.SubproblemAlgorithm='direct';
%nlobj.Optimization.SolverOptions.MaxIterations=1;


validateFcns(nlobj,Xi,Ui);
% tic;
% mv = nlmpcmove(nlobj,Xi,Ui,Xi.')
% toc;
%test = convertToMPC(nlobj,Xi.',Ui);