classdef pignerEstimator < matlab.System
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties(Nontunable)

        physics
    end

    properties(DiscreteState)
        p;
        pk
        q;
        qk;
        h;
        hk;
        start;
        rho;
        pp;

    end

    % Pre-computed constants
    properties(Access = private)

    end

    methods(Access = protected)
        function setupImpl(this)
            % Perform one-time calculations, such as computing constants
        end

        function [pp, rho] = stepImpl(this, worldPosition, quaternion, isNewHydro, hydro)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            

            if isNewHydro
                this.p = worldPosition;
                this.q = quaternion.';
                this.h = [hydro.Heading, hydro.Elevation];
                
                if ~this.start
                    this.start = true;
                else
                    % Estimer Rho
                    this.rho = abs(rhoEstimator(this.p, this.q, this.h, this.pk, this.qk, this.hk ,this.physics.hydroPose.'));
                    
                    % Calculer la position du pigner
                    this.pp = hydroAngles2pinger(this.p, this.q, this.physics.hydroPose.', this.h, this.rho);

                end
                % permuter
                this.pk = this.p;
                this.qk = this.q;
                this.hk = this.h;
            end

            pp = this.pp;
            rho = this.rho;
        end

        function resetImpl(this)
            % Initialize / reset discrete-state properties
            this.p = zeros(3,1);
            this.pk = this.p;
            this.q = [1 0 0 0];
            this.qk = this.q;
            this.h = zeros(1,2);
            this.hk = this.h;
            this.start = false;
            this.rho = 0;
            this.pp = zeros(3,1);
        end
          %% Definire outputs       
       function [pp, rho] = getOutputSizeImpl(this)

            pp = [3,1];
            rho = [1,1];
        end 
      
        function [pp, rho] = isOutputFixedSizeImpl(this)

            pp = true;
            rho = true;      
        end
      
        function [pp, rho] = getOutputDataTypeImpl(this)

            pp = "double";
            rho = "double";  
        end
      
        function [pp, rho] = isOutputComplexImpl(this)

            pp = false;
            rho = false;
        end
     function [sz,dt,cp] = getDiscreteStateSpecificationImpl(this,name)

         if strcmp(name,'p')
              sz = [3 1];
              dt = "double";
              cp = false;
         elseif strcmp(name,'pk')
              sz = [3 1];
              dt = "double";
              cp = false;
         elseif strcmp(name,'q')
              sz = [1 4];
              dt = "double";
              cp = false;
         elseif strcmp(name,'qk')
              sz = [1 4];
              dt = "double";
              cp = false;
         elseif strcmp(name,'h')
              sz = [1 2];
              dt = "double";
              cp = false;
         elseif strcmp(name,'hk')
              sz = [1 2];
              dt = "double";
              cp = false;
         elseif strcmp(name,'start')
              sz = [1 1];
              dt = "logical";
              cp = false;
         elseif strcmp(name,'pp')
              sz = [3 1];
              dt = "double";
              cp = false;
         elseif strcmp(name,'rho')
              sz = [1 1];
              dt = "double";
              cp = false;
         end
     end 
    end
end
