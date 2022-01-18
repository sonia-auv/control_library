function rosmsgOut = TwistWithCovariance(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.Twist = bus_conv_fcns.ros.busToMsg.geometry_msgs.Twist(slBusIn.Twist,rosmsgOut.Twist(1));
    rosmsgOut.Covariance = double(slBusIn.Covariance);
end
