function proc_planner

    % Si on roule en simulation
    if coder.target('MATLAB')
        
        if ~ ros.internal.Global.isNodeActive
            % partir le node ros matlab 
            rosinit;
        end
    end

    % definir le node
    rosSpin = 1;
    r = rosrate(rosSpin);
    killNode = false;
    newMaddPose = false;
    newInitalPose = false;

    % Definir les message ros
    Maddposemsg = rosmessage('sonia_common/MultiAddPose',"DataFormat","struct");
    emptyMAddPoseMsg = rosmessage('sonia_common/MultiAddPose',"DataFormat","struct");
    emptyMAddPoseMsg.Pose = rosmessage('sonia_common/AddPose',"DataFormat","struct");
    validMsg = rosmessage("std_msgs/Bool","DataFormat","struct");
    icMsg = rosmessage('geometry_msgs/Pose',"DataFormat","struct"); % IC topic
    emptyIcMsg = rosmessage('geometry_msgs/Pose',"DataFormat","struct");

    % Definir les Subscrier ros
    mapSub = rossubscriber('/proc_planner/send_multi_addpose','sonia_common/MultiAddPose',"DataFormat","struct");
    icSub = rossubscriber("proc_planner/initial_pose","geometry_msgs/Pose","DataFormat","struct");

    % Definir les publisher ROS
    trajpub = rospublisher('/proc_planner/send_trajectory_list','trajectory_msgs/MultiDOFJointTrajectoryPoint',"DataFormat","struct");
    validPub = rospublisher("/proc_planner/is_waypoints_valid","std_msgs/Bool","DataFormat","struct");
    mapPub = rospublisher('/proc_planner/send_multi_addpose','sonia_common/MultiAddPose',"DataFormat","struct");
    icPub = rospublisher("proc_planner/initial_pose","geometry_msgs/Pose","DataFormat","struct");
    % Definir les parametre de trajectoire
    param.ts = 0.1;
    param.amax = 0.10;
    param.vlmax = 0.5;
    param.vamax = deg2rad(45);

    % Obtenir les rosparams
    obtainRosparam = RosparamClass;
    obtainRosparam.setParameterTree(rosparam);

    param.amax = obtainRosparam.getValue("/proc_planner/maximum_acceleration",param.amax);
    param.vlmax = obtainRosparam.getValue("/proc_planner/maximum_velocity",param.vlmax);
    param.vamax = obtainRosparam.getValue("/proc_planner/maximum_angular_rate",param.vamax);
    
    fprintf('INFO : proc planner : Maximum acceleration is %f m/s^2. \n', param.amax);
    fprintf('INFO : proc planner : Maximum velocity is %f m/s. \n', param.vlmax);
    fprintf('INFO : proc planner : Maximum angular rate is %f rad/s. \n', param.vamax);

    % Initialiser les topics
    Maddposemsg = mapSub.LatestMessage;
    icMsg = icSub.LatestMessage;

    fprintf('INFO : proc planner : Node is started \n');
    fprintf('INFO : proc planner : Wait for poses \n');

    reset(r)

    while ~killNode 
        %[ rMaddposemsg,status] = receive(mapSub,0.2);     
        
        % Si Recois un nouveau message MultiaddPose
        if ~isequaln(Maddposemsg, mapSub.LatestMessage)

            Maddposemsg = mapSub.LatestMessage;
            newMaddPose = true;
            fprintf('INFO : proc planner : Poses received \n');
            fprintf('INFO : proc planner : Wait for initial pose \n');
        end

        % Si Recois un nouveau message initial waypoint
        if (~isequaln(icMsg, icSub.LatestMessage)) && newMaddPose

            icMsg = icSub.LatestMessage;
            newInitalPose = true;
            fprintf('INFO : proc planner : Initial poses received \n');
        end   
            
           % [icMsg,status] = receive(icSub);
        
        if newMaddPose && newInitalPose

            % Cree l'objet trajectoire
            TG = TrajectoryGenerator(Maddposemsg,param,icMsg);

            % Envoyer a ros si le mAddpose est valide
            validMsg.Data = logical(TG.status);
            send(validPub, validMsg);

            % Si la trajectoire est valide
            if TG.status
                TG.Compute(trajpub);            

            end

            Maddposemsg = emptyMAddPoseMsg;
            icMsg = emptyIcMsg;

            send(mapPub,Maddposemsg);
            send(icPub,icMsg);
            
            newMaddPose = false;
            newInitalPose = false;

            fprintf('INFO : proc planner : Wait for poses \n');
        end
 
        waitfor(r);
    end

end

