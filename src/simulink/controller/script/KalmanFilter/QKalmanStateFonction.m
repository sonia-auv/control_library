function xk = QKalmanStateFonction(x,u)
%KALMANSTATEFONCTION Summary of this function goes here
%   Detailed explanation goes here
    M = 10;
    Ts =0.1/10;
    xk = x;

    for i=1:M
        xk = xk + AUVQuatExtSimFcn(x,u)*Ts;
    end
end

