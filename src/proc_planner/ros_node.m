classdef  ros_node < handle

   properties (Access = private)
    % Definir les Subscrier ros   
        madpSub; % multi add pose subscriber
        icSub; % current target sub 
    
    % Definir les publisher ROS
        trajpub;
        validPub;
    
        % ROS Param
        param;
    
        % new msgflag
        TrajIsGenerating = false;
    
    end
    
    methods
        % Constructor
        function this = ros_node()
        % Definir les Subscrier ros
            this.madpSub = rossubscriber('/proc_planner/send_multi_addpose','sonia_common/MultiAddPose',@this.madCallback,"DataFormat","struct");
            this.icSub = rossubscriber("/proc_control/current_target","geometry_msgs/Pose",@this.icCallback,"DataFormat","struct");
    
        % Definir les publisher ROS
            this.trajpub = rospublisher('/proc_planner/send_trajectory_list','trajectory_msgs/MultiDOFJointTrajectoryPoint',"DataFormat","struct","IsLatching",false);
            this.validPub = rospublisher("/proc_planner/is_waypoints_valid","std_msgs/Int8","DataFormat","struct","IsLatching",false);
    
        % Get ros param
            this.param = this.getRosParam();
    
        end
    
        % Ros Spin
        function spin(this,spin)
    
            validMsg = rosmessage("std_msgs/Int8","DataFormat","struct");
            killNode = false; 
    
            reset(spin);
            fprintf('INFO : proc planner : Node is started \n');
            fprintf('INFO : proc planner : Wait for poses \n');
    
            while ~killNode
                
                % Regarder si un nouveau multi-addPose
                if ~this.persistentDataStore('newMadpPose')

                    this.persistentDataStore('newInitialPose', false);
                
                elseif this.TrajIsGenerating
                    this.TrajIsGenerating = false;
    
                elseif this.persistentDataStore('newInitialPose')

                    fprintf('INFO : proc planner : Initial poses received \n');
                    this.TrajIsGenerating = true;
    
                    % Cree l'objet trajectoire
                    TG = TrajectoryGenerator(this.madpSub.LatestMessage,this.param,this.icSub.LatestMessage);
    
                    % Envoyer a ros si le mAddpose est valide
                    validMsg.Data = int8(TG.status);
                    send(this.validPub, validMsg);
    
                    % Si la trajectoire est valide generer la trajectoire
                    if (TG.status == TG.RECIEVED_VALID_WAYPTS)
                        TG.Compute(this.trajpub);            
    
                    end
    
                    this.persistentDataStore('newMadpPose', false);
                    this.persistentDataStore('newInitialPose', false);
    
                end
    
    
                waitfor(spin);
            end
        end
    end
    
    methods (Access = private)
    
        % Get rosparam 
        function param = getRosParam(this)
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

            param.maxDepth = 5.0;
            param.surfaceWarning = 0.3;
    
            obtainRosparam = RosparamClass(rosparam);
            
            param.lowSpeed.amax = obtainRosparam.getValue("/proc_planner/low_speed/maximum_acceleration",param.lowSpeed.amax);
            param.lowSpeed.vlmax = obtainRosparam.getValue("/proc_planner/low_speed/maximum_velocity", param.lowSpeed.vlmax);
            param.lowSpeed.vamax = obtainRosparam.getValue("/proc_planner/low_speed/maximum_angular_rate",param.lowSpeed.vamax);
            
            param.normalSpeed.amax = obtainRosparam.getValue("/proc_planner/normal_speed/maximum_acceleration",param.normalSpeed.amax);
            param.normalSpeed.vlmax = obtainRosparam.getValue("/proc_planner/normal_speed/maximum_velocity", param.normalSpeed.vlmax);
            param.normalSpeed.vamax = obtainRosparam.getValue("/proc_planner/normal_speed/maximum_angular_rate",param.normalSpeed.vamax);
    
            param.highSpeed.amax = obtainRosparam.getValue("/proc_planner/high_speed/maximum_acceleration",param.highSpeed.amax);
            param.highSpeed.vlmax = obtainRosparam.getValue("/proc_planner/high_speed/maximum_velocity", param.highSpeed.vlmax);
            param.highSpeed.vamax = obtainRosparam.getValue("/proc_planner/high_speed/maximum_angular_rate",param.highSpeed.vamax);

            param.maxDepth = obtainRosparam.getValue("/proc_planner/max_depth",param.maxDepth);
            param.surfaceWarning = obtainRosparam.getValue("/proc_planner/surface_warning",param.surfaceWarning);

    
        end
    
    end
    
    %% ROS Call back 
    methods(Static, Access = private)
    
        % MultiAddPose (mad) callback
        function madCallback(src,msg)
    
            ros_node.persistentDataStore('newMadpPose',true);
    
            fprintf('INFO : proc planner : Poses received \n');
            fprintf('INFO : proc planner : Wait for initial pose \n');
        end
    
        % Initial condition (IC) callback
        function icCallback(src,msg)
               
           ros_node.persistentDataStore('newInitialPose',true);
  
        end 
    
        function out = persistentDataStore(variable, value)
    
            persistent newMadpPose newInitialPose;
    
            % initialte variables
            if isempty(newMadpPose)
                newMadpPose = false;
            end
    
            if isempty(newInitialPose)
                newInitialPose = false;
            end
    
            if nargin == 1 % GET
                switch true
    
                    case (strcmpi(variable,'newMadpPose') ==1 )
                        out = newMadpPose;
                        return
    
                    case (strcmpi(variable,'newInitialPose') ==1 )
                        out= newInitialPose;
                        return 
    
                    otherwise
                        out = [];
    
                end
    
            elseif nargin == 2 % SET
    
                switch true
    
                case (strcmpi(variable,'newMadpPose') == 1 )
                    newMadpPose = value;
                    return
    
                case (strcmpi(variable,'newInitialPose') == 1 )
                    newInitialPose = value;
                    return 
                end 
    
            end
        end
    end
end
