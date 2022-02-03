function y = EkfJacobianNavDvl(x)
n=3; % nb output ()
nx=13; % nb states ()

c = zeros(n,nx);

c(1:3,8:10) = diag(ones(1,3)); % mapping dvl velocity


y=c;
end

