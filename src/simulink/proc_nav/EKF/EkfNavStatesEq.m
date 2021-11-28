function xk = EkfNavStatesEq(x,u)

    M = 5;
    Ts =0.05 / M;
    xk = x;
    p = zeros(6,1);
    for i=1:M
        xk = xk + AUVQuatPerturbedSimFcn(x ,p, u) * Ts;
    end
end
