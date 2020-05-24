classdef Thruster < matlab.mixin.Heterogeneous
    % THRUSTER class.
    
    properties
        id;
        force;
        power;
        current;
        rpm;
        pwm;
        efficiency;
    end
    
    methods
        % Construstor
        function obj = Thruster()
           
        end
        
        function this = set.force(this, f)
           this.force = f; 
           this.pwm = this.forceToPwm(this.force);
           this.current = this.forceToCurrent(this.force);
           this.efficiency = this.forceToEfficiency(this.force);
           this.rpm = this.forceToRPM(this.force);
           this.power = this.forceToPower(this.force);
        end
    end
        
    methods(Abstract, Access=public)
        forceToPwm(this, force);
               
        forceToCurrent(this, force);
        
        forceToEfficiency(this, force);
        
        forceToRPM(this, force);
        
        forceToPower(this, force);
    end
end