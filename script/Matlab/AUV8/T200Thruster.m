classdef T200Thruster < Thruster
    % T200THRUSTER class.
    
    properties
        newtons;
        amps;
        watts;
        pwms;
        rpms;
        efficiencies;
        id;
    end
    
    methods
        function this = T200Thruster(T,id)
            this.newtons = T{:,6};
            this.amps = T{:,3};
            this.watts = T{:,7};
            this.pwms = T{:,1};
            this.rpms = T{:,2};
            this.efficiencies = T{:,8};
            this.id=id;
        end
    end
    
    methods(Access=public)      
        function pwm = forceToPwm(this, force)
            pwm = round(interp1(this.newtons, this.pwms, force, "linear"));
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

