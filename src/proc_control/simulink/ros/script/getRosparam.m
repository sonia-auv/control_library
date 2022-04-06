function [simulation,physics, thrusters, mpc] = getRosparam()
    % ROSparams
    %rosinit;
    %try
        % Paramètres pour la simulation.
        simulation.reference_frame = uint8(get(rosparam, '/control/simulation/reference_frame'));
        simulation.model_name = uint8(get(rosparam, '/control/simulation/model_name'));

        % Paramètres pour la physique.
        physics.mass = get(rosparam, '/control/physics/mass');
        physics.volume = get(rosparam, '/control/physics/volume');  
        physics.rho = get(rosparam, '/control/physics/rho');  
        physics.g = get(rosparam, '/control/physics/g'); 
        physics.dvlCenterDist = get(rosparam, '/control/physics/dvlCenterDist'); 
        physics.height = get(rosparam, '/control/physics/height');

        buffer = get(rosparam, '/control/physics/inertia');
        V = [size(buffer{1}, 2), size(buffer{1}, 1), 1]; V(find(V == 1, 1)) = numel(buffer);
        temp = horzcat(buffer{:});
        physics.I = reshape([temp{:}], V).';

        buffer = get(rosparam, '/control/physics/RG');
        physics.RG = double([buffer{:}]);

        buffer = get(rosparam, '/control/physics/RB');
        physics.RB = double([buffer{:}]);

        buffer = get(rosparam, '/control/physics/CDL');
        physics.CDL = double([buffer{:}]);

        buffer = get(rosparam, '/control/physics/CDQ');
        physics.CDQ = double([buffer{:}]);

        buffer = get(rosparam, '/control/physics/AF');
        physics.AF = double([buffer{:}]);

        buffer = get(rosparam, '/control/physics/AddedMass');
        physics.AddedMass = double([buffer{:}]);

        % Paramètres pour les thrusters.
        buffer = get(rosparam, '/control/thrusters/ThrusterConfig');
        V = [size(buffer{1}, 2), size(buffer{1}, 1), 1]; V(find(V == 1, 1)) = numel(buffer);
        temp = horzcat(buffer{:});
        thrusters.T = reshape(double([temp{:}]), V).';

        % Paramètres pour le MPC
        mpc.nx = double(get(rosparam, '/control/mpc/nx'));
        mpc.ny = double(get(rosparam, '/control/mpc/ny'));
        mpc.nu = double(get(rosparam, '/control/mpc/nu'));
        mpc.Ts = double(get(rosparam, '/control/mpc/Ts'));
        mpc.p = double(get(rosparam, '/control/mpc/p'));
        mpc.m = double(get(rosparam, '/control/mpc/m'));
        mpc.tmax = double(get(rosparam, '/control/mpc/tmax'));
        mpc.tmin = double(get(rosparam, '/control/mpc/tmin'));

        buffer = get(rosparam, '/control/mpc/gains/default/OV');
        mpc.gains.default.OV = double([buffer{:}]);
        buffer = get(rosparam, '/control/mpc/gains/default/MV');
        mpc.gains.default.MV = double([buffer{:}]);
        buffer = get(rosparam, '/control/mpc/gains/default/MVR');
        mpc.gains.default.MVR = double([buffer{:}]);
        buffer = get(rosparam, '/control/mpc/gains/c10/OV');
        mpc.gains.c10.OV = double([buffer{:}]);
        buffer = get(rosparam, '/control/mpc/gains/c10/MV');
        mpc.gains.c10.MV = double([buffer{:}]);
        buffer = get(rosparam, '/control/mpc/gains/c10/MVR');
        mpc.gains.c10.MVR = double([buffer{:}]);
        buffer = get(rosparam, '/control/mpc/gains/c19/OV');
        mpc.gains.c19.OV = double([buffer{:}]);
        buffer = get(rosparam, '/control/mpc/gains/c19/MV');
        mpc.gains.c19.MV = double([buffer{:}]);
        buffer = get(rosparam, '/control/mpc/gains/c19/MVR');
        mpc.gains.c19.MVR = double([buffer{:}]);

        clear buffer V temp;
    %catch exception
        disp('Missing parameter');
        rosshutdown;
        return;
   % end
   % rosshutdown;
end

