% Ce script défini un modèle non linéaire dans un domaine continue
% de la dynamique du sous marin. Il génere par la suite les équations
% d'états ainsi que la jacobienne qui seront utilisés par le controlleur.

% Alexandre Lamarre, Alexandre Desgagné

clear; clc;
%% Création des variables Symboliques
% Nombre de d'états et de commandes
   nX=12; % nombre de state du système
   nU= 8; % nombre d'entrée
   
% Quaternions
  syms('q',[1 4]);
  syms qs qu % Partie scalaire et vecteur unitaire
   
% Position 6 DOFF selon t
    syms xt(t) yt(t) zt(t) phit(t) thetat(t) psit(t)

% Vitesse 6 DOFF selon t 
    syms xdott(t) ydott(t) zdott(t) phidott(t) thetadott(t) psidott(t) 

% Accélérations
    syms ('vdot',[6,1])

% thrusters
    syms ('U',[1,8])


% position et vitesse 6DOFF
    syms x y z phi theta psi xdot ydot zdot phidot thetadot psidot
    
% distance truster x y z selon centre geommétrique
% D14 distance thruster 1 a 4.
% D58 distance thruster 5 a 8.
% a14 angle thruster 1 a 4.
% dz distance entre les increments sur le frame.
% PZ position des truster sur le frame.
    syms('D14',[1 3]); syms('D58',[1 3]) ; syms a14 dz ; syms ('PZ',[1,4]);

% masse, volume du prototype et hauteur sub
    syms mass volume height

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
    const = [D14 D58 a14 dz PZ mass volume height AF...
             I(1,:) I(2,:) I(3,:) RG RB rho g];
    
% États en fonction du temps
    statet =  { xt(t) yt(t) zt(t) phit(t) thetat(t) psit(t)  xdott(t) ...
              ydott(t) zdott(t) phidott(t) thetadott(t) psidott(t)};
      
% États constantes
    state = { x y z phi theta psi  xdot ydot zdot phidot thetadot psidot};

%Sorties
    Output={x y z phi theta psi xdot ydot zdot phidot thetadot psidot};

% Vitesse 
    v = [xdott; ydott; zdott; phidott; thetadott; psidott];
    
% Constantes de drag
    func=[CD];

%% Chargement des paramètres
    cf = ConfigAUV8();

    constValues = [cf.d14 ...
                 cf.d58 ...
                 cf.a14 ...
                 cf.dz ...
                 cf.z ...
                 cf.mass ...
                 cf.volume ...
                 cf.height...
                 cf.AF ...
                 cf.I(1,:) ...
                 cf.I(2,:) ...
                 cf.I(3,:) ...
                 cf.RG ...
                 cf.RB ...
                 cf.rho ...
                 cf.g];

    funcValues=[cf.CD];
    
%% Quaternions
% Determiner le quaternion en fonction des angles d'euler.
% Orde de rotation : ZYX.

% Reel
 q(1) = cos(phi/2) * cos(theta/2) * cos(psi/2)...
      + sin(phi/2) * sin(theta/2) * sin(psi/2);
  
% imaginaire i
 q(2) = sin(phi/2) * cos(theta/2) * cos(psi/2)...
      - cos(phi/2) * sin(theta/2) * sin(psi/2);
  
% imaginaire j
 q(3) = cos(phi/2) * sin(theta/2) * cos(psi/2)...
      + sin(phi/2) * cos(theta/2) * sin(psi/2);
  
% imaginaire k
 q(4) = cos(phi/2) * cos(theta/2) * sin(psi/2)...
      - sin(phi/2) * sin(theta/2) * cos(psi/2);
 
qs=q(1);    % Partie scalaire
qu=-q(2:4); % Partie vectoriel unitaire

%% Matrice de gravite
% Definition de la matrice de gravite.

% Equoition du volume submerger selon la profondeur z.    / ͞ ͞
% Equation a double  asymptote horizontal. voir erf()  __/

    % Calculs des constantes
    aa= volume/2; % Calculer l'amplitude.
    kk=aa;     % Monter la courbe pour avoi min 0 et max volume.
    bb=4/height;  % Calculer la pente transitoire.
    hh=height/2;  % Décaler la courbe pour avoir x(0)=0. 
    
    % Equation
    vz=aa*erf(bb*(z-hh))+kk;
    
% Calculer les vecteurs forces
    w = [0,0,(mass * g)]; % vecteur Gravite
    b = [0,0,-(rho * g * vz)]; % Vecteur poussee d'archimede
    
    % Vecteur Gravité tourne selon le quaternion du sous-marin
    FG=2*dot(qu,w)*qu +(qs^2-dot(qu,qu))*w + 2*qs*cross(qu,w); 
    
    % Vecteur d'archimede tourne selon le quaternion du sous-marin
    FB=2*dot(qu,b)*qu +(qs^2-dot(qu,qu))*b + 2*qs*cross(qu,b);
    
    % Equoitions 6DOF de la gravite
    G =simplify([FB.'+FG.';cross(RB.',FB.')+cross(RG.',FG.')]);


