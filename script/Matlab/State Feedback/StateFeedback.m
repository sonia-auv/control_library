%% Etude du système complet

A = [[-0.8635,      -0.345,           0,           0,           0,           0,           0,           0];
     [   0.25,           0,           0,           0,           0,           0,           0,           0];
     [      0,           0,     -0.2842,  -3.185e-05,           0,           0,           0,           0];
     [      0,           0,   3.052e-05,           0,           0,           0,           0,           0];
     [      0,           0,           0,           0,      -5.854,      -2.028,           0,           0];
     [      0,           0,           0,           0,           4,           0,           0,           0];
     [      0,           0,           0,           0,           0,           0,       -3.87,      -3.573];
     [      0,           0,           0,           0,           0,           0,           2,           0]];
  
 
B = [[0.0625,       0,       0,       0,       0,       0];
     [     0,       0,       0,       0,       0,       0];
     [     0,       1,       0,       0,       0,       0];
     [     0,       0,       0,       0,       0,       0];
     [     0,       0,   0.125,       0,       0,       0];
     [     0,       0,       0,       0,       0,       0];
     [     0,       0,       0,       0,       0,       1];
     [     0,       0,       0,       0,       0,       0]];
 

C = [[0.07013,   0.04396,         0,         0,         0,         0,         0,         0];
     [      0,         0,  0.002875,    -1.005,         0,         0,         0,         0];
     [      0,         0,         0,         0,  -0.02275,   0.06289,         0,         0];
     [      0,         0,         0,         0,         0,         0,         0,         0];
     [      0,         0,         0,         0,         0,         0,         0,         0];
     [      0,         0,         0,         0,         0,         0,  -0.04827,    0.7176]];
 

D = [[0   0   0   0   0   0];
     [0   0   0   0   0   0];
     [0   0   0   0   0   0];
     [0   0   0   0   0   0];
     [0   0   0   0   0   0];
     [0   0   0   0   0   0]];

tfXaxis = tf([0.004383, 0.0006869], [1, 0.8635, 0.08625]);
tfYaxis = tf([0.002875, 3.066e-05], [1, 0.2842, 9.719e-10]);
tfZaxis = tf([-0.002843, 0.03145], [1, 5.854, 8.112]);
tfYawaxis = tf([-0.04827, 1.435], [1, 3.87, 7.146]);

tfMatrix = [[tfXaxis,       0,       0, 0, 0,         0]; 
            [      0, tfYaxis,       0, 0, 0,         0];
            [      0,       0, tfZaxis, 0, 0,         0];
            [      0,       0,       0, 0, 0,         0];
            [      0,       0,       0, 0, 0,         0];
            [      0,       0,       0, 0, 0, tfYawaxis]];
        
sys_from_tf = ss(tfMatrix);

sys = ss(A, B, C, D);

% Commandabilité
Co = ctrb(A,B);
if(rank(Co) == size(A, 1))
   disp("Système commandable !")
end

% Observabilité
Obs = obsv(A,C);
if(rank(Obs) == size(A, 1))
   disp("Système observable !")
end

% On a accès à aucun état car y dépend de plusieurs états en même temps =>
% on ne peut pas différencier xi de xj

% Stabilité
if(eig(A) < 0 - 1e-05)
   disp("Système stable !") 
end
damp(A)
%pzmap(sys);


%% Retour d'état sur le système complet

Pcom = [ -7.48e-01; -1.15e-01; -2.84e-01; -1.5e-01; -3.60e+00; -2.25e+00; -1.94e+00 + 1.84e+00i; -1.94e+00 - 1.84e+00i ];
K = place(A,B,Pcom)

sys2 = ss(A-B*K,B,C,D);
figure
pzmap(sys2);

x0 = zeros(size(A, 1), 1);

%% Observateur sur le système complet
% On choisit des poles bien plus rapides que ceux du retour d'état
Pobs = 50*Pcom;

At = transpose(A);
Ct = transpose(C);
Ht = place(At,Ct,Pobs);
H = transpose(Ht);

dimU = size(B,2);
dimY = size(C,1);

A_prime = A - H*C;
B_prime = [B H];
C_prime = [C; zeros(size(A_prime, 1), 1)'; zeros(size(A_prime, 1), 1)'];
D_prime = zeros(size(C_prime, 1), size(B_prime, 2));
x0_chap = zeros(size(A_prime, 1), 1); % Valeur initiale

