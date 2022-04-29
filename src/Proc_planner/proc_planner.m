function proc_planner

% Si on roule en simulation
    if coder.target('MATLAB')
        setenv("AUV","AUV8");
        
        if ~ ros.internal.Global.isNodeActive
            % partir le node ros matlab 
            rosinit;
        end
        
        system("rosparam load ./config/proc_planner_config.yaml");
    end

    fprintf('INFO : proc planner : Load config for %s \n', getenv("AUV"));    

%% Definir les variables

% Variables globals
    global newMadpPose newInitialPose TrajIsGenerating;

    newMadpPose = false;
    newInitialPose = false;
    TrajIsGenerating = false; 

% Variables locals
    rosSpin = 1;
    r = rosrate(rosSpin);
    killNode = false; 

% Definir les message ros
    validMsg = rosmessage("std_msgs/Int8","DataFormat","struct");

% Definir les Subscrier ros
    madpSub = rossubscriber('/proc_planner/send_multi_addpose','sonia_common/MultiAddPose',@madCallback,"DataFormat","struct");
    icSub = rossubscriber("proc_planner/initial_pose","geometry_msgs/Pose",@icCallback,"DataFormat","struct");

% Definir les publisher ROS
    trajpub = rospublisher('/proc_planner/send_trajectory_list','trajectory_msgs/MultiDOFJointTrajectoryPoint',"DataFormat","struct","IsLatching",false);
    validPub = rospublisher("/proc_planner/is_waypoints_valid","std_msgs/Int8","DataFormat","struct","IsLatching",false);

%% Definir les parametre de trajectoire  
    param = getRosParam();

%% Ros Spin
    fprintf('INFO : proc planner : Node is started \n');
    fprintf('INFO : proc planner : Wait for poses \n');
    reset(r);

    while ~killNode 
      
        if newMadpPose && newInitialPose

            % Cree l'objet trajectoire
            TG = TrajectoryGenerator(madpSub.LatestMessage,param,icSub.LatestMessage);

            % Envoyer a ros si le mAddpose est valide
            validMsg.Data = int8(TG.status);
            send(validPub, validMsg);

            % Si la trajectoire est valide generer la trajectoire
            if (TG.status == TG.RECIEVED_VALID_WAYPTS)
                TG.Compute(trajpub);            

            end
        
            newMadpPose = false;
            newInitialPose = false;
            TrajIsGenerating = false;
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

    global newMadpPose newInitialPose TrajIsGenerating;

    if (newMadpPose == true && TrajIsGenerating == false)

        newInitialPose =true;
        TrajIsGenerating = true;
        fprintf('INFO : proc planner : Initial poses received \n');
    end
end

%% Get rosparam 
function param = getRosParam()

    param.ts = 0.1;

    param.lowSpeed.amax = 0.05;
    param.lowSpeed.vlmax = 0.2;
    param.lowSpeed.vamax = 0.3;

    param.normalSpeed.amax = 0.10;
    param.normalSpeed.vlmax = 0.5;
    param.normalSpeed.vamax = 0.5;

    param.highSpeed.amax = 0.15;
    param.highSpeed.vlmax = 0.8;
    param.highSpeed.vamax = 0.8;

    obtainRosparam = RosparamClass;
    obtainRosparam.setParameterTree(rosparam);

    param.lowSpeed.amax = obtainRosparam.getValue("/proc_planner/low_speed/maximum_acceleration",param.lowSpeed.amax);
    param.lowSpeed.vlmax = obtainRosparam.getValue("/proc_planner/low_speed/maximum_velocity", param.lowSpeed.vlmax);
    param.lowSpeed.vamax = obtainRosparam.getValue("/proc_planner/low_speed/maximum_angular_rate",param.lowSpeed.vamax);
    
    param.normalSpeed.amax = obtainRosparam.getValue("/proc_planner/normal_speed/maximum_acceleration",param.normalSpeed.amax);
    param.normalSpeed.vlmax = obtainRosparam.getValue("/proc_planner/normal_speed/maximum_velocity", param.normalSpeed.vlmax);
    param.normalSpeed.vamax = obtainRosparam.getValue("/proc_planner/normal_speed/maximum_angular_rate",param.normalSpeed.vamax);

    param.highSpeed.amax = obtainRosparam.getValue("/proc_planner/high_speed/maximum_acceleration",param.highSpeed.amax);
    param.highSpeed.vlmax = obtainRosparam.getValue("/proc_planner/high_speed/maximum_velocity", param.highSpeed.vlmax);
    param.highSpeed.vamax = obtainRosparam.getValue("/proc_planner/high_speed/maximum_angular_rate",param.highSpeed.vamax);

end