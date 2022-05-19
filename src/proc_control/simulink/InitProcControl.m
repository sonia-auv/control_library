% Ce script initialise le simulink proc_control.

%% Setup Environement

% Regarder si le code est compiler ou si on roule en interprété
    if coder.target('MATLAB')

        clear; 

        % Regarder si le node ros matlab est actif
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
            [simulink, simulation, physics, kalman, MPC, mode] = ConfigAUV8();
        case 'AUV7'
            [simulink, simulation, physics, kalman, MPC, mode] = ConfigAUV7();
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
 
    MPC.gains.noDvl.MV = obtainRosparam.getArray("//proc_control/mpc/gains/noDvl/mv", MPC.nu, MPC.gains.noDvl.MV);
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

% Forces Minmax Thrusters initailes
    TMIN ={MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin; MPC.tmin};
    TMAX ={MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax; MPC.tmax};

% z transform of the thruster 1st order transfert function.
 physics.thruster.b0 = -exp(-(1/physics.thruster.tau) * simulink.sampletime);
 physics.thruster.a1 = 1 + physics.thruster.b0;


%Vitesse Max
    XMIN ={ -inf; -inf; 0; -1; -1; -1; -1; -1; -1; -1; -1; -1; -1};
    XMAX ={inf; inf; 5; 1; 1; 1; 1; 1; 1; 1; 1; 1; 1};


%% Crée la matrice thrusters 
    Tm=zeros(6,size(physics.thruster.T,1));   
    
    for i=1:size(physics.thruster.T,1)
        
       qt= eul2quat(deg2rad(physics.thruster.T(i,4:6)),'ZYX');% convertir les angle d'euler en uaternion
       Tm(:,i)=ThrusterVector(physics.thruster.T(i,1:3),qt);  % Calculer le vecteur thrusters     
    end
    
    % crée la matrice inverse 
    binv=pinv(Tm);
    
%% liniéarisation du modèle aux conditions initales.
    J = str2func(MPC.JacobianFnc);
    [Aqc,Bqc,Cqc,Dqc] = J(MPC.Xi,MPC.Ui);       
    
% Discrétiser le système.
    Aq = expm(Aqc*MPC.Ts); % Fossen Eq B.10/B.9 page 662
    
    BT = Aqc(8:13,8:13)\(Aq(8:13,8:13)-eye(6))*Bqc(8:13,1:8); % Fossen Eq B.11 p 662
    Bq = [zeros(7,8); BT];

    Cq = Cqc;
    Dq = Dqc;

    Plant=ss(Aq,Bq,Cq,Dq,MPC.Ts);
    pole(Plant)

% perturbation externe
    [Ap, Bp, Cp, Dp ] = WaveModelMatrix(ones(6,1)*0.5, ones(6,1)*5, ones(6,1)*3);
    
% Dicrétiser les perturbations externes    
    Adp = expm(Ap*MPC.Ts);
    Bdp = Ap\(Adp-eye(12))*Bp;

    waveDist = ss(Adp,Bdp,Cp,Dp);

%% Initialiser le controlleur MPC quaternion

% Création du controleur MPC.
    Qmpcobj =mpc(Plant);
    Qmpcobj.PredictionHorizon =MPC.p;
    Qmpcobj.ControlHorizon=MPC.m;
    
% Conditions Initials
    Qmpcobj.Model.Nominal.X = MPC.Xi;
    Qmpcobj.Model.Nominal.Y= MPC.Xi;
    Qmpcobj.Model.Nominal.U = MPC.Ui;

% Définir les poids et gains
    Qmpcobj.Weights.OutputVariables = MPC.gains.defaut.OV;
    Qmpcobj.Weights.ManipulatedVariables = MPC.gains.defaut.MV;
    Qmpcobj.Weights.ManipulatedVariablesRate = MPC.gains.defaut.MVR;

% Ajout de contraintres au probleme d'optimisation
    Qmpcobj.MV = struct('Min',TMIN,'Max',TMAX);
    Qmpcobj.OutputVariables = struct('Min',XMIN,'Max',XMAX);

% Paramètre du solveur
    Qmpcobj.Optimizer.Algorithm = 'active-set';
    Qmpcobj.Optimizer.ActiveSetOptions.ConstraintTolerance=0.01;

    % To test if major differences
    % setCustomSolver(Qmpcobj,'quadprog');
    
% Paramètre de l'estimateur   
    setEstimator(Qmpcobj,'custom');

% Définir le modele de perturbation.
    setoutdist(Qmpcobj,'model',waveDist);
    
%% Initialiser le comtrolleur MPC non lineaire

% Création du controleur NMPC.
    nlobj = nlmpc(MPC.nx, MPC.ny, MPC.nu);
    nlobj.Ts = MPC.Ts;
    nlobj.PredictionHorizon = MPC.p;
    nlobj.ControlHorizon = MPC.m;

% Definire les fonctions différentielles et les matrices jacobienne
    nlobj.Model.StateFcn = MPC.StateFnc;
    nlobj.Jacobian.OutputFcn= MPC.StateFnc;
    nlobj.Jacobian.StateFcn = MPC.JacobianFnc;

% Définir les poids et gains
    nlobj.Weights.OutputVariables = MPC.gains.defaut.OV;
    nlobj.Weights.ManipulatedVariables = MPC.gains.defaut.MV;
    nlobj.Weights.ManipulatedVariablesRate = MPC.gains.defaut.MVR; 
    
% Ajout de contraintres au probleme d'optimisation
    nlobj.MV = struct('Min',TMIN,'Max',TMAX);
    nlobj.OV = struct('Min',XMIN,'Max',XMAX);
    
% Parametre du solveur
    nlobj.Optimization.SolverOptions.ConstraintTolerance = 0.02;
    nlobj.Optimization.SolverOptions.OptimalityTolerance = 0.02;
    nlobj.Optimization.SolverOptions.FunctionTolerance = 0.02;
    nlobj.Optimization.SolverOptions.StepTolerance=0.1;
    nlobj.Optimization.SolverOptions.UseParallel=true();
    nlobj.Optimization.SolverOptions.Algorithm='sqp'; 
    nlobj.Optimization.RunAsLinearMPC='adaptive'; %'timevarying';
    
    validateFcns(nlobj,MPC.Xi,MPC.Ui);


%% Perturbation Drift
% Initialiser le seed du random
    rng shuffle
% Temp d'échantillionage des perturbation 
    dts=5; 

% Discretiser les parametres des vagues
    waveDiscreteFrequency = round((2*pi) ./ (simulation.wave.frequences .* simulink.sampletime));
    waveDiscretePhase = simulation.wave.phases * (1/simulink.sampletime) / (2*pi);

% Perturbation maximal
    dmax = simulation.drift.nominal .* rand(1,6);

% Perturbation minimal
    dmin = -simulation.drift.nominal .* rand(1,6);
    
% Randomize seeds
    dSeedX=round(rand*10);
    dSeedY=round(rand*10);

%% Calcules des gains pour filtre ordre 2 space mouse.

zeta_l = .99; % dépassement null

Tr = 3; 
wn_l = (0.9257/Tr)*exp(1.6341*zeta_l);

% transforme en z
gain_l = wn_l / (sqrt(1-zeta_l^2));

num_l = exp(-zeta_l*wn_l*MPC.Ts) * sin(wn_l*sqrt(1-zeta_l^2)*MPC.Ts);
Z2_l = 1;
Z1_l = -2*exp(-zeta_l*wn_l*MPC.Ts)*cos(wn_l*MPC.Ts*sqrt(1-zeta_l^2));
Z0_l = exp(-2*zeta_l*wn_l*MPC.Ts);