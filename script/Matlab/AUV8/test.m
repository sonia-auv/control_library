t = T200Thruster();

disp("Test T200Thruster class...");
disp("40 N to power -> " + t.forceToPower(40) + " W");
disp("Pwm 1200 to force -> " + t.pwmToForce(1200) + " N");
disp("Pwm 1200 to current -> " + t.pwmToCurrent(1200) + " A");
disp("Pwm 1200 to efficiency -> " + t.pwmToEfficiency(1200) + " g/W");
disp("Pwm 1200 to RPM -> " + t.pwmToRPM(1200) + " RPM");