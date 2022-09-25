clc
[simulink, simulation, physics, kalman, MPC, mode] = ConfigAUV7()
constValues = [physics.mass ...
            physics.volume ...
            physics.height...
            physics.I(1,:) ...
            physics.I(2,:) ...
            physics.I(3,:) ...
            physics.RG ...
            physics.RB ...
            physics.CDL ...
            physics.CDQ...
            physics.AddedMass...
            physics.rho ...
            physics.g];

for i=1:MPC.nu
                    
    qt= eul2quat(deg2rad(physics.thruster.T(i,4:6)),'ZYX'); % convertir les angle d'euler en quaternion

    Tm(:,i)=ThrusterVector(physics.thruster.T(i,1:3),qt,physics.RG);   % Calculer le vecteur thrusters     
end

Tm
[M,~,~,~] = AUVModelMatrices(MPC.Xi,constValues);
Minv= inv(M);
B = [zeros(7,8);Minv*Tm]


MPC.Xi(4:7) = eul2quat([0, 0,pi/2],"ZYX").';
MPC.Xi(12) =0.5;

MPC.Ui(5:8) = [20,20,20,20]

J = str2func(MPC.JacobianFnc);
[Ac, Bc, ~, ~] = J(MPC.Xi,MPC.Ui)

A = AUVQuatJacobianMatrix(MPC.Xi,MPC.Ui,constValues);

Aerror = Ac-A

Berror=Bc-B

xkconst = AUV7QuatSimFcn(MPC.Xi,MPC.Ui)
xkDynamic = AUVQuatSimFcn(MPC.Xi, constValues) + B*MPC.Ui

simError = xkconst-xkDynamic
