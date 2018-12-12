
function [pose, velocity, acceleration] = TrajectoryGenerator()
    timeStamp      = 0.02;
    TrajectoryTime = 4;
    responseTime   = TrajectoryTime / timeStamp;
    startPose      = 0;
    endPose        = 1;

    i = 1;
    for t=0:(responseTime)
        j = t * timeStamp;
        pose(i)         = poseTrajectory(j, startPose, endPose, TrajectoryTime);
        velocity(i)     = velocityTrajectory(j, startPose, endPose, TrajectoryTime);
        acceleration(i) = accelarationTrajectory(j, startPose, endPose, TrajectoryTime);
        i = i + 1;
    end
end


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
