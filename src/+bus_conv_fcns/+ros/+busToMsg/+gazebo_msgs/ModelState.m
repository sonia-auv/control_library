function rosmsgOut = ModelState(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.ModelName = char(slBusIn.ModelName);
    if slBusIn.ModelName_SL_Info.CurrentLength < numel(slBusIn.ModelName)
    rosmsgOut.ModelName(slBusIn.ModelName_SL_Info.CurrentLength+1:numel(slBusIn.ModelName)) = [];
    end
    rosmsgOut.Pose = bus_conv_fcns.ros.busToMsg.geometry_msgs.Pose(slBusIn.Pose,rosmsgOut.Pose(1));
    rosmsgOut.Twist = bus_conv_fcns.ros.busToMsg.geometry_msgs.Twist(slBusIn.Twist,rosmsgOut.Twist(1));
    rosmsgOut.ReferenceFrame = char(slBusIn.ReferenceFrame);
    if slBusIn.ReferenceFrame_SL_Info.CurrentLength < numel(slBusIn.ReferenceFrame)
    rosmsgOut.ReferenceFrame(slBusIn.ReferenceFrame_SL_Info.CurrentLength+1:numel(slBusIn.ReferenceFrame)) = [];
    end
end
