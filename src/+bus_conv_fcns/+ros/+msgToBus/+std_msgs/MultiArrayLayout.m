function slBusOut = MultiArrayLayout(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    maxlength = length(slBusOut.Dim);
    recvdlength = length(msgIn.Dim);
    currentlength = min(maxlength, recvdlength);
    if (max(recvdlength) > maxlength) && ...
            isequal(varargin{1}{1},ros.slros.internal.bus.VarLenArrayTruncationAction.EmitWarning)
        diag = MSLDiagnostic([], ...
                             message('ros:slros:busconvert:TruncatedArray', ...
                                     'Dim', msgIn.MessageType, maxlength, max(recvdlength), maxlength, varargin{2}));
        reportAsWarning(diag);
    end
    slBusOut.Dim_SL_Info.ReceivedLength = uint32(recvdlength);
    slBusOut.Dim_SL_Info.CurrentLength = uint32(currentlength);
    for iter=1:currentlength
        slBusOut.Dim(iter) = bus_conv_fcns.ros.msgToBus.std_msgs.MultiArrayDimension(msgIn.Dim(iter),slBusOut(1).Dim(iter),varargin{:});
    end
    slBusOut.DataOffset = uint32(msgIn.DataOffset);
end
