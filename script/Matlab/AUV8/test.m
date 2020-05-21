clc;
clear;
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
disp("----------------------------------");
t1.force = 40;
t2.force = -32;

disp("----------------------------------");
disp("Thruster 1");
disp("----------------------------------");
disp("Force: " + t1.force + " N");
disp("Pwm: " + t1.pwm + " micro sec");
disp("Power: " + t1.power + " W");
disp("Current:  " + t1.current + " A");
disp("RPM: " + t1.rpm + " rpm");
disp("Efficiency: " + t1.efficiency + " g/W");

disp("----------------------------------");
disp("Thruster 2");
disp("----------------------------------");
disp("Force: " + t2.force + " N");
disp("Pwm: " + t2.pwm + " micro sec");
disp("Power: " + t2.power + " W");
disp("Current:  " + t2.current + " A");
disp("RPM: " + t2.rpm + " rpm");
disp("Efficiency: " + t2.efficiency + " g/W");