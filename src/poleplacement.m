
x=repmat(Xi.',11,1)
u =zeros(11,8)

% Déterminer les dimentions
    nx = size(ysec,2);
    nu = size(u,2);
    p = size(u,1)-1;

% Initialiser les matrices
    A = zeros(nx, nx, p);
    B = zeros(nx, nu, p);
    C = zeros(nx, nx, p);
    D = zeros(nx, nu, p);
    U = zeros(nu, 1, p);
    Y = zeros(13, 1, p);
    X = zeros(13, 1, p);
    DX = zeros(13, 1, p);


for i=1:size(u,1)-1
    
    % Actualiser les états
        xk=x(i,:).';
        uk=u(i,:).';
        
    % Lineariser le model dynamique
        [Ac, Bc, C(:,:,i), D(:,:,i)]=AUVQuatJacobianMatrix(xk,uk);


    % Generate discrete-time model
        A(:,:,i) = expm(Ac*Ts); % Fossen(2021) Eq B.10/B.9 page 662

        BT = Ac(8:13,8:13)\(A(8:13,8:13)-eye(6))*Bc(8:13,1:8); % Fossen(2021) Eq B.11 p 662
        B(:,:,i) = [zeros(7,8); BT];

    % Compute F(x(k+1),u)
        xkk = xk;
        % discretiser le modèle avec un Ts plus petit que le celui du controle
        for i=1:M 
          xkk = xkk + AUVQuatSimFcn(xkk,uk)*(Ts/M);  
        end

    % Nominal conditions for discrete-time plant
        U(:,:,i)  = uk.';
        Y(:,:,i)  = xk.';%(Cc*x + Dc*u).';
        X(:,:,i)  = xk.';
        DX(:,:,i) = (xkk-xk).' ;
end