function [x, status] = mpcCustomSolverCodeGen(H, f, A, b, x0)
% "mpcCustomSolverCodeGen" enables using "quadprog" from Optmization 
% Toolbox as a custom QP solver with linear MPC controller for code generation.

%#codegen
%% Specify solver algorithm (must be "active-set") and options
options = optimoptions('quadprog','Algorithm','active-set');
if coder.target('MATLAB')
    options.Display = 'none';  
end
%% Process solver inputs
% Use -A and -b in "quadprog" because MPC QP uses Ax>=b instead
A_custom = -A;
b_custom = -b;
% ensure Hessian is symmetric
H = (H+H')/2; 
%% Call "quadprog"
[x, ~, exitflag, output] = quadprog(H, f, A_custom, b_custom, [], [], [], [], x0, options);
%% Converts exit flag to MPC "status"
switch exitflag
    case 1
        status = output.iterations;
    case 0
        status = 0;
    case -2
        status = -1;
    otherwise
        status = -2;
end
%% If "quadprog" fails to find a solution, set x to the initial guess
if status <= 0
    x = x0;
end