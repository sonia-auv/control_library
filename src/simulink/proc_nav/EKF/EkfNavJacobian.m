function A = EkfNavJacobian(x,u)
%EKFNAVJACOBIAN Summary of this function goes here
%   Detailed explanation goes here
[A,~,~,~] = AUVQuatJacobianMatrix(x,u);
end

