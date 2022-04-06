clc;
clear;
% =========================================================================
% Parametres
% =========================================================================
%Position des truster sur le frame.
%(0 = milieu, 1= position bas, -1= postion haut)(t15,t26,t37,t48)
 z=[0,0,0,0];
 
% Distance entre les postions du frame.
 dz =0.015;
 
% Distance x y z et angles des trusters 1 - 4. 
d14 =[0.292,0.173,0.102]; 
a14 = deg2rad(45);

% Distance x y z des trusters 5 - 8.
d58 =[0.1815,0.159,0.082];

% Force en N horraire et anti horraire.
%tf = [50,-40];

%power supply limitation
psl =.50; 



L=GetMappingMatrix(d14,a14,d58,z,dz);
D=[1,1,1,1,1,1,1,1];
def= diag(D);
%disp(def);

run('ThrusterCurveFitting.m');


%disp(L);
disp(L*def);
%disp(GetMinMaxForceLimit(EQNW,TW,psl));
disp(GetMaxLoadAllAxis(L,tf));

%U = [t1,t2,t3,t4,t5,t6,t7,t8];

% =========================================================================
% Fonction
%==========================================================================
function L= GetMappingMatrix(d14,a14,d58,z,dz)
% Calcule la matrice de componsates des thruster sur les 6DDL.
% Arguments : d14, Matrice Distance x y z  des trusters 1 - 4.
%             a14, Angles des trusters 1 - 4.
%             d58, Matrice distance x y z des trusters 5 - 8.
%             z,   Position des truster sur le frame.
%             dz,  Distance entre les postions du frame.
if ~exist('dz','var')
  dz = 0;
end
 if ~exist('z','var')
  z=[0,0,0,0];
 end
 % Thruster effort Mapping Matrix (L)
%       x         y      z rx ry           rz
l1 = [ sin(a14),-cos(a14), 0, (d14(3)+z(1)*dz)*cos(a14),(d14(3)+z(1)*dz)*sin(a14),-hypot( d14(1), d14(2))];
l2 = [ sin(a14), cos(a14), 0,-(d14(3)+z(2)*dz)*cos(a14), (d14(3)+z(2)*dz)*sin(a14),-hypot(-d14(1), d14(2))];
l3 = [ sin(a14),-cos(a14), 0, (d14(3)+z(3)*dz)*cos(a14), (d14(3)+z(3)*dz)*sin(a14), hypot(-d14(1),-d14(2))];
l4 = [ sin(a14), cos(a14), 0,-(d14(3)+z(4)*dz)*cos(a14), (d14(3)+z(4)*dz)*sin(a14), hypot( d14(1),-d14(2))];
l5 = [0, 0, 1, d58(2),-d58(1), 0];
l6 = [0, 0,-1,-d58(2),-d58(1), 0];
l7 = [0, 0, 1,-d58(2), d58(1), 0];
l8 = [0, 0,-1, d58(2), d58(1), 0];

L= [l1.', l2.', l3.', l4.', l5.' l6.', l7.', l8.'];
end

%==========================================================================
function lax= GetMaxLoadAllAxis(L,tf)
% Calcule la force Maximum déployer sur les thrusters pur les 6DDL.
% Arguments : V matrice de composantes des thrusters (6DDL)
%             tf, matrice de force thruster horraire, antihorraire
[rows ] = size(L);
vml=zeros(size(6));
 for i=1:rows
    V = L(i,:);
    vml(i)= GetMaxLoadOneAxis(V,tf);
 end
 lax=vml.';

end

%==========================================================================
function lxx= GetMaxLoadOneAxis(V,tf)
% Calcule la force Maximum déployer sur les thrusters sur 1 DDL.
% Arguments : V matrice de composantes des thrusters pour 1 DDL
%             tf, matrice de force thruster horraire, antihorraire
mt = 0;
 for i = 1:numel(V)
    mt=mt+GetThrusterMaxLoad(V(i),tf);    
 end
 lxx=mt;
end

%==========================================================================
function mt = GetThrusterMaxLoad(c,tf)
% Retourne la force de la composante selon le sens du thruster
% Arguments : c, la composante du thruster, 
%             tf, matrice de force thruster horraire, antihorraire.
    if c>0
       mt = c*tf(1);
    else
       mt = c*tf(2);
    end
end
%==========================================================================
function tlf=GetMinMaxForceLimit(EQNW,tw,psl)
i=find(EQNW==tw(1)*psl);
tlf=EQNW(i);
disp(11);
%tlf= [fsolve(EQNW,tw(1)*psl),fsolve(EQNW,tw(end)*psl)];
end
