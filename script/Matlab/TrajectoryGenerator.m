timeStamp      = 0.1;
TrajectoryTime = 11;
responseTime   = TrajectoryTime / timeStamp;
startPose      = 0;
endPose        = 13;

q0 = eul2quat([0, 0, 0]);
q1 = eul2quat([30, 0, 0]);

pose         = startPose;
velocity     = 0;
acceleration = 0;
orientation  = 0;
for i=1:(responseTime)
    pose         = [pose, poseTrajectory(i, startPose, endPose, responseTime)];
    velocity     = [velocity, velocityTrajectory(i, startPose, endPose, responseTime)];
    acceleration = [acceleration, accelarationTrajectory_(i, startPose, endPose, responseTime)];
end

for i=0:10
    i = i / 10
    orientation  = [orientation, quatinterp(q0,q1,0.5,'slerp')];
    
end

plot(orientation)
%figure
%plot(pose)
%figure
%plot(velocity)
%figure
%plot(acceleration)


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

function y = accelarationTrajectory_(t, P0, P1, timeResponse)
    spline_time         = t;
    t_f_squared = timeResponse^2;
    t_f_cubed   = timeResponse^3;
    
    y = 2 * (3 / t_f_squared) * (P1 - P0) + 6 * (-2 / t_f_cubed) * (P1 - P0) * spline_time;

end

function y = PositionOrientation(t, q1, q0)
    w = 1;
    y = (q0 * sin((1 - t) * w) + q1 * sin(t * w)) / sin(w);
end



