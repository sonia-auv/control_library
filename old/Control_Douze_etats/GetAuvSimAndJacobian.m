 % Ce script défini un modèle non linéaire dans un domaine continue
% de la dynamique du sous marin. Il génere par la suite les équations
% d'états ainsi que la jacobienne qui seront utilisés par le controlleur.

% Alexandre Lamarre, Aleandre Desgagnié

%clear; clc;
%% Création des variables Symboliques
% Position 6 DOFF selon t
syms xt(t) yt(t) zt(t) phit(t) thetat(t) psit(t)

% Vitesse 6 DOFF selon t 
syms xdott(t) ydott(t) zdott(t) phidott(t) thetadott(t) psidott(t) 

% Accélérations
syms ('vdot',[6,1])

% thrusters
%syms u1 u2 u3 u4 u5 u6 u7 u8
syms ('U',[1,8])

% position et vitesse 6DOFF
syms x y z phi theta psi xdot ydot zdot phidot thetadot psidot

% distance truster x y z selon centre geommétrique
% D14 distance thruster 1 a 4.
% D58 distance thruster 5 a 8.
% a14 angle thruster 1 a 4.
% dz distance entre les increments sur le frame.
% PZ position des truster sur le frame.
syms ('D14',[1 3]); syms('D58',[1 3]) ; syms a14 dz ; syms ('PZ',[1,4])

% masse et volume du prototype
syms mass volume

% coefficient de drag
syms ('CD(x)', [1, 6]);

% aire de surface du sub
syms ('AF', [1, 3]);

% matrice d'inertie
syms ('I', [3, 3]);

% centre de gravité RG et centre de flotataison RB
syms ('RG',[1 3]); syms('RB',[1 3])

% Constantes physique (densité de leau et accélération gravitationel)
syms rho g

%% Grouper les variables symbolique 

% Paramètre relier à la mécanique du sous marin
const = [D14 D58 a14 dz PZ mass volume  AF...
          I(1,:) I(2,:) I(3,:) RG RB rho g];
func = [CD] ;     
% États en fonction du temps
statet =  { xt(t) yt(t) zt(t) phit(t) thetat(t) psit(t)  xdott(t) ...
          ydott(t) zdott(t) phidott(t) thetadott(t) psidott(t)};
      
% États constantes
state = { x y z phi theta psi  xdot ydot zdot phidot thetadot psidot};

%Sorties
Output={x y z phi theta psi xdot ydot zdot phidot thetadot psidot};

%% Chargement des paramètres

cf = ConfigAUV8();

constValues = [cf.d14 ...
             cf.d58 ...
             cf.a14 ...
             cf.dz ...
             cf.z ...
             cf.mass ...
             cf.volume ...       
             cf.AF ...
             cf.I(1,:) ...
             cf.I(2,:) ...
             cf.I(3,:) ...
             cf.RG ...
             cf.RB ...
             cf.rho ...
             cf.g];
         
funcValues=[cf.CD];
%% Matrice de transformation 
% Angle Euler X Y Z
Rz = [ cos(psit), -sin(psit), 0;
       sin(psit),  cos(psit), 0;
       0        ,  0        , 1];
   
Ry = [ cos(thetat), 0,  sin(thetat);
       0          , 1,  0;
      -sin(thetat), 0,  cos(thetat)];
  
Rx = [1, 0        , 0;
      0, cos(phit), -sin(phit);
      0, sin(phit), cos(phit)];

% Matrice de transformation vitesse liéaire du frame sub au frame world
J1 = Rz*Ry*Rx;

