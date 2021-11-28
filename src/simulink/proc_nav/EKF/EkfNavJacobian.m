function A = EkfNavJacobian(x,u)
%EKFNAVJACOBIAN Summary of this function goes here
%   Detailed explanation goes here
[Ac,Bc,~,~] = EkfNavJacobianMatrix(x,u);
Ts=0.2;
nx = size(Ac,1);
nu = size(Bc,2);
M = expm([[Ac Bc]*Ts; zeros(nu,nu+nx)]);
A = M(1:nx,1:nx);
end

