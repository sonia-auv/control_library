function mpcParamsBus() 
% MPCPARAMSBUS initializes a set of bus objects in the MATLAB base workspace 

% Bus object: C10 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'OV';
elems(1).Dimensions = [1 13];
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'double';
elems(1).Complexity = 'real';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

elems(2) = Simulink.BusElement;
elems(2).Name = 'MV';
elems(2).Dimensions = [1 8];
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'double';
elems(2).Complexity = 'real';
elems(2).Min = [];
elems(2).Max = [];
elems(2).DocUnits = '';
elems(2).Description = '';

elems(3) = Simulink.BusElement;
elems(3).Name = 'MVR';
elems(3).Dimensions = [1 8];
elems(3).DimensionsMode = 'Fixed';
elems(3).DataType = 'double';
elems(3).Complexity = 'real';
elems(3).Min = [];
elems(3).Max = [];
elems(3).DocUnits = '';
elems(3).Description = '';

C10 = Simulink.Bus;
C10.HeaderFile = '';
C10.Description = '';
C10.DataScope = 'Auto';
C10.Alignment = -1;
C10.PreserveElementDimensions = 0;
C10.Elements = elems;
clear elems;
assignin('base','C10', C10);

% Bus object: C11 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'OV';
elems(1).Dimensions = [1 13];
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'double';
elems(1).Complexity = 'real';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

elems(2) = Simulink.BusElement;
elems(2).Name = 'MV';
elems(2).Dimensions = [1 8];
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'double';
elems(2).Complexity = 'real';
elems(2).Min = [];
elems(2).Max = [];
elems(2).DocUnits = '';
elems(2).Description = '';

elems(3) = Simulink.BusElement;
elems(3).Name = 'MVR';
elems(3).Dimensions = [1 8];
elems(3).DimensionsMode = 'Fixed';
elems(3).DataType = 'double';
elems(3).Complexity = 'real';
elems(3).Min = [];
elems(3).Max = [];
elems(3).DocUnits = '';
elems(3).Description = '';

C11 = Simulink.Bus;
C11.HeaderFile = '';
C11.Description = '';
C11.DataScope = 'Auto';
C11.Alignment = -1;
C11.PreserveElementDimensions = 0;
C11.Elements = elems;
clear elems;
assignin('base','C11', C11);

% Bus object: C19 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'OV';
elems(1).Dimensions = [1 13];
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'double';
elems(1).Complexity = 'real';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

elems(2) = Simulink.BusElement;
elems(2).Name = 'MV';
elems(2).Dimensions = [1 8];
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'double';
elems(2).Complexity = 'real';
elems(2).Min = [];
elems(2).Max = [];
elems(2).DocUnits = '';
elems(2).Description = '';

elems(3) = Simulink.BusElement;
elems(3).Name = 'MVR';
elems(3).Dimensions = [1 8];
elems(3).DimensionsMode = 'Fixed';
elems(3).DataType = 'double';
elems(3).Complexity = 'real';
elems(3).Min = [];
elems(3).Max = [];
elems(3).DocUnits = '';
elems(3).Description = '';

C19 = Simulink.Bus;
C19.HeaderFile = '';
C19.Description = '';
C19.DataScope = 'Auto';
C19.Alignment = -1;
C19.PreserveElementDimensions = 0;
C19.Elements = elems;
clear elems;
assignin('base','C19', C19);

% Bus object: Defaut 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'OV';
elems(1).Dimensions = [1 13];
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'double';
elems(1).Complexity = 'real';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

elems(2) = Simulink.BusElement;
elems(2).Name = 'MV';
elems(2).Dimensions = [1 8];
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'double';
elems(2).Complexity = 'real';
elems(2).Min = [];
elems(2).Max = [];
elems(2).DocUnits = '';
elems(2).Description = '';

elems(3) = Simulink.BusElement;
elems(3).Name = 'MVR';
elems(3).Dimensions = [1 8];
elems(3).DimensionsMode = 'Fixed';
elems(3).DataType = 'double';
elems(3).Complexity = 'real';
elems(3).Min = [];
elems(3).Max = [];
elems(3).DocUnits = '';
elems(3).Description = '';

Defaut = Simulink.Bus;
Defaut.HeaderFile = '';
Defaut.Description = '';
Defaut.DataScope = 'Auto';
Defaut.Alignment = -1;
Defaut.PreserveElementDimensions = 0;
Defaut.Elements = elems;
clear elems;
assignin('base','Defaut', Defaut);

