classdef RosparamClass < matlab.System
    %ROSPARAM Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        ptree
    end
    
    methods (Access = public)
        function setParameterTree(obj, ptree_ros)
            %ROSPARAM Construct an instance of this class
            %   Detailed explanation goes here
            obj.ptree = ptree_ros;
        end
        
        function [gainRequested, state] = getgainArray(obj, mode, gain, nbGains)
            %METHOD1 Summary of this method goes here
            %   Detailed explanation goes here
            gains = get(obj.ptree, "/proc_control/mpc/gains");
            fields = fieldnames(gains);
            if sum(strcmp(fields, mode)) == 1
                fields = fieldnames(gains.(mode));
                if sum(strcmp(fields, gain)) == 1
                    gainRequested = extractionArray(obj, gains.(mode).(gain), nbGains);
                    state = true;
                else
                    gainRequested = zeros(1, nbGains);
                    state = false;
                end
            else
                gainRequested = zeros(1, nbGains);
                state = false;
            end
        end

        function [valueRequested, state] = getValue(obj, value)
            valueOut = get(obj.ptree, "/proc_control/mpc");
            fields = fieldnames(valueOut);
            if sum(strcmp(fields, value)) == 1
                valueRequested = valueOut.(value);
                state = true;
            else
                valueRequested = 0;
                state = false;
            end
        end
    end
    methods(Access = protected)
        function array = extractionArray(~, str, nbElements)
            array = zeros(1, nbElements);
            for i = 1:nbElements
                [token, remain] = strtok(str, ',');
                array(i) = str2double(token);
                str = remain;
            end
        end
    end
end

