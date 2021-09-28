function A = EkfNavJacobian(x,u)
%EKFNAVJACOBIAN Summary of this function goes here
%   Detailed explanation goes here
[A,~,~,~] = EkfNavJacobianMatrix(x,u);
end

