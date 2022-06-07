function xk = EkfNavStatesEq(x,u)

    M = 2;
    Ts =0.02 / M;
    xk = x;
    p = zeros(6,1);
    for i=1:M
        xk = xk + AUV8QuatPerturbedSimFcn(x ,p, u) * Ts;
    end
end
