trajpub = rospublisher('/proc_planner/send_trajectory_list','trajectory_msgs/MultiDOFJointTrajectoryPoint',"DataFormat","struct");
pospub = rospublisher('/proc_planner/send_multi_addpose','sonia_common/MultiAddPose',"DataFormat","struct");


for i =1 : max(size(newmsg.Pose))
fprintf("WPTS # %d :: Position { X: %d Y: %d Z: %d } Orientation { yaw : %d } \n",i, newmsg.Pose(i).Position.X,newmsg.Pose(i).Position.Y,newmsg.Pose(i).Position.Z,newmsg.Pose(i).Orientation.Z)
newmsg.Pose(i).Frame = uint8(newmsg.Pose(i).Frame);
newmsg.Pose(i).Speed = uint8(0);
newmsg.Pose(i).Rotation = logical(newmsg.Pose(i).Rotation);

end


newmsg.InterpolationMethod =uint8(1);

iquat= eul2quat(deg2rad([180,0,0]),"ZYX");
icMsg = rosmessage('geometry_msgs/Pose',"DataFormat","struct"); % IC topic

send(pospub,newmsg);
icMsg.Orientation.W = iquat(1);
icMsg.Orientation.X = iquat(2);
icMsg.Orientation.Y = iquat(3);
icMsg.Orientation.Z = iquat(4);

icMsg.Position.Z = 0.5;
icMsg.Position.Y = 0;
icMsg.Position.X = 0;
param.ts = 0.1;

param.lowSpeed.amax = 0.05;
param.lowSpeed.vlmax = 0.2;
param.lowSpeed.vamax = 0.3;

param.normalSpeed.amax = 0.1;
param.normalSpeed.vlmax = 0.5;
param.normalSpeed.vamax = 0.5;

param.highSpeed.amax = 0.15;
param.highSpeed.vlmax = 0.8;
param.highSpeed.vamax = 0.8;

TG = TrajectoryGenerator(newmsg,param,icMsg);
if TG.status == TG.RECIEVED_VALID_WAYPTS
    test= TG.Compute(trajpub);
    send(trajpub,test);
    Traj_viewer(test);
end