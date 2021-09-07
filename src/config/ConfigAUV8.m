function [simulation, physics, thrusters, mpc] = ConfigAUV8()
       % Simulation
       simulation.reference_frame = uint8('world');
       simulation.model_name = uint8('auv8');
        
       % Physics
       physics.mass = 31;
       physics.volume = 0.0315;
       physics.rho = 998;
       physics.g = 9.81;
       physics.dvlCenterDist =0.1435;
       physics.height=.3;

       physics.I = [0.4756, 0.008, 0.004;... Ixx Ixy Ixz 0.5358
                   0.008, 1.3735, -0.001;... Iyx Iyy Iyz 1.47
                   0.004, -0.001, 1.5371]; % Izx Izy Izz1.68
             
       physics.RG =[0.001,... x
                    0.002,... y
                    0.018]; % z

       physics.RB =[0.00,... x
                    0.00,... y
                    0.006]; % z
             
       physics.CDL=[45, 60, 70, 10, 7, 15]/4;

       physics.CDQ=[1.17, 0.82, 0.756, 0.167, 0.1, 0.102];

       physics.AF = [0.12, 0.22, 0.292];

       physics.AddedMass=-[1.4648, 12.6156, 15.7695, 0.1164, 0.3493, 0.3493];
        
       % Thrusters     x      y      z    yaw  roll pitch
       thrusters.T=[ 0.292, 0.173, 0.082, -45,-90, 0;   % T1
                    -0.292, 0.173, 0.082, 45,-90, 0;    % T2
                    -0.292,-0.173, 0.082,-45,-90, 0;    % T3
                     0.292,-0.173, 0.082, 45,-90, 0;    % T4
                     0.181, 0.159, 0.082,  0,  0, 0;    % T5
                    -0.181, 0.159, 0.082,  0,180, 0;    % T6
                    -0.181,-0.159, 0.082,  0,  0, 0;    % T7
                     0.181,-0.159, 0.082,  0,180, 0];   % T8
       % MPC
       mpc.nx = 13;
       mpc.ny = 13;
       mpc.nu = 8;
       mpc.Ts = 0.1;
       mpc.p = 10;
       mpc.m =  4;
       mpc.tmax = 50;%29;
       mpc.tmin = -40;%-24;
       mpc.gains.defaut.OV = [ 70, 60, 70, 90, 90, 90, 90, 0, 0, 0, 0, 0, 0 ];
       mpc.gains.defaut.MV = [ 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2 ];
       mpc.gains.defaut.MVR = [ 0.1, 0.1, 0.1, 0.1, 0.3, 0.3, 0.3, 0.3 ];
       mpc.gains.c10.OV = [ 45, 45, 45, 45, 45, 45, 45, 0, 0, 0, 0, 0, 0 ];
       mpc.gains.c10.MV = [ 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2 ];
       mpc.gains.c10.MVR = [ 0.4, 0.4, 0.4, 0.4, 0.6, 0.6, 0.6, 0.6 ];
       %mpc.gains.c19.OV = [ 0, 0, 0, 0, 0, 0, 0, 70, 60, 70, 50, 50, 50];
       mpc.gains.c19.OV = [ 0, 0, 0, 0, 0, 0, 0, 20, 20, 20, 20, 20, 20];
       mpc.gains.c19.MV = [ 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2 ];
       mpc.gains.c19.MVR = [ 0.1, 0.1, 0.1, 0.1, 0.3, 0.3, 0.3, 0.3 ];                    
end

