classdef ProcControlNode
    %PROCCONTROLNODE Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        node;
    end
    
    methods
        function this = ProcControlNode(nh)
            this.node = nh;
        end
        
        function spinOnce(this)
            disp("Ça marche Alex!!!!");
        end
    end
end

