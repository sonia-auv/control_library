function slBusOut = BodyVelocityDVL(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    currentlength = length(slBusOut.Header);
    for iter=1:currentlength
        slBusOut.Header(iter) = bus_conv_fcns.ros.msgToBus.std_msgs.Header(msgIn.Header(iter),slBusOut(1).Header(iter),varargin{:});
    end
    slBusOut.Header = bus_conv_fcns.ros.msgToBus.std_msgs.Header(msgIn.Header,slBusOut(1).Header,varargin{:});
    slBusOut.XVelBtm = double(msgIn.XVelBtm);
    slBusOut.YVelBtm = double(msgIn.YVelBtm);
    slBusOut.ZVelBtm = double(msgIn.ZVelBtm);
    slBusOut.EVelBtm = double(msgIn.EVelBtm);
    slBusOut.Velocity1 = double(msgIn.Velocity1);
    slBusOut.Velocity2 = double(msgIn.Velocity2);
    slBusOut.Velocity3 = double(msgIn.Velocity3);
    slBusOut.Velocity4 = double(msgIn.Velocity4);
end
