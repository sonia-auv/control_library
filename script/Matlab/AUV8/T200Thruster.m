classdef T200Thruster < Thruster
    %T200THRUSTER class.
    
    properties
        
    end
    
    methods
        function obj = T200Thruster()
            
        end
    end
    
    methods(Access=public)
        % Function to convert pwm to thrust (Kg f).
        function thrust = pwmToThrust(this, pwm)
            thrust = pwm;
        end
        
        % Function to convert pwm (micro s) to current (A).
        function current = pwmToCurrent(this, pwm)
            current = pwm;
        end
        
        % Function to convert pwm (micro s) to efficiency (g/W).
        function efficiency = pwmToEfficiency(this, pwm)
            efficiency = pwm;
        end
        
        % Function to convert pwm (micro s) to rpm.
        function rpm = pwmToRPM(this, pwm)
            rpm = pwm;
        end
        
        % Function to convert thrust (Kg f) to power (W).
        function power = thrustToPower(this, thrust)
            power = thrust;
        end
    end
end

