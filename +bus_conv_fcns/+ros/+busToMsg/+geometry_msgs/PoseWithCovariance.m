function rosmsgOut = PoseWithCovariance(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.Pose = bus_conv_fcns.ros.busToMsg.geometry_msgs.Pose(slBusIn.Pose,rosmsgOut.Pose(1));
    rosmsgOut.Covariance = double(slBusIn.Covariance);
end
