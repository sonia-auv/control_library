clear;

% Definition des messages
    addposemsg = rosmessage('sonia_common/AddPose',"DataFormat","struct");
    Maddposemsg = rosmessage('sonia_common/MultiAddPose',"DataFormat","struct");
    icMsg = rosmessage('geometry_msgs/Pose',"DataFormat","struct"); % IC topic
    mappub = rospublisher('/proc_planner/send_multi_addpose','sonia_common/MultiAddPose',"DataFormat","struct","IsLatching",false);

    trajpub = rospublisher('/proc_planner/send_trajectory_list','trajectory_msgs/MultiDOFJointTrajectoryPoint',"DataFormat","struct");
    

    %% position initial
    iquat= eul2quat(deg2rad([0,0,0]),"ZYX");
    icMsg.Orientation.W = iquat(1);
    icMsg.Orientation.X = iquat(2);
    icMsg.Orientation.Y = iquat(3);
    icMsg.Orientation.Z = iquat(4);

    icMsg.Position.Z = 0;
    icMsg.Position.Y = 0;
    icMsg.Position.X = 0;

%% Traj param
    param.ts = 0.1;

    param.lowSpeed.amax = 0.05;
    param.lowSpeed.vlmax = 0.2;
    param.lowSpeed.vamax = 0.3;
    
    param.normalSpeed.amax = 0.1;
    param.normalSpeed.vlmax = 0.5;
    param.normalSpeed.vamax = 0.5;
    
    param.highSpeed.amax = 0.15;
    param.highSpeed.vlmax = 0.8;
    param.highSpeed.vamax = 0.8;

% Parametre constante
    point =[1, 0];
    dir = 1
    speed = 0;
    fine =0;
% state

    Maddposemsg.InterpolationMethod = uint8(2);

    
    rho = norm(point)

    p0 =complex(-point(1), -point(2))

    trans = complex(0,-1) % 90 rotation
    

     p1 = p0*trans

     p2 = p1*trans

     p3 =p2*trans

     p4 =p3*trans


   

    addposemsg.Position.X = real(p1) - real(p0);
    addposemsg.Position.Y = imag(p1) - imag(p0);
    addposemsg.Position.Z = 0;
    addposemsg.Orientation.X = 0 ;
    addposemsg.Orientation.Y = 0 ;
    addposemsg.Orientation.Z = -90;
    addposemsg.Frame = uint8(1);
    addposemsg.Speed = uint8( speed );
    addposemsg.Fine = 0;
    Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg]; 

    addposemsg.Position.X = real(p1) - real(p0);
    addposemsg.Position.Y = imag(p1) - imag(p0);
    addposemsg.Position.Z = 0;
    addposemsg.Orientation.X = 0 ;
    addposemsg.Orientation.Y = 0 ;
    addposemsg.Orientation.Z = -90;
    addposemsg.Frame = uint8(1);
    addposemsg.Speed = uint8( speed );
    addposemsg.Fine = fine;
    Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg];         
         
    addposemsg.Position.X = real(p1) - real(p0);
    addposemsg.Position.Y = imag(p1) - imag(p0);
    addposemsg.Position.Z = 0;
    addposemsg.Orientation.X = 0 ;
    addposemsg.Orientation.Y = 0 ;
    addposemsg.Orientation.Z = -90;
    addposemsg.Frame = uint8(1);
    addposemsg.Speed = uint8(speed );
    addposemsg.Fine = fine;
    Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg];  


    addposemsg.Position.X = real(p1) - real(p0);
    addposemsg.Position.Y = imag(p1) - imag(p0);
    addposemsg.Position.Z = 0;
    addposemsg.Orientation.X = 0 ;
    addposemsg.Orientation.Y = 0 ;
    addposemsg.Orientation.Z = -90;
    addposemsg.Frame = uint8(1);
    addposemsg.Speed = uint8( speed );
    addposemsg.Fine = fine;
    Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg];  
        
    
   send(mappub , Maddposemsg);

    for i =1 : max(size(Maddposemsg.Pose))
        fprintf("WPTS # %d :: Position { X: %d Y: %d Z: %d } Orientation { yaw : %d } \n",i, Maddposemsg.Pose(i).Position.X,Maddposemsg.Pose(i).Position.Y,Maddposemsg.Pose(i).Position.Z,Maddposemsg.Pose(i).Orientation.Z)
    end
    TG = TrajectoryGenerator(Maddposemsg,param,icMsg)

    if TG.status == TG.RECIEVED_VALID_WAYPTS
        test= TG.Compute(trajpub);
        send(trajpub,test);
        Traj_viewer(test);
    end