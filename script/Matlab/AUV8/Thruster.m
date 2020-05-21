classdef Thruster < matlab.mixin.Heterogeneous
    % THRUSTER class.
    
    properties
        force;
        power;
        current;
        rpm;
        inputPwm;
    end
    
    methods
        % Construstor
        function obj = Thruster()
           
        end
        
        function this = set.force(this, f)
           this.force = f; 
        end
    end
        
    methods(Abstract, Access=public)
        forceToPwm(this, pwm);
               
        forceToCurrent(this, pwm);
        
        forceToEfficiency(this, pwm);
        
        forceToRPM(this, pwm);
        
        forceToPower(this, thrust);
    end
end