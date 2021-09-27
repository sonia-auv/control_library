clear
test= [0.1 11 0.1];
if max(test) > 10
    disp("good")
end


[simulation, physics, thrusters, MPC] = ConfigAUV8();

%Forces Minmax Thrusters initailes
    TMIN ={MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin};
    TMAX ={MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax};

%% Initialiser le comtrolleur MPC
% Conditions initiales
    Xi=[0;0;0.3;1;0;0;0;0;0;0;0;0;0]; % états initials
    Ui= [0;0;0;0;0;0;0;0];  % Commande initials


% Generate discrete-time model
   
   [A, B, C, D] = trimPlant(Xi, Ui, MPC.Ts);
    IntitalPlant=ss(A,B,C,D,MPC.Ts);
   % pole(IntitalPlant)

% Création du controleur MPC.
    mpcobj =mpc(IntitalPlant);
    mpcobj.PredictionHorizon =MPC.p;
    mpcobj.ControlHorizon=2;%MPC.m;

    mpcobj.Model.Nominal.X =Xi;
    mpcobj.Model.Nominal.Y=Xi;

%Ajout des poids et gains
    mpcobj.Weights.OutputVariables = MPC.gains.defaut.OV;
    mpcobj.Weights.ManipulatedVariables = MPC.gains.defaut.MV;
    mpcobj.Weights.ManipulatedVariablesRate = MPC.gains.defaut.MVR;
    mpcobj.MV = struct('Min',TMIN,'Max',TMAX);
% mpcobj.OutputVariables=struct('Min',VMIN,'Max',VMAX);

    setEstimator(mpcobj,'custom');
    mpcobj.Optimizer.ActiveSetOptions.ConstraintTolerance=0.01;
    
% Code gen
    [configData, stateData, onlineData] = getCodeGenerationData(mpcobj); 
%% Initialiser le comtrolleur MPC non lineaire
% 
% % conditions initial
Ui =[0 0 0 0 0 0 0 0];
Xi=[0;0;0.4;1;0;0;0;0;0;0;0;0;0];

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
%  nlobj.Optimization.SolverOptions.ConstraintTolerance = 0.02;
%  nlobj.Optimization.SolverOptions.OptimalityTolerance = 0.02;
%  nlobj.Optimization.SolverOptions.FunctionTolerance = 0.02;
%  nlobj.Optimization.SolverOptions.StepTolerance=0.1;
%  nlobj.Optimization.SolverOptions.UseParallel=true();
%  nlobj.Optimization.SolverOptions.Algorithm='sqp'; 
nlobj.Optimization.RunAsLinearMPC='adaptive';%'timevarying';
%nlobj.Optimization.UseSuboptimalSolution=true();
%nlobj.Optimization.MVInterpolationOrder=1;cell
%nlobj.Optimization.SolverOptions.HessianApproximation='finite-difference';

%nlobj.Optimization.SolverOptions.SubproblemAlgorithm='direct';
nlobj.Optimization.SolverOptions.MaxIterations=1;

[coredata,onlinedata] = getCodeGenerationData(nlobj,Xi,Ui.');

validateFcns(nlobj,Xi,Ui);    
%% Définir EKF
EKF = extendedKalmanFilter(@KalmanStateFonction,@KalmanMesuredFonction);
EKF.State = Xi;



%% Test simulation
%rosinit
r = rosrate(.1);
reset(r)

xk=Xi;
uk=Ui;
ref = [0.01,0,0.4,1,0,0,0,0,0,0,0,0,0];


while(1)
    
    yk = C * correct(EKF,xk);
    lastMV = uk;
    %% process "MVTarget" to get p-by-nmv MV references (unscaled, default to 0)



    onlineData.ref = [0.01,0,0.4,1,0,0,0,0,0,0,0,0,0];
    xk = correct(EKF,xk);
    [mv,onlineData] = QPnlmpcmoveCodeGeneration(coredata,xk,uk.',onlinedata);
% 
%      onlineData.signals.ym = yk;
%      
% % Linéariser le modèle
%     [Ak, Bk, Ck, Dk] = trimPlant(yk,uk,MPC.Ts);
%      
%         configData.A(1:13,1:13)= Ak;
%         configData.B(1:13,1:8) = Bk;
%         configData.B(1:13,1:8)
%      onlineData.signals.ref = [0.01,0,0.4,1,0,0,0,0,0,0,0,0,0];
% 
%      [uk ,stateData] = mpcmoveCodeGeneration(configData,stateData,onlineData);
% 
%      predict(EKF,uk);
% 
%      disp(uk)
%      
%      waitfor(r);
end


function [A, B, C, D] = trimPlant(X, U, Ts)

%liniéarisation du modèle aux conditions initales.
    [Ac,Bc,Cc,Dc] = AUVQuatJacobianMatrix(X,U);   

% Discrétiser le système.
    nx = size(Ac,1);
    nu = size(Bc,2);
    M = expm([[Ac Bc]*Ts; zeros(nu,nu+nx)]);
    
    A = M(1:nx,1:nx);
    B = M(1:nx,nx+1:nx+nu);
    C = Cc;
    D = Dc;
end
