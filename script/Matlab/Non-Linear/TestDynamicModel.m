[p, v, a] = TrajectoryGenerator();
for i = 1:length(v)
    velocity     = [v(i);v(i);0;0;0;v(i)];
    acceleration = [a(i);a(i);0;0;0;a(i)];
    orientation  = [0;0;p(i)];

    T = DynamicModel(acceleration, velocity, orientation);
    
    TTx(i)  = T(1);
    TTy(i)  = T(2);
    TTz(i)  = T(3);
    TTyaw(i) = T(6);
    
end

figure% plot against left y-axis 
hold on
plot(TTx) 
plot(TTyaw) 
title('Wrench')
figure
plot(v)
title('Velocity')