% Data Thuster
clc;
load('T200-Spec-16V.mat');
PWM= T200Spec16V{:,1};% PWM
RPM=T200Spec16V{:,2};% vitesse rpm
A=T200Spec16V{:,3};% Ampérage
N=T200Spec16V{:,6};% Force en Newton
W=T200Spec16V{:,7};% puissance watt
E=T200Spec16V{:,3};% efficiency

plot([N,PWM]);

T=interp1(N,PWM,25,'linear');
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


