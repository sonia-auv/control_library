% Data Thuster
clc;
load('T200-Spec-16V.mat');
PWM= T200Spec16V{:,1};% PWM
RPM=T200Spec16V{:,2};% vitesse rpm
A=T200Spec16V{:,3};% Ampérage
N=T200Spec16V{:,6};% Force en Newton
W=T200Spec16V{:,7};% puissance watt
E=T200Spec16V{:,3};% efficiency

%plot([N,PWM]);

limit=.5;
PN=T200Spec16V{108:end,6};
NN=T200Spec16V{1:94,6};
PW=T200Spec16V{108:end,7};
NW=T200Spec16V{1:94,7};
MW= GetMinMax(W);
MN=GetMinMax(N);
T=GetRelation(PW,PN);
LIM1=T(MW(1)*limit);
ML=LIM1/MN(1);
T2=GetRelation(NW,NN);
LIM2=T2(MW(2)*limit);
ML2=LIM2/MN(2);

%plot([PW,PN]);


T=interp1(N,RPM,40,'linear');
disp(T);
tf=GetMinMax(N);

% =========================================================================
% Fonction
%==========================================================================
function f= GetRelation(x,y)
% trouve une équoition d'orde 6 pour un nuage de point donnée.
% Arguments : x, Matrice des composante x.
%             y, Matrice des composante y.
options = fitoptions('poly2','Normalize', 'on', 'Robust', 'Bisquare');
disp(options);
f=fit(x,y,'poly6',options);

disp(f);
plot(f,x,y);


end

%==========================================================================
function mm= GetMinMax(A)
% trouve la valeur maximum et minimum d'une matrice.
% Arguments : N, Matrice data.
mm=[A(end),A(1)];
end


