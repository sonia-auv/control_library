classdef RosparamClass < handle
   %

    properties
        ptree
    end

    methods (Access = public)
        function this = RosparamClass(ptree_ros)
            %ROSPARAM Construct an instance of this class
            %   Detailed explanation goes here
            this.ptree = ptree_ros;
        end

        %% get rosparam number
        function valueRequested = getValue(this, value, actualValue)
            valueRequested = zeros(1,1);
            if has(this.ptree, value)
                val = get(this.ptree, value);
                valueRequested(1,1) = val(1,1);
                fprintf("%s : %f \n", value, val);
            else
                valueRequested(1,1) = double(actualValue(1,1));

            end
        end
        %% Get float32 array
        function gainRequested = getArray(this, gain, nbGains, actualGain)
            % rosparam array not supported for codegen. use string instead
            gainRequested =zeros(1,nbGains);

            if has(this.ptree, gain)

                if coder.target('MATLAB')
                    [gains, status] = get(this.ptree, gain);
                else
                    [gains, status] = get(this.ptree,gain,"DataType",'char');
                end
                fprintf("rosin : %s \n", gains);
                fprintf("size : %d \n", int8(status));
                gainsArray = this.extractionArray(gains, nbGains);

                if ~isnan(gainsArray)
                    gainRequested(1,1:nbGains) = gainsArray(1,1:nbGains);
                else
                    gainRequested(1,1:nbGains) = actualGain(1,1:nbGains);
                end

            else
                gainRequested(1,1:nbGains) = actualGain(1,1:nbGains);
            end
        end

    end


    methods(Access = protected)

        %% string2array
        function array = extractionArray(this, str, nbElements)
            array = ones(1, nbElements);
            fprintf("input : %s \n", char(str));
            for i = 1:nbElements
                [token, remain] = strtok(str, ',');
                array(i) = real(str2double(token));
                fprintf("gain(%d) : %f \n",int8(i), array(i));
                remainSize = max(size(remain));
                str(1:remainSize-1) = remain(2:end);
            end
        end
    end


end

