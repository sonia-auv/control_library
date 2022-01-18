function rosmsgOut = BodyVelocityDVL(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.Header = bus_conv_fcns.ros.busToMsg.std_msgs.Header(slBusIn.Header,rosmsgOut.Header(1));
    rosmsgOut.XVelBtm = double(slBusIn.XVelBtm);
    rosmsgOut.YVelBtm = double(slBusIn.YVelBtm);
    rosmsgOut.ZVelBtm = double(slBusIn.ZVelBtm);
    rosmsgOut.EVelBtm = double(slBusIn.EVelBtm);
    rosmsgOut.Velocity1 = double(slBusIn.Velocity1);
    rosmsgOut.Velocity2 = double(slBusIn.Velocity2);
    rosmsgOut.Velocity3 = double(slBusIn.Velocity3);
    rosmsgOut.Velocity4 = double(slBusIn.Velocity4);
end
