function slBusOut = AddPose(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    currentlength = length(slBusOut.Position);
    for iter=1:currentlength
        slBusOut.Position(iter) = bus_conv_fcns.ros.msgToBus.geometry_msgs.Point(msgIn.Position(iter),slBusOut(1).Position(iter),varargin{:});
    end
    slBusOut.Position = bus_conv_fcns.ros.msgToBus.geometry_msgs.Point(msgIn.Position,slBusOut(1).Position,varargin{:});
    currentlength = length(slBusOut.Orientation);
    for iter=1:currentlength
        slBusOut.Orientation(iter) = bus_conv_fcns.ros.msgToBus.geometry_msgs.Vector3(msgIn.Orientation(iter),slBusOut(1).Orientation(iter),varargin{:});
    end
    slBusOut.Orientation = bus_conv_fcns.ros.msgToBus.geometry_msgs.Vector3(msgIn.Orientation,slBusOut(1).Orientation,varargin{:});
    slBusOut.Frame = uint8(msgIn.Frame);
    slBusOut.Speed = uint8(msgIn.Speed);
    slBusOut.Fine = double(msgIn.Fine);
    slBusOut.Rotation = logical(msgIn.Rotation);
end
