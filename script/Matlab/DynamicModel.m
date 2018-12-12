function T = DynamicModel(acceleration, velocity, orientation)
    AUV_MASS               = 50.0;
    AUV_VOLUME             = 0.04949949;
    BUOYANCY_CENTER        = [0.0, 0.0, 0.0];
    X_SURFACE              = 0.73 * 0.17;
    Y_SURFACE              = X_SURFACE;
    Z_SURFACE              = X_SURFACE + Y_SURFACE;
    ROLL_SURFACE           = 0.0;
    PITCH_SURFACE          = 0.0;
    YAW_SURFACE            = 0.40 * 0.17;
    GRAVITY                = AUV_MASS * 9.81;
    BUOYANCY               = -AUV_VOLUME * 1025 * 9.81;
    resultingForce         = GRAVITY + BUOYANCY;

    ConstDragCoefficient   = [136.1473; 104.6571; 0.0; 0.0; 0.0; 76.4971];
    QuadDragCoefficient    = [3.7787; 51.7301; 0.0; 0.0; 0.0; -122.1888];
                    
    MassInertiaCoefficient = [[50, 0.0, 0.0, 0.0, 0.0, 0.0];
                             [0.0, 50, 0.0, 0.0, 0.0, 0.0];
                             [0.0, 0.0, 50, 0.0, 0.0, 0.0];
                             [0.0, 0.0, 0.0, 1.9, 0.0, 0.0];
                             [0.0, 0.0, 0.0, 0.0, 3.1, 0.0];
                             [0.0, 0.0, 0.0, 0.0, 0.0, 1.7]];
          
    M = MassInertiaCoefficient;    
    D = ComputeDamping(ConstDragCoefficient, QuadDragCoefficient, velocity);
    G = ComputeGravityVector(resultingForce, BUOYANCY, BUOYANCY_CENTER, orientation);

    T = M * acceleration + D .* velocity + G;
    
end

function GravityVectorT = ComputeGravityVector(resultingForce, Buoyancy, buoyancy_center, orientation)
        GravityVector(1) = resultingForce  * sin(orientation(2));
        GravityVector(2) = -resultingForce * sin(orientation(1)) * cos(orientation(2));
        GravityVector(3) = -resultingForce * cos(orientation(1)) * cos(orientation(2));

        GravityVector(4) = Buoyancy  * cos(orientation(2)) * (buoyancy_center(3) * sin(orientation(1)) - buoyancy_center(2) * cos(orientation(1)));
        GravityVector(5) = Buoyancy  * (buoyancy_center(1) * cos(orientation(1)) * cos(orientation(2)) - buoyancy_center(3) * sin(orientation(2)));
        GravityVector(6) = -Buoyancy * (buoyancy_center(1) * sin(orientation(1)) * cos(orientation(2)) - buoyancy_center(2) * sin(orientation(2)));
        GravityVectorT = [GravityVector(1);GravityVector(2);GravityVector(3);GravityVector(4);GravityVector(5);GravityVector(6)];
end

function Damping = ComputeDamping(ConstDragCoefficient, QuadDragCoefficient, Velocity)
    
    Damping = ConstDragCoefficient + QuadDragCoefficient .* (Velocity .* Velocity);
    
end


