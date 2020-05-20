load('T200-Spec-16V.mat');
N=T200Spec16V{:,6};
A=T200Spec16V{:,3};
W=T200Spec16V{:,7};

EQNW= GetRelation(N,W);
tf= GetMinMax(N);
TW= GetMinMax(W);
%tlf=GetMinMaxForceLimit(EQNW,TW,psl);

% =========================================================================
% Fonction
%==========================================================================
function f = GetRelation(x,y)
% trouve une équoition d'orde 6 pour un nuage de point donnée.
% Arguments : x, Matrice des composante x.
%             y, Matrice des composante y.
options = fitoptions('poly6','Normalize', 'on', 'Robust', 'Bisquare');
disp(options);
ff=fit(x,y,'poly6',options);
disp(ff);
plot(ff,x,y);
f = formula(ff);
end

%==========================================================================
function mm= GetMinMax(A)
% trouve la valeur maximum et minimum d'une matrice.
% Arguments : N, Matrice data.
mm=[A(end),A(1)];
end


