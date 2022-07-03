classdef String2DoubleArray < matlab.System
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System thisect with discrete state.

    % Public, tunable properties
    properties (Nontunable)
        arraySize;
    end

    properties(DiscreteState)

    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods(Access = protected)
        function setupImpl(this)
            % Perform one-time calculations, such as computing constants
        end

        function array = stepImpl(this,string, length)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            array = extractionArray(this, char(string(1:length)), this.arraySize); 
        end

        function resetImpl(this)
            % Initialize / reset discrete-state properties
        end
    end

    methods(Access = private)
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
