function rosmsgOut = MultiArrayDimension(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.Label = char(slBusIn.Label);
    if slBusIn.Label_SL_Info.CurrentLength < numel(slBusIn.Label)
    rosmsgOut.Label(slBusIn.Label_SL_Info.CurrentLength+1:numel(slBusIn.Label)) = [];
    end
    rosmsgOut.Size = uint32(slBusIn.Size);
    rosmsgOut.Stride = uint32(slBusIn.Stride);
end
