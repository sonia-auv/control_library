function rosmsgOut = Bool(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.Data = logical(slBusIn.Data);
end
