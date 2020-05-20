classdef T200Thruster < Thruster
    % T200THRUSTER class.
    
    properties
        newtons;
        amps;
        watts;
        pwms;
        efficiencies;
        rpms;
        
        eqNewtonsWatts;
        eqPwmNewtons;
        eqPwmCurrent;
        eqPwmEfficiency;
        eqPwmRpm;
    end
    
    methods
        function this = T200Thruster()
            load('T200-Spec-16V.mat');
            this.newtons = T200Spec16V{:,6};
            this.amps = T200Spec16V{:,3};
            this.watts = T200Spec16V{:,7};
            this.pwms = T200Spec16V{:,1};
            this.efficiencies = T200Spec16V{:,8};
            this.rpms = T200Spec16V{:,2};
            
            this.eqNewtonsWatts = this.getRelation(this.newtons, this.watts);
            this.eqPwmNewtons = this.getRelation(this.pwms, this.newtons);
            this.eqPwmCurrent = this.getRelation(this.pwms, this.amps);
            this.eqPwmEfficiency = this.getRelation(this.pwms, this.efficiencies);
            this.eqPwmRpm = this.getRelation(this.pwms, this.rpms);
        end
    end
    
    methods(Access=public)
        % Function to convert pwm (micro s) to force (N).
        function force = pwmToForce(this, pwm)
            force = this.eqPwmNewtons(pwm);
        end
        
        % Function to convert pwm (micro s) to current (A).
        function current = pwmToCurrent(this, pwm)
            current = this.eqPwmCurrent(pwm);
        end
        
        % Function to convert pwm (micro s) to efficiency (g/W).
        function efficiency = pwmToEfficiency(this, pwm)
            efficiency = this.eqPwmEfficiency(pwm);
        end
        
        % Function to convert pwm (micro s) to rpm.
        function rpm = pwmToRPM(this, pwm)
            rpm = this.eqPwmRpm(pwm);
        end
        
        % Function to convert thrust (Kg f) to power (W).
        function power = forceToPower(this, force)
            power = this.eqNewtonsWatts(force);
        end
    end
    
    methods(Access=private)
        % Get relation function between data.
        function f = getRelation(this, x, y)
            % trouve une équoition d'orde 6 pour un nuage de point donnée.
            % Arguments : x, Matrice des composante x.
            %             y, Matrice des composante y.
            options = fitoptions('poly6','Normalize', 'on', 'Robust', 'Bisquare');
            disp(options);
            ff=fit(x,y,'poly6',options);
            disp(ff);
            plot(ff,x,y);
            f = ff;
        end
    end
end

