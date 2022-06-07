function Traj_viewer(trajMsg)
    % Affiche la trajectoire généré par le planner.
    % Initialise array
    n = size(trajMsg.Transforms,1);
    pose = zeros(n,3);
    quat = zeros(n,4);
    velocity = zeros(n,3);
    angularRate = zeros(n,3);


    for i=1 : size(trajMsg.Transforms,1)
        pose(i,1) = trajMsg.Transforms(i).Translation.X;
        pose(i,2) = trajMsg.Transforms(i).Translation.Y;
        pose(i,3) = trajMsg.Transforms(i).Translation.Z;

        quat(i,1) = trajMsg.Transforms(i).Rotation.W;
        quat(i,2) = trajMsg.Transforms(i).Rotation.X;
        quat(i,3) = trajMsg.Transforms(i).Rotation.Y;
        quat(i,4) = trajMsg.Transforms(i).Rotation.Z;
        
        velocity(i,1) = trajMsg.Velocities(i).Linear.X;
        velocity(i,2) = trajMsg.Velocities(i).Linear.Y;
        velocity(i,3) = trajMsg.Velocities(i).Linear.Z;     

        angularRate(i,1) = trajMsg.Velocities(i).Angular.X;
        angularRate(i,2) = trajMsg.Velocities(i).Angular.Y;
        angularRate(i,3) = trajMsg.Velocities(i).Angular.Z;
        
        linearAcc(i,1) = trajMsg.Accelerations(i).Linear.X;
        linearAcc(i,2) = trajMsg.Accelerations(i).Linear.Y;
        linearAcc(i,3) = trajMsg.Accelerations(i).Linear.Z;

        angularAcc(i,1) = trajMsg.Accelerations(i).Angular.X;
        angularAcc(i,2) = trajMsg.Accelerations(i).Angular.Y;
        angularAcc(i,3) = trajMsg.Accelerations(i).Angular.Z;
    end

    tvec  = (0:1:n-1)/10;
    tiledlayout(2,1);

    % Afficher l'orientation en fonction du temps
    nexttile;
    plot(tvec,quat.');
    ax = gca;
    ax.FontSize = 13;
    title('Orientation en fonction du temps');
    xlabel('temps en seconde');
    legend({'\eta','\epsilon_1','\epsilon_2','\epsilon_3'},'Location','northeast');

    % Afficher la positions en fonction du temps
    nexttile;
    plot(tvec, pose.');
    ax = gca;
    ax.FontSize = 13;
    title('Position en fonction du temps');
    xlabel('temps en seconde') ;
    ylabel('distance en mètre');
    legend({'distance en x','distance en x','distance en z'},'Location','northeast');

    figure;
    % Afficher vitesse angulaire en fonction du temps
    nexttile;
    plot(tvec,angularRate.');
    ax = gca;
    ax.FontSize = 13;
    title('Vitesse angulaire en fonction du temps');
    xlabel('temps en seconde');
    legend({'p','q','r',},'Location','northeast');

    % Afficher la vitesse lineaire en fonction du temps
    nexttile;
    plot(tvec, velocity.');
    ax = gca;
    ax.FontSize = 13;
    title('vitesse linéaire en fonction du temps');
    xlabel('temps en seconde') ;
    ylabel('distance en mètre');
    legend({'u','v','w'},'Location','northeast');

    figure;
    % Afficher acceleration angulaire en fonction du temps
    nexttile;
    plot(tvec,angularAcc.');
    ax = gca;
    ax.FontSize = 13;
    title('acceleration angulaire en fonction du temps');
    xlabel('temps en seconde');
    legend({'\p_dot','\q_dot','\r_dot'},'Location','northeast');

    % Afficher la v lineaire en fonction du temps
    nexttile;
    plot(tvec, linearAcc.');
    ax = gca;
    ax.FontSize = 13;
    title('acceleration linéaire en fonction du temps');
    xlabel('temps en seconde') ;
    ylabel('distance en mètre');
    legend({'\u_dot','\v_dot','\w_dot'},'Location','northeast');

    % Afficher un second graphique en 3d
    figure
    plotTransforms(pose(1:10:end,:),quat(1:10:end,:),'InertialZDirection','Down');
    title('Pose en fonction du temps');
    xlabel('x en mètre') ;
    ylabel('y en mètre');
    set( hAxes, 'YDir', 'reverse' );
    zlabel('z en mètre');
    xlim([-1 18]);
    ylim([-9 9]);
    zlim([-5 0]);
end