% Ce script initialise les controlleurs du sous-marin.

% Si on roule en simulation
    if coder.target('MATLAB')
        
        if ~ ros.internal.Global.isNodeActive
            % partir le node ros matlab 
            rosinit;
        end

        % Definir AUV8
        setenv("AUV","AUV8");
    end

% Obtenir la variable d'environement du sub
    auv = getenv("AUV");

% Parametre et constantes
    switch auv
        case 'AUV8'
            [simulink, simulation, physics, thrusters, MPC, mode] = ConfigAUV8();
        case 'AUV7'
            [simulink, simulation, physics, thrusters, MPC, mode] = ConfigAUV7();
        otherwise
            return;
    end

  fprintf('INFO : proc control : Load model of %s. \n', auv);

%% Load Rosparam

     obtainRosparam = RosparamClass;
     obtainRosparam.setParameterTree(rosparam);
 
    % Load MPC Gain Default
    MPC.gains.defaut.OV = obtainRosparam.getArray("/proc_control/mpc/gains/default/ov", MPC.nx, MPC.gains.defaut.OV);
    MPC.gains.defaut.MV = obtainRosparam.getArray("/proc_control/mpc/gains/default/mv", MPC.nu, MPC.gains.defaut.MV);
    MPC.gains.defaut.MVR = obtainRosparam.getArray("/proc_control/mpc/gains/default/mvr", MPC.nu, MPC.gains.defaut.MVR);
    
    % Load MPC Gain Mode 10
    MPC.gains.c10.OV = obtainRosparam.getArray("/proc_control/mpc/gains/c10/ov", MPC.nx, MPC.gains.c10.OV);
    MPC.gains.c10.MV = obtainRosparam.getArray("/proc_control/mpc/gains/c10/mv", MPC.nu, MPC.gains.c10.MV);
    MPC.gains.c10.MVR = obtainRosparam.getArray("/proc_control/mpc/gains/c10/mvr", MPC.nu, MPC.gains.c10.MVR);

    % Load MPC Gain Mode 11
    MPC.gains.c11.OV = obtainRosparam.getArray("/proc_control/mpc/gains/c11/ov", MPC.nx, MPC.gains.c11.OV);
    MPC.gains.c11.MV = obtainRosparam.getArray("/proc_control/mpc/gains/c11/mv", MPC.nu, MPC.gains.c11.MV);
    MPC.gains.c11.MVR = obtainRosparam.getArray("/proc_control/mpc/gains/c11/mvr", MPC.nu, MPC.gains.c11.MVR);
    
    % Load MPC Gain Mode 19
    MPC.gains.c19.OV = obtainRosparam.getArray("/proc_control/mpc/gains/c19/ov", MPC.nx, MPC.gains.c19.OV);
    MPC.gains.c19.MV = obtainRosparam.getArray("/proc_control/mpc/gains/c19/mv", MPC.nu, MPC.gains.c19.MV);
    MPC.gains.c19.MVR = obtainRosparam.getArray("/proc_control/mpc/gains/c19/mvr", MPC.nu, MPC.gains.c19.MVR);
 
    % Insére les gains dans la liste des gains
    MPC.gainsList = [ 10, MPC.gains.c10.OV, MPC.gains.c10.MV, MPC.gains.c10.MVR;
                      11, MPC.gains.c11.OV, MPC.gains.c11.MV, MPC.gains.c11.MVR;
                      19, MPC.gains.c19.OV, MPC.gains.c19.MV, MPC.gains.c19.MVR];

    % Load Thruster min & max
    MPC.tmax = obtainRosparam.getValue("/proc_control/mpc/tmax", MPC.tmax);
    MPC.tmin = obtainRosparam.getValue("/proc_control/mpc/tmin", MPC.tmin);

    % Param du target reached
    MPC.targetReached.linearTol = obtainRosparam.getValue("/proc_control/target_reached/linear_tolerance", MPC.targetReached.linearTol);
    MPC.targetReached.angularTol = obtainRosparam.getValue("/proc_control/target_reached/angular_tolerance",  MPC.targetReached.angularTol);
    MPC.targetReached.timeInTol = obtainRosparam.getValue("/proc_control/target_reached/time_in_tolerance",  MPC.targetReached.timeInTol);
    
%% Modèle du thruster
    load('T200-Spec-16V.mat');
    
% Données pour lookup table.
    N = T200Spec16V{:,6};% Force en Newton
    A = T200Spec16V{:,3};% curents A
    PWM = T200Spec16V{:,1};% PWM
    RPM = T200Spec16V{:,2}; % RPM

%Forces Minmax Thrusters initailes
    TMIN ={MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin};
    TMAX ={MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax};

