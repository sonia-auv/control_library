function slBusOut = UInt8(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    slBusOut.Data = uint8(msgIn.Data);
end
