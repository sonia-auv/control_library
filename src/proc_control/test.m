    syms z
    volume = 0.0365;
    m = 35.42
    H =.3;
    g = 9.81;
    rho = 998

    minVol = (m/rho) *0.996
volume- minVol
    aa = (volume - minVol)/2;   % Calculer l'amplitude.
    kk= minVol +aa;          % Monter la courbe pour avoir min 0 et max volume.
    bb=4/H;         % Calculer la pente transitoire.
    hh=H/2;         % Décaler la courbe pour avoir x(0)=0. 

% Équation erf
    vz=aa*erf(bb*(z-hh))+kk;
    fplot(vz, [-0.5,0.5])



    (m*g)-(rho*g*minVol)