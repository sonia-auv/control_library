    syms z
    volume = 0.0365;
    H =.3;


    aa = volume/4;   % Calculer l'amplitude.
    kk=aa;          % Monter la courbe pour avoir min 0 et max volume.
    bb=4/H;         % Calculer la pente transitoire.
    hh=H/2;         % Décaler la courbe pour avoir x(0)=0. 

% Équation erf
    vz=aa*erf(bb*(z-hh))+kk;
    fplot(vz, [-0.5,0.5])