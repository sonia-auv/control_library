classdef RosparamClass < handle
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

        function gainRequested = getArray(this, gain, nbGains, actualGain)
            if has(this.ptree, gain)
                gains = get(this.ptree, gain);
                gainRequested = extractionArray(this, gains, nbGains);
            else
                gainRequested = actualGain;
            end
        end

        function valueRequested = getValue(this, value, actualValue)

            if has(this.ptree, value)
                valueRequested = get(this.ptree, value);
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

