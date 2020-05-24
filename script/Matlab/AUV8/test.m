clc;
clear;

config = Config('config_AUV8.json');
M= ThrusterModel(config);


disp("----------------------------------");
disp("Test TrusterModel class...");
disp("----------------------------------");


disp("----------------------------------");
disp("limitation de la  force des moteurs (%)");
disp("----------------------------------");
disp(M.fl);

disp("----------------------------------");
disp("Matrice des coefficients des thruster");
disp("----------------------------------");
disp(M.L);

disp("----------------------------------");
disp("Matrice de défault thruster");
disp("----------------------------------");
disp(M.D);

disp("----------------------------------");
disp("Force maximum théorique des 6 DLL");
disp("----------------------------------");
disp(M.MLDT);

disp("----------------------------------");
disp("Force maximum réel des 6 DLL");
disp("----------------------------------");

disp(M.MLDR);
command=[30,5,80,0,0,0];
% LT=M.optimiseThrusterOutput(command);
NLT=M.NLoptimiseThrusterOutput(command);

% disp("----------------------------------");
% disp("Simplex");
% disp("----------------------------------");
% disp("Solution");
% disp(LT);
% disp("----------------------------------");
% disp("vecteur résultant");
% disp(M.L*LT);
% disp("----------------------------------");
% disp("W total");
% disp(M.NonLinearObjFunc(LT));


disp("----------------------------------");
disp("Fmincon");
disp("----------------------------------");
disp("Solution");
disp(NLT.');
disp("----------------------------------");
disp("vecteur résultant");
disp(M.L*NLT.');
disp("----------------------------------");
disp("W total");
disp(M.NonLinearObjFunc(NLT));