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
        lastMsg;
        lastValues;
    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods(Access = private)
        %% string2array
        function array = extractionArray(this,str, nbElements)
            array = ones(1, nbElements);      

            fprintf("input : %s \n", char(str));
            for i = 1:nbElements
                [token, remain] = strtok(str, ',');
                array(i) = real(str2double(token));
                str = remain(2:end);
                %remainSize = max(size(remain));
                %str(1:remainSize-1) = remain(2:end);
            end
        end

        
    end

    methods(Access = protected)
        function setupImpl(this)
            % Perform one-time calculations, such as computing constants
        end

        function array = stepImpl(this,string, length)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.

            % remove space and add a comma at the end
            cleanStr = [erase(char(string(1:length)),' ') ','];
            l = strlength(cleanStr);
            
            % new msg
            if ~strcmp(char(this.lastMsg(1:l)), char(cleanStr(1:l)))
                str = cleanStr;

                for i = 1 : this.arraySize(1)
                    [token, remain] = strtok(str, ';');
                    this.lastValues(i,:) = extractionArray(this, token, this.arraySize(2));
                    %remainSize = max(size(remain));
                    str = remain(2:end);
                    %str(1:remainSize-2) = remain(2:end-1);
                end

                this.lastMsg(1:l) = cleanStr(1:l);
            end

        

            array = this.lastValues;
        end

        function resetImpl(this)
            % Initialize / reset discrete-state properties
            this.lastMsg = zeros(1,400);
            this.lastValues = zeros(this.arraySize(1), this.arraySize(2));

        end


        %% Definire outputs       
        function [array] = getOutputSizeImpl(this)

            array = [this.arraySize(1), this.arraySize(2)];

        end 
    
        function [array] = isOutputFixedSizeImpl(this)
            array = true;

        end
        
        function [array] = getOutputDataTypeImpl(this)
            array = "double";
  
        end
     
       function [array] = isOutputComplexImpl(this)
            array = false;
  
       end

       function [sz,dt,cp] = getDiscreteStateSpecificationImpl(this,name)
           if strcmp(name,'lastMsg')
                sz = [1, 400];
                dt = "double";
                cp = false;
           elseif strcmp(name,'lastValues')
                sz = [this.arraySize(1), this.arraySize(2)];
                dt = "double";
                cp = false;
           elseif strcmp(name,'row')
                sz = [1,1];
                dt = "double";
                cp = false;
           elseif strcmp(name,'columns')
                sz = [1,1];
                dt = "double";
                cp = false;
           end
       end
    end

end
