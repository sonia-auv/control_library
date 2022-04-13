x0 =zeros(12,1);
u0 = zeros(8,1);

[A B C D]=AUVEULJacobianMatrix(x0,u0);


Av = A(7:12,7:12)

Bv = B(7:12,:)

k=[0 0 0 0 0 1]

k* [Bv Av*Bv Av^2*Bv Av^3*Bv Av^4*Bv Av^5*Bv].'