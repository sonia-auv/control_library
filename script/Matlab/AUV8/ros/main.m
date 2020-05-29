clc;
clear;

%rosshutdown
%rosinit();

rate = rosrate(1);

node = ProcControlNode();

while(true)
   node.spinOnce();
   waitfor(rate);
end

