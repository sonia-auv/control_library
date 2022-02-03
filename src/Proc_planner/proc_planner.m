function proc_planner

   % Definir les message ros
    addposemsg = rosmessage('sonia_common/AddPose',"DataFormat","struct");
    Maddposemsg = rosmessage('sonia_common/MultiAddPose',"DataFormat","struct");
    rMaddposemsg = rosmessage('sonia_common/MultiAddPose',"DataFormat","struct");
    validMsg = rosmessage("std_msgs/Bool","DataFormat","struct");

    % Definir les publisher ros
    pospub = rospublisher('/proc_planner/madpos','sonia_common/MultiAddPose',"DataFormat","struct");
    mapSub = rossubscriber('/proc_planner/send_multi_addpose','sonia_common/MultiAddPose',"DataFormat","struct");
    
    % Definir les Subscrier ROS
    trajpub = rospublisher('/proc_planner/send_trajectory_list','trajectory_msgs/MultiDOFJointTrajectoryPoint',"DataFormat","struct");
    validSub = rospublisher("/proc_planner/is_waypoint_valid","std_msgs/Bool","DataFormat","struct");

    % Definir les parametre de trajectoire
    rosSpin = 1;
    param.ts = 0.1;
    param.amax = 0.15;
    param.vlmax = 0.8;
    param.vamax = deg2rad(45);
  
    killNode = false;
    
    r = rosrate(rosSpin);
    
    
    while ~killNode
    [rMaddposemsg,status] = receive(mapSub,rosSpin/2);
        
        % Si Recois un nouveau message
        if status

            TG = TrajectoryGenerator(rMaddposemsg,param);

            % Envoyer a ros si le mAddpose est valide
            validMsg.Data = logical(TG.status);
            send(validSub, validMsg);

            % Si la trajectoire est valide
            if TG.status
                TG.Compute(trajpub); 
            end
        end
        waitfor(r);
    end
end