classdef T200Thruster < Thruster
    % T200THRUSTER class.
    
    properties
        newtons;
        amps;
        watts;
        pwms;
        rpms;
        efficiencies;
    end
    
    methods
        function this = T200Thruster(n, a, w, p, r, e)
            this.newtons = n;
            this.amps = a;
            this.watts = w;
            this.pwms = p;
            this.rpms = r;
            this.efficiencies = e;
        end
    end
    
    methods(Access=public)      
        function pwm = forceToPwm(this, force)
            pwm = interp1(this.newtons, this.pwms, force, "linear");
        end
                
        function current = forceToCurrent(this, force)
            current = interp1(this.newtons, this.amps, force, "linear");
        end
                
        function eff = forceToEfficiency(this, force)
            eff = interp1(this.newtons, this.efficiencies, force, "linear");
        end
        
        function rpm = forceToRPM(this, force)
            rpm = interp1(this.newtons, this.rpms, force, "linear");
        end
             
        function power = forceToPower(this, force)
            power = interp1(this.newtons, this.watts, force, "linear");
        end
    end
end

