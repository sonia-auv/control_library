classdef Thruster < matlab.mixin.Heterogeneous
    % THRUSTER class.
    
    properties
        
    end
    
    methods
        % Construstor
        function obj = Thruster()
           
        end
    end
    
    methods(Access=private)
        % Get relation function between data.
        getRelation(this, x, y);
    end
        
    methods(Abstract, Access=public)
        % Function to convert pwm to thrust (Kg f).
        pwmToForce(this, pwm);
               
        % Function to convert pwm (micro s) to current (A).
        pwmToCurrent(this, pwm);
        
        % Function to convert pwm (micro s) to efficiency (g/W).
        pwmToEfficiency(this, pwm);
        
        % Function to convert pwm (micro s) to rpm.
        pwmToRPM(this, pwm);
        
        % Function to convert thrust (Kg f) to power (W).
        forceToPower(this, thrust);
    end
end