%Vitesse Max
    VMIN ={-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2;-2};
    VMAX ={ 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2; 2};

   
        
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

%% Initialiser le comtrolleur MPC EULER
% Conditions initiales
    Xi=[0;0;0.3;0;0;0;0;0;0;0;0;0]; % états initials
    Ui= [0;0;0;0;0;0;0;0];%  % Commande initials

%liniéarisation du modèle aux conditions initales.
    [Aec,Bec,Cec,Dec] = AUVEULJacobianMatrix(Xi,Ui);   

% création de l'objet state space.
% Generate discrete-time model
    nx = size(Aec,1);
    nu = size(Bec,2);
    M = expm([[Aec Bec]*MPC.Ts; zeros(nu,nu+nx)]);
    Ae = M(1:nx,1:nx);
    Be = M(1:nx,nx+1:nx+nu);
    %BT = Ac(7:12,7:12)\(A(7:12,7:12)-eye(6))*Bc(7:12,1:8)
    Ce = Cec;
    De = Dec;

    IntitalPlant=ss(Ae,Be,Ce,De,MPC.Ts);
%IntitalPlant = setmpcsignals(IntitalPlant,'UD',[1:8]);
    pole(IntitalPlant)

% Création du controleur MPC.
    Empcobj =mpc(IntitalPlant);
    Empcobj.PredictionHorizon =MPC.p;
    Empcobj.ControlHorizon=MPC.m;

    Empcobj.Model.Nominal.X =Xi;
    Empcobj.Model.Nominal.Y=Xi;
%Ajout des poids et gains
    Empcobj.Weights.OutputVariables = [ 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 0 ];
    Empcobj.Weights.ManipulatedVariables = [ 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2 ];
    Empcobj.Weights.ManipulatedVariablesRate = [ 0.4, 0.4, 0.4, 0.4, 0.6, 0.6, 0.6, 0.6];
    Empcobj.MV = struct('Min',TMIN,'Max',TMAX);
    % mpcobj.OutputVariables=struct('Min',VMIN,'Max',VMAX);%
    setEstimator(Empcobj,'custom');
    Empcobj.Optimizer.ActiveSetOptions.ConstraintTolerance=0.01;
    %xss=mpcstate(mpcobj);
    %results = review(Qmpcobj);
    %disp(results);
    
%% Initialiser le controlleur MPC quaternion

% Conditions initiales
    Xi=[0;0;0.3;1;0;0;0;0;0;0;0;0;0]; % états initials
    Ui= [0;0;0;0;0;0;0;0];%  % Commande initials

%liniéarisation du modèle aux conditions initales.
    [Aqc,Bqc,Cqc,Dqc] = AUVQuatJacobianMatrix(Xi,Ui);   
    
% création de l'objet state space.
% Generate discrete-time model
    nx = size(Aqc,1);
    nu = size(Bqc,2);
    
    M = expm([[Aqc Bqc]*MPC.Ts; zeros(nu,nu+nx)]);
    Aq = M(1:nx,1:nx);
    Bq = M(1:nx,nx+1:nx+nu);
    Cq = Cqc;
    Dq = Dqc;

    IntitalPlant=ss(Aq,Bq,Cq,Dq,MPC.Ts);
%IntitalPlant = setmpcsignals(IntitalPlant,'UD',[1:8]);
    pole(IntitalPlant)

% Création du controleur MPC.
    Qmpcobj =mpc(IntitalPlant);
    Qmpcobj.PredictionHorizon =MPC.p;
    Qmpcobj.ControlHorizon=MPC.m;

    Qmpcobj.Model.Nominal.X = Xi;
    Qmpcobj.Model.Nominal.Y= Xi;
%Ajout des poids et gains
    Qmpcobj.Weights.OutputVariables = MPC.gains.defaut.OV;
    Qmpcobj.Weights.ManipulatedVariables = MPC.gains.defaut.MV;
    Qmpcobj.Weights.ManipulatedVariablesRate = MPC.gains.defaut.MVR;
    Qmpcobj.MV = struct('Min',TMIN,'Max',TMAX);
    % mpcobj.OutputVariables=struct('Min',VMIN,'Max',VMAX);%
    setEstimator(Qmpcobj,'custom');
    %setCustomSolver(Qmpcobj,'quadprog');
    %Qmpcobj.Optimizer.ActiveSetOptions.ConstraintTolerance=0.01;
    %qxss=mpcstate(Qmpcobj);
    %results = review(Qmpcobj);
%% Initialiser le comtrolleur MPC non lineaire
% 
% % conditions initial
    Ui =[0 0 0 0 0 0 0 0];
    Xi=[0;0;0.3;1;0;0;0;0;0;0;0;0;0];

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