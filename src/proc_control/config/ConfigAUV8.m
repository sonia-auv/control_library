function [simulink, simulation, physics, thrusters, MPC, mode] = ConfigAUV8()

%% Paramètre simulink
    simulink.sampletime = 1/50;
    simulink.procNav.sampletime = simulink.sampletime;
    simulink.procNav.imuDepth.sampletime = simulink.sampletime;
    simulink.procNav.dvl.sampletime = 1/50;
        
%% Constantes Physiques
   physics.mass = 31; % Kg
   physics.volume = 0.0315; % M^3
   physics.rho = 998;
   physics.g = 9.81;
   physics.dvlCenterDist =0.1435;
   physics.height=.3;

   physics.I = [0.4756, 0.008, 0.004;... Ixx Ixy Ixz 0.5358
               0.008, 1.3735, -0.001;... Iyx Iyy Iyz 1.47
               0.004, -0.001, 1.5371]; % Izx Izy Izz1.68

   % Center of mass      
   physics.RG =[0.001,... x
                0.002,... y
                0.018]; % z

   % Center of boyency
   physics.RB =[0.000,... x
                0.000,... y
               -0.006]; % z
   % Drag
   physics.CDL=[45, 60, 70, 10, 7, 15]/3;

   physics.CDQ=[1.17, 0.82, 0.756, 0.167, 0.1, 0.102];

   physics.AF = [0.12, 0.22, 0.292];

   physics.AddedMass=-[1.4648, 12.6156, 15.7695, 0.1164, 0.3493, 0.3493];

   % distance of depth sensor acording to auv center
   physics.DepthPose = [0 -136 178]*10^-3; % m

   % distance of hydrophones acording to auv center
   physics.hydroPose = [160 0 155]*10^-3; % m
   % Thrusters     x      y      z    yaw  roll pitch
   thrusters.T=[ 0.292, 0.173, 0.082, -45,-90, 0;   % T1
                -0.292, 0.173, 0.082, 45,-90, 0;    % T2
                -0.292,-0.173, 0.082,-45,-90, 0;    % T3
                 0.292,-0.173, 0.082, 45,-90, 0;    % T4
                 0.181, 0.159, 0.082,  0,  0, 0;    % T5
                -0.181, 0.159, 0.082,  0,180, 0;    % T6
                -0.181,-0.159, 0.082,  0,  0, 0;    % T7
                 0.181,-0.159, 0.082,  0,180, 0];   % T8
%% MPC
   % MPC parameters
       MPC.nx = 13; % Number of states
       MPC.ny = 13; % NUmber of outputs
       MPC.nu = 8;  % Number of inputs
       MPC.Ts = 0.1;% Sample time
       MPC.p = 10; % Prediction horizon (in sample)
       MPC.m =  2; % control horizon (in sample)
       MPC.dts =10; % Sample time divider
       MPC.tmax = 40; % maximum thrust in N
       MPC.tmin = -30;% minimum thrust in N
       MPC.thrusters.faultThres = .10; %  % Pourcentage de fautes pour moteurs
       MPC.thrusters.faultSample = 20; %  fault Sample

   % Trajectory Parameters    
       MPC.trajectory.bufferSize = 6000;

   % Target Reached parameters
       MPC.targetReached.linearTol = 0.2; % meters
       MPC.targetReached.angularTol = 0.1; % radians
       MPC.targetReached.timeInTol = 3; % Seconds
       
   % MPC gains
       MPC.gains.defaut.OV =  [30, 30, 30, 45, 45, 45, 45, 0, 0, 0, 0, 0, 0 ];
       MPC.gains.defaut.MV = [ 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2 ];
       MPC.gains.defaut.MVR = [ 0.4, 0.4, 0.4, 0.4, 0.5, 0.5, 0.5, 0.5 ];
       
       MPC.gains.c10.OV = [ 30, 30, 30, 45, 45, 45, 45, 0, 0, 0, 0, 0, 0 ];
       MPC.gains.c10.MV = [ 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2 ];
       MPC.gains.c10.MVR = [ 0.4, 0.4, 0.4, 0.4, 0.5, 0.5, 0.5, 0.5 ];
       
       MPC.gains.c11.OV = MPC.gains.c10.OV;
       MPC.gains.c11.MV = MPC.gains.c10.MV;
       MPC.gains.c11.MVR = MPC.gains.c10.MVR;
       
       MPC.gains.c19.OV = [ 0, 0, 0, 0, 0, 0, 0, 20, 20, 20, 20, 20, 20];
       MPC.gains.c19.MV = [ 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2 ];
       MPC.gains.c19.MVR = [ 0.1, 0.1, 0.1, 0.1, 0.3, 0.3, 0.3, 0.3 ];
       
   %% Définitions des modes
   
   % Mode initial
        mode.init = 0;
   
    % controlleur
        % Quaternion Adaptive MPC
        mode.control.adapQMpcMode = [10 11 19 31]; % Adaptive MPC QUAT
        
        % Open Loop controller
        mode.control.openLoopMode = [20 21];
        
        % Develop
        mode.control.LtvQMpcMode = [30]; % LTV MPC QUAT
        mode.control.rosGains = 31; % Debug RosGains
        
        % Legacy
        mode.control.NlmpcMode = [40]; % Non linear mpc (non compilable)
        mode.control.adapEMpcMode = [41]; % Adaptive MPC EULER
        
        
        
    % Trajectory
        mode.traj.trajMode = [10];
        mode.traj.singleWpts = [11,30,31,40,41];
        mode.traj.SpaceMouseMode = [19 20 21];
        
  %% Paramèetre de Simulation
   % Gazebo
       simulation.gazebo.sampletime = simulink.sampletime;
       simulation.gazebo.reference_frame = uint8('world');
       simulation.gazebo.model_name = uint8('auv8');
    
   % Unity
        simulation.unity.sampletime = simulink.sampletime;
        
   % Sensors
        simulation.sensors.imu.sampletime = 1/50;
        simulation.sensors.imu.sampletime = 1/50;
        simulation.sensors.imu.gyro.noisePower = 0.00000002;
        simulation.sensors.imu.acc.noisePower = 0.000002;
        simulation.sensors.imu.acc.bias = [0,0,-9.59066];

        simulation.sensors.dvl.sampletime = 1/5;
        simulation.sensors.dvl.maxSpeedThres = 10;
        simulation.sensors.dvl.resolution = 0.001;
        simulation.sensors.dvl.noise.power = 0.0000000004;
        
        simulation.sensors.depth.sampletime = 1/50;
        simulation.sensors.depth.resolution = 0.001;
        simulation.sensors.depth.noise.power = 0.0000000004;
        
  % White noise      
        simulation.sensors.noise.sampletime = 1/50;
        simulation.sensors.noise.power =0.0000000004;
    end

