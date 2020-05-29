classdef ProcControlNode
    %PROCCONTROLNODE Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        node;
    end
    
    methods
        function this = ProcControlNode()
            this.node = ros.Node('/proc_control_matlab');
        end
        
        function spinOnce(this)
            disp("Hello");
        end
    end
end