% Matrice de transformation vitesse angulaire du frame sub au frame world
%J2⁻¹
J2i=[[1;0;0],Rx.'*[0;1;0],Rx.'*Ry.'*[0;0;1]];
J2=simplify(inv(J2i));

J= diag([J1,J2]);

%% Matrice de gravite
% Definition de la matrice de gravite.
w = mass * g;
b = rho * g * volume;
FG = inv(J1)*[0;0;w];
FB = inv(J1)*[0;0;-b];
gg =simplify([FB+FG;cross(RB.',FB)+cross(RG.',FG)]);

X  =  (w-b)*sin(thetat);
Y  =  -(w-b)*cos(thetat)*sin(phit);
Z  =  -(w-b)*cos(thetat)*cos(phit);

Rx = -(RG2*w-RB2*b)*cos(thetat)*cos(phit)+...
      (RG3*w-RB3*b)*cos(thetat)*sin(phit);

Ry =  (RG3*w-RB3*b)*sin(thetat)+...
      (RG1*w-RB1*b)*cos(thetat)*cos(phit);

Rz =  -(RG1*w-RB1*b)*cos(thetat)*sin(phit)-...
      (RG2*w-RB2*b)*sin(thetat);

G  = [X;Y;Z;Rx;Ry;Rz];

%% Matrice de masse et d'inertie
% Definition des quatres matrices 3x3 pour former la matrice
% des masses du corp rigide.
Mrb1 = diag(repmat(mass,1,3));
Mrb2 = [0, mass * RG3, -mass * RG2; ...
        -mass * RG3, 0, mass * RG1; ...
        mass * RG2, -mass * RG1, 0];
Mrb3 = [0, -mass * RG3, mass * RG2; ...
        mass * RG3, 0, -mass * RG1; ...
        -mass * RG2, mass * RG1, 0];

forme= (diag(repmat(2,1,3))-1); % diag 1 avec -1 partout
Mrb4 = I.*forme;

% Matrice des masses du corps rigide.
MRB = [Mrb1, Mrb2; ... 
       Mrb3, Mrb4];

% Matrice des masses ajoutees.
MA=zeros(6,6);

% Calcul de la matrice des masses et inerties.
M = MRB + MA;
%M=sum(M,2);
%% Matrice des forces de Coriolis
% Définition des matrices 3x3 pour former la matrice de
% Coriolis (corps rigide).
Crb1 = zeros(3,3);
Crb23 = [0, mass * zdott, -mass * ydott; ...
         -mass * zdott, 0, mass * xdott; ...
         mass * ydott, -mass * xdott, 0];
Crb4 = [0, I3_3 * psidott, -I2_2 * thetadott; ...
        -I3_3 * psidott, 0, I1_1 * phidott; ...
        I2_2 * thetadott, -I1_1 * phidott, 0];
% Matrice de Coriolis(Corps rigide)
CRB = [Crb1, Crb23; ...
       Crb23, Crb4];

% Matrice de Coriolis (masse ajoutée)
CA = zeros(6,6);

% Matrice de Coriolis
Cor = CRB + CA;
    
%% Matrice des forces de drag
xu = (-(1/2) * rho * CD1(xdot) * AF1);% * xdott;
yv = (-(1/2) * rho * CD2(ydott) * AF2);% * ydott;
zw = (-(1/2) * rho * CD3(zdott) * AF3);% * zdott;
kp = (-(1/2) * rho * CD4(phidott) * AF3) ;%* phidott;
mq = (-(1/2) * rho * CD5(thetadott) * AF3) ;%* thetadott;
nr = (-(1/2) * rho * CD6(psidott) * AF2);% * psidott;

% Matrice quadratic damping.
Dq = diag([xu yv zw kp mq nr]);

% Matrice linear damping.
Dl = zeros(6,6);

Damp = Dq + Dl;

%% Definir la matrice thrusters

% Thruster effort Mapping Matrix (L)
%       x         y      z      
l1 = [ sin(a14),-cos(a14), 0,... fxyz
    (D14(3)-RG(3)+PZ(1)*dz)*cos(a14),... rx
    (D14(3)-RG(3)+PZ(1)*dz)*sin(a14),... ry
    -hypot( D14(1)-RG(1), D14(2)-RG(2))]; %rz

l2 = [ sin(a14), cos(a14), 0,...fxyz
     -(D14(3)-RG(3)+PZ(2)*dz)*cos(a14),...rx
     (D14(3)-RG(3)+PZ(2)*dz)*sin(a14),...ry
     -hypot( D14(1)+RG(1), D14(2)-RG(2))];%rz

l3 = [ sin(a14),-cos(a14), 0,...fxyz
    (D14(3)-RG(3)+PZ(3)*dz)*cos(a14),...rx
     (D14(3)-RG(3)+PZ(3)*dz)*sin(a14),...ry
     hypot(D14(1)+RG(1), D14(2)+RG(2))];%rz

l4 = [ sin(a14), cos(a14), 0,...fxyz
    -(D14(3)-RG(3)+PZ(4)*dz)*cos(a14),...rx
     (D14(3)-RG(3)+PZ(4)*dz)*sin(a14),...ry
     hypot(D14(1)-RG(1), D14(2)+RG(2))];%rz

l5 = [0, 0, 1, (D58(2)-RG(2)+PZ(1)*dz),...
     -(D58(1)-RG(1)+PZ(1)*dz), 0];

l6 = [0, 0,-1,-(D58(2)-RG(2)+PZ(2)*dz),...
      -(D58(1)+RG(1)+PZ(2)*dz), 0];

l7 = [0, 0, 1,-(D58(2)+RG(2)+PZ(3)*dz),...
    (D58(1)+RG(1)+PZ(3)*dz), 0];

l8 = [0, 0,-1, (D58(2)+RG(2)+PZ(4)*dz),...
     (D58(1)-RG(1)+PZ(2)*dz), 0];
 
% Matrice thrusters
Tm = [l1.', l2.', l3.', l4.', l5.' l6.', l7.', l8.'];
% équoition input pour 6doff
tau = simplify(sum(Tm*diag(U),2)); 
tt=Tm*U.';
%% Équation Dynamique pour simulation
% Liste de tous les états.
% Vitesse/Posision
simfonction(1) = xdott;
simfonction(2) = ydott;
simfonction(3) = zdott;
simfonction(4) = phidott;
simfonction(5) = thetadott;
simfonction(6) = psidott;


v = [xdott; ydott; zdott; phidott; thetadott; psidott];
v2 = [xdott^2; ydott^2; zdott^2; phidott^2; thetadott^2; psidott^2];
% Vitesse/Accélération
% simfonction(7:12) = -Damp* v -Cor*v - G +tau ;
%  
% simfonction(7)  = (simfonction(7))/M(1);
% simfonction(8)  = (simfonction(8))/M(2);
% simfonction(9)  = (simfonction(9))/M(3);
% simfonction(10) =(simfonction(10))/M(4);
% simfonction(11) =(simfonction(11))/M(5);
% simfonction(12) =(simfonction(12))/M(6); 
%  
% tt=M.'*vdot;
% ttt=Tm*U.';
% eqn = M * vdot == Tm*U.'-(-Damp * v +Cor*v -G);
% S = solve(eqn, vdot);
% simfonction(7) = S.vdot1;
% simfonction(8) = S.vdot2;
% simfonction(9) = S.vdot3;
% simfonction(10) = S.vdot4;
% simfonction(11) = S.vdot5;
% simfonction(12) = S.vdot6;
simfonction(7:12) = (tau + (Cor * v + Damp * v + G))/mass;
% Substitution des paramètres et des fontions.
simfonction = subs(simfonction, const, constValues);
simfonction = subs(simfonction, func, funcValues);
simfonction = subs(simfonction, statet, state);
simfonction = simplify(simfonction);

%%Équation d'état
statefonction(1:2)=simfonction(4:5);
statefonction(3:8)=simfonction(7:12);

aditionforcemoment(1:6)=(tau + (Cor * v + Damp * v + G));
aditionforcemoment = subs(aditionforcemoment, const, constValues);
aditionforcemoment = subs(aditionforcemoment, func, funcValues);
aditionforcemoment = subs(aditionforcemoment, statet, state);
aditionforcemoment = simplify(aditionforcemoment);

physique(1:6)=tau;
physique(7:12)=Cor * v;
physique(13:18)=Damp * v;
physique(19:24)=G;

physique = subs(physique, const, constValues);
physique = subs(physique, func, funcValues);
physique = subs(physique, statet, state);
physique = simplify(physique);

%% Calcul de la Matrice Jacobienne
A = jacobian(simfonction, [state{:}]);
B = jacobian(simfonction, U );
C = jacobian([state{:}],[Output{:}]);
D = jacobian([Output{:}], U );


%% Étude de controlabilité
Xi=repmat(0,1,12); % états initials
Ui=repmat(0,1,8);   % Commande initials

Ad=double(subs(A, state, Xi));
Bd=double(subs(B, U, Ui));
Cd=double(C);
Dd=double(D);

CPlant=ss(Ad,Bd,Cd,Dd);


co = ctrb(CPlant);
controllability = rank(co)
unco = length(Ad) - rank(co)

%% Generation des fonctions d'etats et Jacobienne
% Crée AUVStateFcn.m
matlabFunction(transpose(simfonction),'File','AUVStateSimFcn',...
   'Vars',{transpose([Output{:}]),transpose(U)});
% Crée AUVJacobianFcn.m 
matlabFunction(A, B, C, D,'File','AUVStateJacobianFcn',...
    'Vars',{transpose([state{:}]),transpose(U)});   

matlabFunction(transpose(aditionforcemoment),'File','AUVForceMoments',...
   'Vars',{transpose([Output{:}]),transpose(U)});
disp("Done")

matlabFunction(transpose(physique),'File','AUVDynamics',...
   'Vars',{transpose([Output{:}]),transpose(U)});
disp("Done")
