function rosmsgOut = Imu(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.Header = bus_conv_fcns.ros.busToMsg.std_msgs.Header(slBusIn.Header,rosmsgOut.Header(1));
    rosmsgOut.Orientation = bus_conv_fcns.ros.busToMsg.geometry_msgs.Quaternion(slBusIn.Orientation,rosmsgOut.Orientation(1));
    rosmsgOut.OrientationCovariance = double(slBusIn.OrientationCovariance);
    rosmsgOut.AngularVelocity = bus_conv_fcns.ros.busToMsg.geometry_msgs.Vector3(slBusIn.AngularVelocity,rosmsgOut.AngularVelocity(1));
    rosmsgOut.AngularVelocityCovariance = double(slBusIn.AngularVelocityCovariance);
    rosmsgOut.LinearAcceleration = bus_conv_fcns.ros.busToMsg.geometry_msgs.Vector3(slBusIn.LinearAcceleration,rosmsgOut.LinearAcceleration(1));
    rosmsgOut.LinearAccelerationCovariance = double(slBusIn.LinearAccelerationCovariance);
end
