function proc_planner
    % definir le node
    
    %r = rateControl(rosSpin);

    % Definir les message ros
    addposemsg = rosmessage('sonia_common/AddPose',"DataFormat","struct");
    Maddposemsg = rosmessage('sonia_common/MultiAddPose',"DataFormat","struct");
    rMaddposemsg = rosmessage('sonia_common/MultiAddPose',"DataFormat","struct");
    validMsg = rosmessage("std_msgs/Bool","DataFormat","struct");
    icMsg = rosmessage('geometry_msgs/Pose',"DataFormat","struct"); % IC topic

    % Definir les Subscrier ros
    pospub = rospublisher('/proc_planner/madpos','sonia_common/MultiAddPose',"DataFormat","struct");
    mapSub = rossubscriber('/proc_planner/send_multi_addpose','sonia_common/MultiAddPose',"DataFormat","struct");
    icSub = rossubscriber("proc_planner/initial_pose","geometry_msgs/Pose","DataFormat","struct");

    % Definir les publisher ROS
    trajpub = rospublisher('/proc_planner/send_trajectory_list','trajectory_msgs/MultiDOFJointTrajectoryPoint',"DataFormat","struct");
    validSub = rospublisher("/proc_planner/is_waypoint_valid","std_msgs/Bool","DataFormat","struct");

    % Definir les parametre de trajectoire
    
    param.ts = 0.1;
    param.amax = 0.15;
    param.vlmax = 0.8;
    param.vamax = deg2rad(45);
  
    killNode = false;
    
    fprintf('proc planner : Node is started \n');
    %reset(r)
    while ~killNode

    fprintf('proc planner : Wait for poses \n');
    [rMaddposemsg,status] = receive(mapSub);
    fprintf('proc planner : Poses received \n'); 

    fprintf('proc planner : Wait for initial pose \n');
    [icMsg,status] = receive(icSub);
    fprintf('proc planner : Initial poses received \n');  
        % Si Recois un nouveau message
        if status
            
            TG = TrajectoryGenerator(rMaddposemsg,param,icMsg);

            % Envoyer a ros si le mAddpose est valide
            validMsg.Data = logical(TG.status);
            send(validSub, validMsg);

            % Si la trajectoire est valide
            if TG.status
                TG.Compute(trajpub);
                fprintf('proc planner : Trajectory list is sended \n');
            end
        end
   % waitfor(r);

    end

end