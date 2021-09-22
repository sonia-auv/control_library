function A = AUVQuatDiscreteJacobianMatrix(x,u)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
[Ac, Bc, Cc, Dc]=AUVEULJacobianMatrix(x,u);
Ts=0.1
nx = size(Ac,1);
nu = size(Bc,2);
M = expm([[Ac Bc]*Ts; zeros(nu,nu+nx)]);
A = M(1:nx,1:nx);
B = M(1:nx,nx+1:nx+nu);
C = Cc;
D = Dc;
end

