%% Système découplé
Px   = tf([0.004383, 0.0006869], [1, 0.8635, 0.08625]);
Py   = tf([0.002875, 3.066e-05], [1, 0.2842, 9.719e-10]);
Pz   = tf([-0.002843, 0.03145], [1, 5.854, 8.112]);
Pyaw = tf([-0.04827, 1.435], [1, 3.87, 7.146]);

%% Rendre l'inverse de Pyaw et Pz stable
PinvZ   = tf([1, 5.854, 8.112], [0.002843, 0.03145]);
PinvYaw = tf([1, 3.870, 7.146], [ 0.04827, 1.435]);

%% Commande B
Jx   = tf(2.001, [1, 0.01]) * tf(9.802, [1, 9.802])^2;
Jy   = tf(1.701, [1, 0.01]) * tf(7.482, [1, 7.482])^2;
Jz   = tf(1.953, [1, 0.01]) * tf(8.59, [1, 8.59])^2;
Jyaw = tf(0.602, [1, 0.01]) * tf(2.649, [1, 2.649])^2;

Cx   = Px^-1   * Jx;
Cy   = Py^-1   * Jy; 
Cz   = PinvZ   * Jz;
Cyaw = PinvYaw * Jyaw;


%% Test de la robustesse
sys = ss(Px);
sys.A = sys.A + 0.1;
Px1 = tf(sys);

sys = ss(Px);
sys.A(2, 1) = sys.A(2, 1) + 1;
Px2 = tf(sys);