%% Matrice de masse et d'inertie
% Definition des quatres matrices 3x3 pour former la matrice
% des masses du corp rigide.
    Mrb1 = diag(repmat(mass,1,3));
    Mrb2 = [0, mass * RG3, -mass * RG2; ...
            -mass * RG3, 0, mass * RG1;
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
    CA = zeros(6,6); % Public, tunable properties


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
%             x         y      z      
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
   

%% Sommes des forces et des moments

    aditionForceFoment(1:6) =(tau + (Cor * v + Damp * v + G));

%% Équation Dynamique pour simulation
% Liste de tous les états.
% Vitesse/Posision
    simfonction(1) = xdott;
    simfonction(2) = ydott;
    simfonction(3) = zdott;
    simfonction(4) = phidott;
    simfonction(5) = thetadott;
    simfonction(6) = psidott;

%v2 = [xdott^2; ydott^2; zdott^2; phidott^2; thetadott^2; psidott^2];
 %simfonction(7:12)=aditionForceFoment/mass
    simfonction(7) = aditionForceFoment(1)/mass;
    simfonction(8) = aditionForceFoment(2)/mass;
    simfonction(9) = aditionForceFoment(3)/mass;
    simfonction(10) = aditionForceFoment(4)/mass;
    simfonction(11) = aditionForceFoment(5)/mass;
    simfonction(12) = aditionForceFoment(6)/mass;
    
    
%% Substitution des paramètres et des fonctions.
    simfonction = subs(simfonction, const, constValues);
    simfonction = subs(simfonction, func, funcValues);
    simfonction = subs(simfonction, statet, state);
    simfonction = simplify(simfonction);
    
    aditionForceFoment = subs(aditionForceFoment, const, constValues);
    aditionForceFoment = subs(aditionForceFoment, func, funcValues);
    aditionForceFoment = subs(aditionForceFoment, statet, state);
    aditionForceFoment = simplify(aditionForceFoment);
    
    ThrusterMatrix = subs(Tm, const, constValues);
    ThrusterMatrix = subs(ThrusterMatrix, func, funcValues);
    ThrusterMatrix = subs(ThrusterMatrix, statet, state);
    ThrusterMatrix = simplify(ThrusterMatrix);
    
    Gravity = subs(G, const, constValues);
    Gravity = subs(Gravity, func, funcValues);
    Gravity = subs(Gravity, statet, state);
    Gravity = simplify(Gravity);

%% Calcul de la Matrice Jacobienne
    A = jacobian(simfonction, [state{:}]);
    B = jacobian(simfonction, U );
    C = jacobian([state{:}],[Output{:}]);
    D = jacobian([Output{:}], U );


%% Étude de controlabilité
    Xi=zeros(1,nX); % états initials
    Ui=zeros(1,nU);   % Commande initials

    Ad=double(subs(A, state, Xi));
    Bd=double(subs(B, U, Ui));
    Cd=double(C);
    Dd=double(D);

    CPlant=ss(Ad,Bd,Cd,Dd);


    co = ctrb(CPlant);
    controllability = rank(co)
    unco = length(Ad) - rank(co);

%% Generation des fonctions d'etats et Jacobienne

if unco == 0 %si le système est controllable
    
% Crée AUVStateFcn.m
    matlabFunction(transpose(simfonction),'File','AUVStateSimFcn',...
       'Vars',{transpose([Output{:}]),transpose(U)});
   
% Crée AUVJacobianFcn.m 
    matlabFunction(A, B, C, D,'File','simulink/controller/script/AUVStateJacobianFcn',...
        'Vars',{transpose([state{:}]),transpose(U)});  
    
%Crée AUVForceMoment
    matlabFunction(transpose(aditionForceFoment),'File',...
        'simulink/auv_plant/script/AUVForceMoments','Vars',{transpose([Output{:}]),transpose(U)});
    
    %Exporter la matrice thruster
    matlabFunction(transpose(ThrusterMatrix),'File',...
        'simulink/controller/script/ThrusterMatrix');
    
    %Exporter la  AUVForceMoment
    matlabFunction(transpose(Gravity),'File',...
        'simulink/controller/script/Gravity','Vars',{transpose([Output{:}])});
    
   disp("Done")
else
   disp...
   ("Le système n'est pas controlable. Les fichiers n'ont pas été générés")
end   

    


