classdef T200Thruster < Thruster
    % T200THRUSTER class.
    
    properties
        force;
        power;
        current;
        rpm;
        inputPwm;
        
        eqNewtonsWatts;
        eqPwmNewtons;
        eqPwmCurrent;
        eqPwmEfficiency;
        eqPwmRpm;
    end
    
    methods
        function this = T200Thruster(eqNewtonsWatts)
            this.eqNewtonsWatts = eqNewtonsWatts;
            %this.eqPwmNewtons = ;
            %this.eqPwmCurrent = ;
            %this.eqPwmEfficiency = ;
            %this.eqPwmRpm = ;
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
end

