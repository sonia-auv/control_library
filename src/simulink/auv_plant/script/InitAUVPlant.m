
% Initialiser le seed du random
rng shuffle

%% Perturbations des vagues
    %Vages X
    waX=.5;          % Amplitude
    wfX=pi/2;         % Frequence
    wpX=0;          % Phase
    %Vages Y
    waY=1;          % Amplitude
    wfY=pi/2;         % Frequence
    wpY=pi/2;       % Phase
    %Vages Z
    waZ= 1.5 ;         % Amplitude
    wfZ=pi/2;         % Frequence
    wpZ=pi;         % Phase
    %Vages RX (Roll)
    waPhi= .5;      % Amplitude
    wfPhi= pi/3;      % Frequence
    wpPhi=0;        % Phase
    %Vages Ry (Pitch)
    waTheta=.5;    % Amplitude
    wfTheta=pi/3;     % Frequence
    wpTheta=pi/2;   % Phase
    %Vages Rz (Yaw)
    waPsi=.5;       % Amplitude
    wfPsi=pi/3;       % Frequence
    wpPsi=pi;       % Phase
    
%% Damping des vagues en fonction de la profondeur
    
% On suppose un ratio linéaire Ax +B
    dampA = -0.4;
    dampB = 1;
    
    ratioMax =1;
    ratioMin =0.2;


%% Perturbation Drift

    dts=5; % Temp d'échantillionage des perturbation
    
    % Perturbation x
    dMinX=-0.5*rand(); % Valeur minimum x
    dMaxX=0.5*rand();  % Valeur maximum x
    dSeedX=round(rand*10);
    
    % Perturbation y
    dMinY=-1.5*rand(); % Valeur minimum  y
    dMaxY=1.5*rand();  % Valeur maximumx y
    dSeedY=round(rand*10);