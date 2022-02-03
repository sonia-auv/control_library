rosinit;

Ip = get(rosparam, '/control/physics/inertia');
V = [size(Ip{1}, 2), size(Ip{1}, 1), 1]; V(find(V == 1, 1)) = numel(Ip);
temp = horzcat(Ip{:});
physics.I = reshape([temp{:}], V).'

RGp = get(rosparam, '/control/physics/RG');
physics.RG = double([RGp{:}])

RBp = get(rosparam, '/control/physics/RB');
physics.RB = double([RBp{:}])

CDLp = get(rosparam, '/control/physics/CDL');
physics.CDL = double([CDLp{:}])

CDQp = get(rosparam, '/control/physics/CDQ');
physics.CDQ = double([CDQp{:}])

AFp = get(rosparam, '/control/physics/AF');
physics.AF = double([AFp{:}])

AddedMassp = get(rosparam, '/control/physics/AddedMass');
physics.AddedMass = double([AddedMassp{:}])

Thrusterp = get(rosparam, '/control/thrusters/ThrusterConfig');
V = [size(Thrusterp{1}, 2), size(Thrusterp{1}, 1), 1]; V(find(V == 1, 1)) = numel(Thrusterp);
temp = horzcat(Thrusterp{:});
physics.T = reshape(double([temp{:}]), V).'

rosshutdown
