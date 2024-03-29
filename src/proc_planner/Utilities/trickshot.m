clear;
% Definition des messages
    addposemsg = rosmessage('sonia_common/AddPose',"DataFormat","struct");
    Maddposemsg = rosmessage('sonia_common/MultiAddPose',"DataFormat","struct");
    icMsg = rosmessage('geometry_msgs/Pose',"DataFormat","struct"); % IC topic
    mappub = rospublisher('/proc_planner/send_multi_addpose','sonia_common/MultiAddPose',"DataFormat","struct","IsLatching",false);

    trajpub = rospublisher('/proc_planner/send_trajectory_list','trajectory_msgs/MultiDOFJointTrajectoryPoint',"DataFormat","struct");
    
    iquat= eul2quat(deg2rad([0,0,0]),"ZYX");
    icMsg.Orientation.W = iquat(1);
    icMsg.Orientation.X = iquat(2);
    icMsg.Orientation.Y = iquat(3);
    icMsg.Orientation.Z = iquat(4);

    icMsg.Position.Z = 0;
    icMsg.Position.Y = 0;
    icMsg.Position.X = 0;

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

    param.maxDepth = 5;

% Parametre constante
    x = 5;
    y = 5;
    step = 1;
    speed = 0;
    fine = 0.0;
    Maddposemsg.InterpolationMethod = uint8(0);


    fstep = floor(x/step);
    residut = mod(x,step);
    side = false;
    
    % depth
    addposemsg.Position.X = 0;
    addposemsg.Position.Y = 0;
    addposemsg.Position.Z = 0.6;
    addposemsg.Orientation.X = 0 ;
    addposemsg.Orientation.Y = 0 ;
    addposemsg.Orientation.Z = 0;
    addposemsg.Frame = uint8(1);
    addposemsg.Speed = uint8( speed );
    addposemsg.Fine = 0;
    Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg]; 

    % chandelle
    addposemsg.Position.Y = 0;%0
    addposemsg.Position.X = 0;%(y/2) ;
    addposemsg.Position.Z = 0;
    addposemsg.Orientation.X = 0 ;
    addposemsg.Orientation.Y = 60 ;
    addposemsg.Orientation.Z = 0;
    addposemsg.Frame = uint8(1);
    addposemsg.Speed = uint8( speed );
    addposemsg.Fine = fine;
    Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg]; 

     % barrel
    addposemsg.Position.Y = 0;%0
    addposemsg.Position.X = 0;%(y/2) ;
    addposemsg.Position.Z = 0;
    addposemsg.Orientation.X = 180 ;
    addposemsg.Orientation.Y = 0 ;
    addposemsg.Orientation.Z = 0;
    addposemsg.Frame = uint8(1);
    addposemsg.Speed = uint8( speed );
    addposemsg.Fine = fine;
    Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg]; 
    % barrel
    addposemsg.Position.Y = 0;%0
    addposemsg.Position.X = 0;%(y/2) ;
    addposemsg.Position.Z = 0;
    addposemsg.Orientation.X = 180 ;
    addposemsg.Orientation.Y = 0 ;
    addposemsg.Orientation.Z = 0;
    addposemsg.Frame = uint8(1);
    addposemsg.Speed = uint8( speed );
    addposemsg.Fine = fine;
    Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg]; 

    %roue
    addposemsg.Position.Y = 0;%0
    addposemsg.Position.X = 0;%(y/2) ;
    addposemsg.Position.Z = 0;
    addposemsg.Orientation.X = 0 ;
    addposemsg.Orientation.Y = 0 ;
    addposemsg.Orientation.Z = 180;
    addposemsg.Frame = uint8(1);
    addposemsg.Speed = uint8( speed );
    addposemsg.Fine = fine;
    Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg]; 
    %roue
    addposemsg.Position.Y = 0;%0
    addposemsg.Position.X = 0;%(y/2) ;
    addposemsg.Position.Z = 0;
    addposemsg.Orientation.X = 0 ;
    addposemsg.Orientation.Y = 0 ;
    addposemsg.Orientation.Z = 180;
    addposemsg.Frame = uint8(1);
    addposemsg.Speed = uint8( speed );
    addposemsg.Fine = fine;
    Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg]; 

    %back
    addposemsg.Position.Y = 0;%0
    addposemsg.Position.X = 0;%(y/2) ;
    addposemsg.Position.Z = 0;
    addposemsg.Orientation.X = 0 ;
    addposemsg.Orientation.Y = -60 ;
    addposemsg.Orientation.Z = 0;
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