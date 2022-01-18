function rosmsgOut = MpcGains(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.OV = double(slBusIn.OV(1:slBusIn.OV_SL_Info.CurrentLength));
    rosmsgOut.MV = double(slBusIn.MV(1:slBusIn.MV_SL_Info.CurrentLength));
    rosmsgOut.MVR = double(slBusIn.MVR(1:slBusIn.MVR_SL_Info.CurrentLength));
    rosmsgOut.MaxThrust = double(slBusIn.MaxThrust);
    rosmsgOut.MinThrust = double(slBusIn.MinThrust);
end
