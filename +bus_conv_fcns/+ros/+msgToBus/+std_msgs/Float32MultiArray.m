function slBusOut = Float32MultiArray(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    currentlength = length(slBusOut.Layout);
    for iter=1:currentlength
        slBusOut.Layout(iter) = bus_conv_fcns.ros.msgToBus.std_msgs.MultiArrayLayout(msgIn.Layout(iter),slBusOut(1).Layout(iter),varargin{:});
    end
    slBusOut.Layout = bus_conv_fcns.ros.msgToBus.std_msgs.MultiArrayLayout(msgIn.Layout,slBusOut(1).Layout,varargin{:});
    maxlength = length(slBusOut.Data);
    recvdlength = length(msgIn.Data);
    currentlength = min(maxlength, recvdlength);
    if (max(recvdlength) > maxlength) && ...
            isequal(varargin{1}{1},ros.slros.internal.bus.VarLenArrayTruncationAction.EmitWarning)
        diag = MSLDiagnostic([], ...
                             message('ros:slros:busconvert:TruncatedArray', ...
                                     'Data', msgIn.MessageType, maxlength, max(recvdlength), maxlength, varargin{2}));
        reportAsWarning(diag);
    end
    slBusOut.Data_SL_Info.ReceivedLength = uint32(recvdlength);
    slBusOut.Data_SL_Info.CurrentLength = uint32(currentlength);
    slBusOut.Data = single(msgIn.Data(1:slBusOut.Data_SL_Info.CurrentLength));
    if recvdlength < maxlength
    slBusOut.Data(recvdlength+1:maxlength) = 0;
    end
end
