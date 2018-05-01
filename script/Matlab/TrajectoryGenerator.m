timeStamp      = 0.1;
TrajectoryTime = 10;
responseTime   = TrajectoryTime / timeStamp;
startPose      = 0;
endPose        = 13;

pose         = startPose;
velocity     = 0;
acceleration = 0;
for i=1:(responseTime)
    pose         = [pose, poseTrajectory(i, startPose, endPose, responseTime)];
    velocity     = [velocity, velocityTrajectory(i, startPose, endPose, responseTime)];
    acceleration = [acceleration, accelarationTrajectory(i, startPose, endPose, responseTime)];
end

plot(pose)
figure
plot(velocity)
figure
plot(acceleration)


function y = poseTrajectory(t, P0, P1, timeResponse)
    spline_time_squared = t^2;
    spline_time_cubed   = t^3;
    t_f_squared = timeResponse^2;
    t_f_cubed   = timeResponse^3;
    
    y = P0 + (3 / t_f_squared) * (P1 - P0) * spline_time_squared + (-2 / t_f_cubed) * (P1 - P0) * spline_time_cubed;

end

function y = velocityTrajectory(t, P0, P1, timeResponse)
    spline_time         = t;
    spline_time_squared = t^2;
    t_f_squared = timeResponse^2;
    t_f_cubed   = timeResponse^3;
    
    y = 2 * (3 / t_f_squared) * (P1 - P0) * spline_time + 3 * (-2 / t_f_cubed) * (P1 - P0) * spline_time_squared;

end

function y = accelarationTrajectory(t, P0, P1, timeResponse)
    spline_time         = t;
    t_f_squared = timeResponse^2;
    t_f_cubed   = timeResponse^3;
    
    y = 2 * (3 / t_f_squared) * (P1 - P0) + 6 * (-2 / t_f_cubed) * (P1 - P0) * spline_time;

end