%% Régulateur complet (retour d'état + observateur)
Ar = A - H*C - B*K;
Br = [B H];
Cr = -K;
Dr = [ eye(dimU) zeros(dimU, dimY) ];
x0r = zeros(size(Ar, 1), 1);



%% Etude en sous-systèmes : 4 axes découplés

%% X
sys_from_tf_X = ss(tfXaxis);
Ax = sys_from_tf_X.A;
Bx = sys_from_tf_X.B;
Cx = sys_from_tf_X.C;
Dx = sys_from_tf_X.D;

x0x = zeros(size(Ax, 1), 1);

% Commandabilité
Co = ctrb(Ax,Bx);
if(rank(Co) == size(Ax, 1))
   disp("Système commandable !")
end

% Observabilité
Obs = obsv(Ax,Cx);
if(rank(Obs) == size(Ax, 1))
   disp("Système observable !")
end

% On a accès à aucun état car y dépend de plusieurs états en même temps =>
% on ne peut pas différencier xi de xj

% Stabilité
if(eig(Ax) < 0 - 1e-05)
   disp("Système stable !") 
end
damp(Ax)
pzmap(sys_from_tf_X);

% Retour d'état
%rltool(sys_from_tf_X)
Pcom = [ -1.5; -0.157];
Kx = place(Ax,Bx,Pcom)
damp(Ax-Bx*Kx)

% Observateur
% On choisit des poles bien plus rapides que ceux du retour d'état
Pobs = 50*Pcom;
At = transpose(Ax);
Ct = transpose(Cx);
Ht = place(At,Ct,Pobs);
Hx = transpose(Ht);

dimU = size(Bx,2);
dimY = size(Cx,1);

Ax_prime = Ax - Hx*Cx;
Bx_prime = [Bx Hx];
Cx_prime = eye(2);
Dx_prime = zeros(size(Cx_prime, 1), size(Bx_prime, 2));
x0_chap = zeros(size(Ax_prime, 1), 1); % Valeur initiale

% Régulateur complet (retour d'état + observateur)
Ar = Ax - Hx*Cx - Bx*Kx;
Br = [Bx Hx];
Cr = -Kx;
Dr = [ eye(dimU) zeros(dimU, dimY) ];
x0r = zeros(size(Ar, 1), 1);

% Régulateur complet avec précompensateur 
E = Cx;
Sx = -inv(E*inv(Ax-Bx*Kx)*Bx);
Arpx = Ar;
Brpx = [Bx*Sx Hx];
Crpx = Cr;
Drpx = [Sx 0];
xp = -(Ax-Bx*Kx)'*Bx*Sx;
yc = E*xp

%% Y
sys_from_tf_Y = ss(tfYaxis);
Ay = sys_from_tf_Y.A;
By = sys_from_tf_Y.B;
Cy = sys_from_tf_Y.C;
Dy = sys_from_tf_Y.D;

x0y = zeros(size(Ay, 1), 1);

% Commandabilité
Co = ctrb(Ay,By);
if(rank(Co) == size(Ay, 1))
   disp("Système commandable !")
end

% Observabilité
Obs = obsv(Ay,Cy);
if(rank(Obs) == size(Ay, 1))
   disp("Système observable !")
end

% On a accès à aucun état car y dépend de plusieurs états en même temps =>
% on ne peut pas différencier xi de xj

% Stabilité
if(eig(Ay) < 0 - 1e-05)
   disp("Système stable !") 
end
damp(Ay)
figure;
pzmap(sys_from_tf_Y);

% Retour d'état
%rltool(sys_from_tf_Y)
Pcom = [ -1.5; -0.01067];
Ky = place(Ay,By,Pcom)
damp(Ay-By*Ky)

% Observateur
% On choisit des poles bien plus rapide que ceux du retour d'état
Pobs = 50*Pcom;
At = transpose(Ay);
Ct = transpose(Cy);
Ht = place(At,Ct,Pobs);
Hy = transpose(Ht);

dimU = size(By,2);
dimY = size(Cy,1);

Ay_prime = Ay - Hy*Cy;
By_prime = [By Hy];
Cy_prime = eye(2);
Dy_prime = zeros(size(Cy_prime, 1), size(By_prime, 2));
x0_chap = zeros(size(Ay_prime, 1), 1); % Valeur initiale à modifier

% Régulateur complet (retour d'état + observateur)
Ar = Ay - Hy*Cy - By*Ky;
Br = [By Hy];
Cr = -Ky;
Dr = [ eye(dimU) zeros(dimU, dimY) ];
x0r = zeros(size(Ar, 1), 1);

% Régulateur complet avec précompensateur 
E = Cy;
Sy = -inv(E*inv(Ay-By*Ky)*By);
Arpy = Ar;
Brpy = [By*Sy Hy];
Crpy = Cr;
Drpy = [Sy 0];

%% Z

sys_from_tf_Z = ss(tfZaxis);
Az = sys_from_tf_Z.A;
Bz= sys_from_tf_Z.B;
Cz = sys_from_tf_Z.C;
Dz = sys_from_tf_Z.D;

x0z = zeros(size(Az, 1), 1);

% Commandabilité
Co = ctrb(Az,Bz);
if(rank(Co) == size(Az, 1))
   disp("Système commandable !")
end

% Observabilité
Obs = obsv(Az,Cz);
if(rank(Obs) == size(Az, 1))
   disp("Système observable !")
end

% On a accès à aucun état car y dépend de plusieurs états en même temps =>
% on ne peut pas différencier xi de xj

% Stabilité
if(eig(Az) < 0 - 1e-05)
   disp("Système stable !") 
end
damp(Az)
figure;
pzmap(sys_from_tf_Z);


% Retour d'état
% rltool(sys_from_tf_Z)
Pcom = [ -2; -2.1];
Kz = place(Az,Bz,Pcom)
damp(Az-Bz*Kz)

% Observateur
% On choisit des poles bien plus rapide que ceux du retour d'état
Pobs = 50*Pcom;
At = transpose(Az);
Ct = transpose(Cz);
Ht = place(At,Ct,Pobs);
Hz = transpose(Ht);

dimU = size(Bz,2);
dimY = size(Cz,1);

Az_prime = Az - Hz*Cz;
Bz_prime = [Bz Hz];
Cz_prime = eye(2);
Dz_prime = zeros(size(Cz_prime, 1), size(Bz_prime, 2));
x0_chap = zeros(size(Az_prime, 1), 1); % Valeur initiale à modifier

% Régulateur complet (retour d'état + observateur)
Ar = Az - Hz*Cz - Bz*Kz;
Br = [Bz Hz];
Cr = -Kz;
Dr = [ eye(dimU) zeros(dimU, dimY) ];
x0r = zeros(size(Ar, 1), 1);

% Régulateur complet avec précompensateur
E = Cz;
Sz = -inv(E*inv(Az-Bz*Kz)*Bz);
Arpy = Ar;
Brpy = [Bz*Sz Hz];
Crpy = Cr;
Drpy = [Sz 0];

%% Yaw

sys_from_tf_Yaw = ss(tfYawaxis);
Ayaw = sys_from_tf_Yaw.A;
Byaw= sys_from_tf_Yaw.B;
Cyaw = sys_from_tf_Yaw.C;
Dyaw = sys_from_tf_Yaw.D;

x0yaw = zeros(size(Ayaw, 1), 1);

% Commandabilité
Co = ctrb(Ayaw,Byaw);
if(rank(Co) == size(Ayaw, 1))
   disp("Système commandable !")
end

% Observabilité
Obs = obsv(Ayaw,Cyaw);
if(rank(Obs) == size(Ayaw, 1))
   disp("Système observable !")
end

% On a accès à aucun état car y dépend de plusieurs états en même temps =>
% on ne peut pas différencier xi de xj

% Stabilité
if(eig(Ayaw) < 0 - 1e-05)
   disp("Système stable !") 
end
damp(Ayaw)
figure;
pzmap(sys_from_tf_Yaw);

% Retour d'état
%rltool(sys_from_tf_Yaw)
Pcom = [ -2; -2.5];
Kyaw = place(Ayaw,Byaw,Pcom)
damp(Ayaw-Byaw*Kyaw)

% Observateur
% On choisit des poles bien plus rapide que ceux du retour d'état
Pobs = 50*Pcom;
At = transpose(Ayaw);
Ct = transpose(Cyaw);
Ht = place(At,Ct,Pobs);
Hyaw = transpose(Ht);

dimU = size(Byaw,2);
dimY = size(Cyaw,1);

Ayaw_prime = Ayaw - Hyaw*Cyaw;
Byaw_prime = [Byaw Hyaw];
Cyaw_prime = eye(2);
Dyaw_prime = zeros(size(Cyaw_prime, 1), size(Byaw_prime, 2));
x0_chap = zeros(size(Ayaw_prime, 1), 1); % Valeur initiale

% Régulateur complet (retour d'état + observateur)
Ar = Ayaw - Hyaw*Cyaw - Byaw*Kyaw;
Br = [Byaw Hyaw];
Cr = -Kyaw;
Dr = [ eye(dimU) zeros(dimU, dimY) ];
x0r = zeros(size(Ar, 1), 1);

% Régulateur complet avec précompensateur
E = Cyaw;
Syaw = -inv(E*inv(Ayaw-Byaw*Kyaw)*Byaw);
Arpy = Ar;
Brpy = [Byaw*Syaw Hyaw];
Crpy = Cr;
Drpy = [Syaw 0];
