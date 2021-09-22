function [configData, stateData, onlineData, EKF] =  InitMPC()

[~, ~, ~, MPC] = ConfigAUV8();

%Forces Minmax Thrusters initailes
    TMIN ={MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin};
    TMAX ={MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax};

%% Initialiser le comtrolleur MPC
% Conditions initiales
    Xi=[0;0;0.3;1;0;0;0;0;0;0;0;0;0]; % états initials
    Ui= [0;0;0;0;0;0;0;0];  % Commande initials

%liniéarisation du modèle aux conditions initales.
    [Ac,Bc,Cc,Dc] = AUVQuatJacobianMatrix(Xi,Ui);   

% création de l'objet state space.
% Generate discrete-time model
    nx = size(Ac,1);
    nu = size(Bc,2);
    M = expm([[Ac Bc]*MPC.Ts; zeros(nu,nu+nx)]);
    A = M(1:nx,1:nx);
    B = M(1:nx,nx+1:nx+nu);
    C = Cc;
    D = Dc;
    
  %  IntitalPlant=ss(A,B,C,D,MPC.Ts);
    pole(IntitalPlant)

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
    
%% Définir EKF
EKF = extendedKalmanFilter(@KalmanStateFonction,@KalmanMesuredFonction);
EKF.State = Xi;


end

