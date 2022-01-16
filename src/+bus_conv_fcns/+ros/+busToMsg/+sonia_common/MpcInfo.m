function rosmsgOut = MpcInfo(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.IsMpcAlive = logical(slBusIn.IsMpcAlive);
    rosmsgOut.TargetReached = logical(slBusIn.TargetReached);
    rosmsgOut.ThrustersStatus = logical(slBusIn.ThrustersStatus(1:slBusIn.ThrustersStatus_SL_Info.CurrentLength));
    rosmsgOut.MpcStatus = int8(slBusIn.MpcStatus);
    rosmsgOut.MpcMode = uint8(slBusIn.MpcMode);
    rosmsgOut.CurrentGains = bus_conv_fcns.ros.busToMsg.sonia_common.MpcGains(slBusIn.CurrentGains,rosmsgOut.CurrentGains(1));
end
