function y = EkfJacobianNavAhrsDepth(x)
%EKFNAVMESUREDF Summary of this function goes here
%   Detailed explanation goes here

n=7; % nb output (n e1 e2 e3 p q r )
nx=13; % nb states ()

c = zeros(n,nx);

c(1:4,4:7) = diag(ones(1,4)); % mapping imu quat
c(5:7,11:13) = diag(ones(1,3)); % mapping imu gyro

y=c;
end

