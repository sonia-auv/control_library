function slBusOut = MultiArrayDimension(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    slBusOut.Label_SL_Info.ReceivedLength = uint32(strlength(msgIn.Label));
    currlen  = min(slBusOut.Label_SL_Info.ReceivedLength, length(slBusOut.Label));
    slBusOut.Label_SL_Info.CurrentLength = uint32(currlen);
    slBusOut.Label(1:currlen) = uint8(char(msgIn.Label(1:currlen))).';
    slBusOut.Size = uint32(msgIn.Size);
    slBusOut.Stride = uint32(msgIn.Stride);
end
