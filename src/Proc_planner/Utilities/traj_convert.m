
for i =1 : max(size(newmsg.Pose))
fprintf("WPTS # %d :: Position { X: %d Y: %d Z: %d } Orientation { yaw : %d } \n",i, newmsg.Pose(i).Position.X,newmsg.Pose(i).Position.Y,newmsg.Pose(i).Position.Z,newmsg.Pose(i).Orientation.Z)
end

iquat= eul2quat(deg2rad([-135,0,0]),"ZYX");
icMsg = rosmessage('geometry_msgs/Pose',"DataFormat","struct"); % IC topic


icMsg.Orientation.W = iquat(1);
icMsg.Orientation.X = iquat(2);
icMsg.Orientation.Y = iquat(3);
icMsg.Orientation.Z = iquat(4);

icMsg.Position.Z = 0.3;
icMsg.Position.Y = 8;
icMsg.Position.X = 10;
param.ts = 0.1;
param.amax = 0.15;
param.vlmax = 0.8;
param.vamax = deg2rad(45);

TG = TrajectoryGenerator(newmsg,param,icMsg);
if TG.status
    test= TG.Compute(trajpub);
    Traj_viewer(test);
end