function slBusOut = KillSwitchMsg(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    slBusOut.State = logical(msgIn.State);
end
