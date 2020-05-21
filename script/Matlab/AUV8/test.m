load('T200-Spec-16V.mat');
N=T200Spec16V{:,6};
A=T200Spec16V{:,3};
W=T200Spec16V{:,7};
P=T200Spec16V{:,1};
E=T200Spec16V{:,8};
R=T200Spec16V{:,2};

t1 = T200Thruster(N, A, W, P, R, E);
t2 = T200Thruster(N, A, W, P, R, E);

disp("Test T200Thruster class...");
t1.force = 40;
t2.force = 80;
disp(t1.force);
disp(t2.force);
disp(t1.forceToPwm(40));
disp(t1.forceToCurrent(40));
disp(t1.forceToEfficiency(40));
disp(t1.forceToRPM(40));
disp(t1.forceToPower(40));
