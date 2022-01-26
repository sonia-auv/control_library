classdef RosparamClass < matlab.System
    %ROSPARAM Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        ptree
    end
    
    methods (Access = public)
        function setParameterTree(this, ptree_ros)
            %ROSPARAM Construct an instance of this class
            %   Detailed explanation goes here
            this.ptree = ptree_ros;
        end
        
        function gainRequested = getgainArray(this, mode, gain, nbGains, actualGain)
            %METHOD1 Summary of this method goes here
            %   Detailed explanation goes here
            if sum(contains(this.ptree.AvailableParameters, "/proc_control/mpc/gains")) == 0
                gainRequested = actualGain;
                return;
            end
            gains = get(this.ptree, "/proc_control/mpc/gains");
            fields = fieldnames(gains);
            if sum(strcmp(fields, mode)) == 1
                fields = fieldnames(gains.(mode));
                if sum(strcmp(fields, gain)) == 1
                    gainRequested = extractionArray(this, gains.(mode).(gain), nbGains);
                else
                    gainRequested = actualGain;
                end
            else
                gainRequested = actualGain;
            end
        end

        function valueRequested = getValue(this, value, actualValue)
            if sum(contains(this.ptree.AvailableParameters, "/proc_control/mpc")) == 0
                valueRequested = actualValue;
                return;
            end
            valueOut = get(this.ptree, "/proc_control/mpc");
            fields = fieldnames(valueOut);
            if sum(strcmp(fields, value)) == 1
                valueRequested = valueOut.(value)
            else
                valueRequested = actualValue;
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

