disp(EQNW);

t = T200Thruster(EQNW);

disp("Test T200Thruster class...");
disp("40 N to power -> " + t.forceToPower(40) + " W");