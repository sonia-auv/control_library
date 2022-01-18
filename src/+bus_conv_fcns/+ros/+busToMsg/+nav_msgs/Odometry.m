function rosmsgOut = Odometry(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.Header = bus_conv_fcns.ros.busToMsg.std_msgs.Header(slBusIn.Header,rosmsgOut.Header(1));
    rosmsgOut.ChildFrameId = char(slBusIn.ChildFrameId);
    if slBusIn.ChildFrameId_SL_Info.CurrentLength < numel(slBusIn.ChildFrameId)
    rosmsgOut.ChildFrameId(slBusIn.ChildFrameId_SL_Info.CurrentLength+1:numel(slBusIn.ChildFrameId)) = [];
    end
    rosmsgOut.Pose = bus_conv_fcns.ros.busToMsg.geometry_msgs.PoseWithCovariance(slBusIn.Pose,rosmsgOut.Pose(1));
    rosmsgOut.Twist = bus_conv_fcns.ros.busToMsg.geometry_msgs.TwistWithCovariance(slBusIn.Twist,rosmsgOut.Twist(1));
end
