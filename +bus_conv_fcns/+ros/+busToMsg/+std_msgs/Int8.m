function rosmsgOut = Int8(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.Data = int8(slBusIn.Data);
end
