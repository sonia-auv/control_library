function rosmsgOut = MultiArrayLayout(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.Dim = ros.slroscpp.internal.bus.Util.newMessageFromSimulinkMsgType('std_msgs/MultiArrayDimension');
    for iter=1:slBusIn.Dim_SL_Info.CurrentLength
        rosmsgOut.Dim(iter) = bus_conv_fcns.ros.busToMsg.std_msgs.MultiArrayDimension(slBusIn.Dim(iter),rosmsgOut.Dim(1));
    end
    if slBusIn.Dim_SL_Info.CurrentLength < numel(rosmsgOut.Dim)
    rosmsgOut.Dim(slBusIn.Dim_SL_Info.CurrentLength+1:numel(rosmsgOut.Dim)) = [];
    end
    rosmsgOut.DataOffset = uint32(slBusIn.DataOffset);
end