% Bus object: Gains 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'defaut';
elems(1).Dimensions = 1;
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'Defaut';
elems(1).Complexity = 'real';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

elems(2) = Simulink.BusElement;
elems(2).Name = 'c10';
elems(2).Dimensions = 1;
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'C10';
elems(2).Complexity = 'real';
elems(2).Min = [];
elems(2).Max = [];
elems(2).DocUnits = '';
elems(2).Description = '';

elems(3) = Simulink.BusElement;
elems(3).Name = 'c11';
elems(3).Dimensions = 1;
elems(3).DimensionsMode = 'Fixed';
elems(3).DataType = 'C11';
elems(3).Complexity = 'real';
elems(3).Min = [];
elems(3).Max = [];
elems(3).DocUnits = '';
elems(3).Description = '';

elems(4) = Simulink.BusElement;
elems(4).Name = 'c19';
elems(4).Dimensions = 1;
elems(4).DimensionsMode = 'Fixed';
elems(4).DataType = 'C19';
elems(4).Complexity = 'real';
elems(4).Min = [];
elems(4).Max = [];
elems(4).DocUnits = '';
elems(4).Description = '';

elems(5) = Simulink.BusElement;
elems(5).Name = 'noDvl';
elems(5).Dimensions = 1;
elems(5).DimensionsMode = 'Fixed';
elems(5).DataType = 'NoDvl';
elems(5).Complexity = 'real';
elems(5).Min = [];
elems(5).Max = [];
elems(5).DocUnits = '';
elems(5).Description = '';

Gains = Simulink.Bus;
Gains.HeaderFile = '';
Gains.Description = '';
Gains.DataScope = 'Auto';
Gains.Alignment = -1;
Gains.PreserveElementDimensions = 0;
Gains.Elements = elems;
clear elems;
assignin('base','Gains', Gains);

% Bus object: NoDvl 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'MV';
elems(1).Dimensions = [1 8];
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'double';
elems(1).Complexity = 'real';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

NoDvl = Simulink.Bus;
NoDvl.HeaderFile = '';
NoDvl.Description = '';
NoDvl.DataScope = 'Auto';
NoDvl.Alignment = -1;
NoDvl.PreserveElementDimensions = 0;
NoDvl.Elements = elems;
clear elems;
assignin('base','NoDvl', NoDvl);

% Bus object: TargetReached 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'linearTol';
elems(1).Dimensions = [1 1];
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'double';
elems(1).Complexity = 'real';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

elems(2) = Simulink.BusElement;
elems(2).Name = 'angularTol';
elems(2).Dimensions = [1 1];
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'double';
elems(2).Complexity = 'real';
elems(2).Min = [];
elems(2).Max = [];
elems(2).DocUnits = '';
elems(2).Description = '';

elems(3) = Simulink.BusElement;
elems(3).Name = 'timeInTol';
elems(3).Dimensions = [1 1];
elems(3).DimensionsMode = 'Fixed';
elems(3).DataType = 'double';
elems(3).Complexity = 'real';
elems(3).Min = [];
elems(3).Max = [];
elems(3).DocUnits = '';
elems(3).Description = '';

TargetReached = Simulink.Bus;
TargetReached.HeaderFile = '';
TargetReached.Description = '';
TargetReached.DataScope = 'Auto';
TargetReached.Alignment = -1;
TargetReached.PreserveElementDimensions = 0;
TargetReached.Elements = elems;
clear elems;
assignin('base','TargetReached', TargetReached);

% Bus object: mpcParams 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'gains';
elems(1).Dimensions = 1;
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'Gains';
elems(1).Complexity = 'real';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

elems(2) = Simulink.BusElement;
elems(2).Name = 'targetReached';
elems(2).Dimensions = 1;
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'TargetReached';
elems(2).Complexity = 'real';
elems(2).Min = [];
elems(2).Max = [];
elems(2).DocUnits = '';
elems(2).Description = '';

mpcParams = Simulink.Bus;
mpcParams.HeaderFile = '';
mpcParams.Description = '';
mpcParams.DataScope = 'Auto';
mpcParams.Alignment = -1;
mpcParams.PreserveElementDimensions = 0;
mpcParams.Elements = elems;
clear elems;
assignin('base','mpcParams', mpcParams);

