function proc_planner

% Si on roule en simulation
    if coder.target('MATLAB')
        setenv("AUV","AUV8");
        if ~ ros.internal.Global.isNodeActive
            % partir le node ros matlab 
            rosinit;
        end
    end

    fprintf('INFO : proc planner : Load config for %s \n', getenv("AUV"));    

%% Definir les variables

% Variables globals
    global newMadpPose newInitalPose;

    newMadpPose = false;
    newInitalPose = false;
    %mAddposemsg = rosmessage('sonia_common/MultiAddPose',"DataFormat","struct");
    %icMsg = rosmessage('geometry_msgs/Pose',"DataFormat","struct"); % IC topic

% Variables locals
    rosSpin = 1;
    r = rosrate(rosSpin);
    killNode = false;

    param.ts = 0.1;
    param.amax = 0.10;
    param.vlmax = 0.5;
    param.vamax = deg2rad(45);

% Definir les message ros
    validMsg = rosmessage("std_msgs/Bool","DataFormat","struct");

% Definir les Subscrier ros
    madpSub = rossubscriber('/proc_planner/send_multi_addpose','sonia_common/MultiAddPose',@madCallback,"DataFormat","struct");
    icSub = rossubscriber("proc_planner/initial_pose","geometry_msgs/Pose",@icCallback,"DataFormat","struct");

% Definir les publisher ROS
    trajpub = rospublisher('/proc_planner/send_trajectory_list','trajectory_msgs/MultiDOFJointTrajectoryPoint',"DataFormat","struct");
    validPub = rospublisher("/proc_planner/is_waypoints_valid","std_msgs/Bool","DataFormat","struct");

%% Definir les parametre de trajectoire  

% Obtenir les rosparams
    obtainRosparam = RosparamClass;
    obtainRosparam.setParameterTree(rosparam);

    param.amax = obtainRosparam.getValue("/proc_planner/maximum_acceleration",param.amax);
    param.vlmax = obtainRosparam.getValue("/proc_planner/maximum_velocity",param.vlmax);
    param.vamax = obtainRosparam.getValue("/proc_planner/maximum_angular_rate",param.vamax);
    
    fprintf('INFO : proc planner : Maximum acceleration is %f m/s^2. \n', param.amax);
    fprintf('INFO : proc planner : Maximum velocity is %f m/s. \n', param.vlmax);
    fprintf('INFO : proc planner : Maximum angular rate is %f rad/s. \n', param.vamax);

    fprintf('INFO : proc planner : Node is started \n');
    fprintf('INFO : proc planner : Wait for poses \n');

    reset(r)

%% Ros Spin
    while ~killNode 
      
        if newMadpPose && newInitalPose

            % Cree l'objet trajectoire
            TG = TrajectoryGenerator(madpSub.LatestMessage,param,icSub.LatestMessage);

            % Envoyer a ros si le mAddpose est valide
            validMsg.Data = logical(TG.status);
            send(validPub, validMsg);

            % Si la trajectoire est valide
            if TG.status
                TG.Compute(trajpub);            

            end
        
            newMadpPose = false;
            newInitalPose = false;

            fprintf('INFO : proc planner : Wait for poses \n');
       end
 
        waitfor(r);
    end

end

%% MultiAddPose (mad) callback
function madCallback(src,msg)

    global newMadpPose 

    newMadpPose = true;

    fprintf('INFO : proc planner : Poses received \n');
    fprintf('INFO : proc planner : Wait for initial pose \n');
end

%% Initial condition (IC) callback
function icCallback(src,msg)

    global newMadpPose newInitalPose;

    if (newMadpPose == true)
        newInitalPose =true;
        fprintf('INFO : proc planner : Initial poses received \n');
    end
end