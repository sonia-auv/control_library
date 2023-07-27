function xk = EkfNavStatesEq(x,inputs)

    % Split u vector and constMec from inputs
    nu = 8;
    u = inputs(2:9);
    constValues = inputs(10:47);
    rg = inputs(22 : 24 );

    % Crée la matrice thrusters 
    T = zeros(nu,6);
    Tm=zeros(6,nu);
    T(1,:) =inputs(48:53);
    T(2,:) =inputs(54:59);
    T(3,:) =inputs(60:65);
    T(4,:) =inputs(66:71);
    T(5,:) =inputs(72:77);
    T(6,:) =inputs(78:83);
    T(7,:) =inputs(84:89);
    T(8,:) =inputs(90:95);
   
   
    for i=1:nu  
        qt= eul2quat(deg2rad(T(i,4:6)),'ZYX');% convertir les angle d'euler en quaternion
        Tm(:,i)=ThrusterVector(T(i,1:3),qt,rg);  % Calculer le vecteur thrusters     
    end

    % prendre la matrice M
    [M,~,~,~] = AUVModelMatrices(x,constValues);

    % M inverse * Tm
    Bc = [zeros(7,nu) ; M\Tm];
    
    % Préparer estimation 
    M = 2;
    Ts =0.02 / M;
    xk = x;
  
    x_dot_kk = zeros(13,1);
   
     for i=1:M
    %     % X(k+1) = A(xk)*xk + B*xk
    %     x_dot_k =  AUVQuatPerturbedSimFcn(xk,zeros(6,1),constValues) + Bc*u.' ;

    %     % Intégration trapezoidale
    %     xk = xk + ((x_dot_k + x_dot_kk)*(Ts))/2;
            
    %     x_dot_kk = x_dot_k;
    xk=  xk + (AUVQuatPerturbedSimFcn(xk,zeros(6,1),constValues) + Bc*u.') * Ts;
    % correct Quaternion
     xk(4:7)=quatUtilities.quatNorm(xk(4:7)); 
    end
 
end

