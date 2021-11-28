x0 = zeros(12,1);
u0 = zeros(12, 0);

[A B C D] =AUVEULJacobianMatrix(x0,u0);

Bv = B(7:12,:)
Av =A(7:12,7:12).*eye(6)


syms s

lap=eye(6)*inv((s*eye(6)-Av))