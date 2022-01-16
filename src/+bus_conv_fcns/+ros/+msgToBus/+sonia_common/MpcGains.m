function slBusOut = MpcGains(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    maxlength = length(slBusOut.OV);
    recvdlength = length(msgIn.OV);
    currentlength = min(maxlength, recvdlength);
    if (max(recvdlength) > maxlength) && ...
            isequal(varargin{1}{1},ros.slros.internal.bus.VarLenArrayTruncationAction.EmitWarning)
        diag = MSLDiagnostic([], ...
                             message('ros:slros:busconvert:TruncatedArray', ...
                                     'OV', msgIn.MessageType, maxlength, max(recvdlength), maxlength, varargin{2}));
        reportAsWarning(diag);
    end
    slBusOut.OV_SL_Info.ReceivedLength = uint32(recvdlength);
    slBusOut.OV_SL_Info.CurrentLength = uint32(currentlength);
    slBusOut.OV = double(msgIn.OV(1:slBusOut.OV_SL_Info.CurrentLength));
    if recvdlength < maxlength
    slBusOut.OV(recvdlength+1:maxlength) = 0;
    end
    maxlength = length(slBusOut.MV);
    recvdlength = length(msgIn.MV);
    currentlength = min(maxlength, recvdlength);
    if (max(recvdlength) > maxlength) && ...
            isequal(varargin{1}{1},ros.slros.internal.bus.VarLenArrayTruncationAction.EmitWarning)
        diag = MSLDiagnostic([], ...
                             message('ros:slros:busconvert:TruncatedArray', ...
                                     'MV', msgIn.MessageType, maxlength, max(recvdlength), maxlength, varargin{2}));
        reportAsWarning(diag);
    end
    slBusOut.MV_SL_Info.ReceivedLength = uint32(recvdlength);
    slBusOut.MV_SL_Info.CurrentLength = uint32(currentlength);
    slBusOut.MV = double(msgIn.MV(1:slBusOut.MV_SL_Info.CurrentLength));
    if recvdlength < maxlength
    slBusOut.MV(recvdlength+1:maxlength) = 0;
    end
    maxlength = length(slBusOut.MVR);
    recvdlength = length(msgIn.MVR);
    currentlength = min(maxlength, recvdlength);
    if (max(recvdlength) > maxlength) && ...
            isequal(varargin{1}{1},ros.slros.internal.bus.VarLenArrayTruncationAction.EmitWarning)
        diag = MSLDiagnostic([], ...
                             message('ros:slros:busconvert:TruncatedArray', ...
                                     'MVR', msgIn.MessageType, maxlength, max(recvdlength), maxlength, varargin{2}));
        reportAsWarning(diag);
    end
    slBusOut.MVR_SL_Info.ReceivedLength = uint32(recvdlength);
    slBusOut.MVR_SL_Info.CurrentLength = uint32(currentlength);
    slBusOut.MVR = double(msgIn.MVR(1:slBusOut.MVR_SL_Info.CurrentLength));
    if recvdlength < maxlength
    slBusOut.MVR(recvdlength+1:maxlength) = 0;
    end
    slBusOut.MaxThrust = double(msgIn.MaxThrust);
    slBusOut.MinThrust = double(msgIn.MinThrust);
end
