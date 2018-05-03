AUV_MASS               = 49.5;
AUV_VOLUME             = 0.0405;
BUOYANCY_CENTER        = [0.0, 0.0, 0.0];
X_SURFACE              = 0.73 * 0.17;
Y_SURFACE              = X_SURFACE;
Z_SURFACE              = X_SURFACE + Y_SURFACE;
ROLL_SURFACE           = 0.0;
PITCH_SURFACE          = 0.0;
YAW_SURFACE            = 0.40 * 0.17;
GRAVITY                = AUV_MASS * 9.81;
BUOYANCY               = -AUV_VOLUME * 1000 * 9.81;
resultingForce         = GRAVITY + BUOYANCY;

ConstDragCoefficient   = [13.883160949; 10.6720508; 0.0; 0.0; 0.0; 7.8005317454];
QuadDragCoefficient    = [0.3853191662; 5.2749972475; 0.0; 0.0; 0.0; -12.4597949862];


add_mass_x     = AUV_VOLUME * 1000;   
add_mass_y     = AUV_VOLUME * 1000;    
add_mass_z     = AUV_VOLUME * 1000;    
add_mass_roll  = AUV_VOLUME * 1000; 
add_mass_pitch = AUV_VOLUME * 1000;
add_mass_yaw   = AUV_VOLUME * 1000;

x = [0 2];
y = [0 2];
xq = x(1):0.001:x(end);

px1 = spline(x,[0 y 0],xq);
px = px1(1, 3:length(px1));
py1 = spline(x,[0 y 0],xq);
py = py1(1, 3:length(py1));
pz1 = zeros(1,length(xq));
pz = pz1(1, 3:length(pz1));
pr1 = zeros(1,length(xq));
pr = pr1(1, 3:length(pr1));
pp1 = zeros(1,length(xq));
pp = pp1(1, 3:length(pp1));
ps1 = zeros(1,length(xq));
ps = ps1(1, 3:length(ps1));

vx1 = diff(px1);
vx = vx1(1, 2:length(vx1));
vy1 = diff(py1);
vy = vy1(1, 2:length(vy1));
vz1 = diff(pz1);
vz = vz1(1, 2:length(vz1));
vr1 = diff(pr1);
vr = vr1(1, 2:length(vr1));
vp1 = diff(pp1);
vp = vp1(1, 2:length(vp1));
vs1 = diff(ps1);
vs = vs1(1, 2:length(vs1));

ax = diff(vx1);
ay = diff(vy1);
az = diff(vz1);
ar = diff(vr1);
ap = diff(vp1);
as = diff(vs1);

figure
t  = 0:0.001:1.98;
length(ay)
plot(0:0.001:1.998, py)
figure
plot(0:0.001:1.998, vy)
figure
plot(0:0.001:1.998, ay)

AUVSurface = [[X_SURFACE, 0.0,       0.0,       0.0,          0.0,           0.0];
              [0.0,       Y_SURFACE, 0.0,       0.0,          0.0,           0.0];
              [0.0,       0.0,       Z_SURFACE, 0.0,          0.0,           0.0];
              [0.0,       0.0,       0.0,       ROLL_SURFACE, 0.0,           0.0];
              [0.0,       0.0,       0.0,       0.0,          PITCH_SURFACE, 0.0];
              [0.0,       0.0,       0.0,       0.0,          0.0,           YAW_SURFACE]];

               
AddedMassCoefficient = [[add_mass_x, 0.0,        0.0,        0.0,           0.0,            0.0];
                        [0.0,        add_mass_y, 0.0,        0.0,           0.0,            0.0];
                        [0.0,        0.0,        add_mass_z, 0.0,           0.0,            0.0];
                        [0.0,        0.0,        0.0,        add_mass_roll, 0.0,            0.0];
                        [0.0,        0.0,        0.0,        0.0,           add_mass_pitch, 0.0];
                        [0.0,        0.0,        0.0,        0.0,           0.0,            add_mass_yaw]];
                    
MassInertiaCoefficient = [[50, 0.0, 0.0, 0.0, 0.0, 0.0];
                          [0.0, 50, 0.0, 0.0, 0.0, 0.0];
                          [0.0, 0.0, 50, 0.0, 0.0, 0.0];
                          [0.0, 0.0, 0.0, 1.9, 0.0, 0.0];
                          [0.0, 0.0, 0.0, 0.0, 3.1, 0.0];
                          [0.0, 0.0, 0.0, 0.0, 0.0, 1.7]];
          
M = AddedMassCoefficient * MassInertiaCoefficient;
for i = 1:length(vx)
    velocity     = [vx(i);vy(i);vz(i);vr(i);vp(i);vs(i)];
    acceleration = [ax(i);ay(i);az(i);ar(i);ap(i);as(i)];
    position     = [px(i);py(i);pz(i)];
    orientation  = [pr(i);pr(i);ps(i)];
    
    D = ComputeDamping(ConstDragCoefficient, QuadDragCoefficient, velocity);
    G = ComputeGravityVector(resultingForce, BUOYANCY, BUOYANCY_CENTER, orientation);

    T = M * acceleration + D .* velocity + G;
    
    TTx(i) = T(1);
    TTy(i) = T(2);
    TTz(i) = T(3);
    
end

figure
hold on          % plot against left y-axis 
plot(0:0.001:1.998, TTx) 
plot(0:0.001:1.998, TTy)



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


