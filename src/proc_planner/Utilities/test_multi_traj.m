
trajpub = rospublisher('/proc_planner/send_trajectory_list','trajectory_msgs/MultiDOFJointTrajectoryPoint',"DataFormat","struct");
icpub = rospublisher("proc_planner/initial_pose","geometry_msgs/Pose","DataFormat","struct");
addposemsg = rosmessage('sonia_common/AddPose',"DataFormat","struct");
Maddposemsg = rosmessage('sonia_common/MultiAddPose',"DataFormat","struct");
rMaddposemsg = rosmessage('sonia_common/MultiAddPose',"DataFormat","struct");
pospub = rospublisher('/proc_planner/send_multi_addpose','sonia_common/MultiAddPose',"DataFormat","struct");

mapSub = rossubscriber('/proc_planner/madpos','sonia_common/MultiAddPose',"DataFormat","struct");

tt= mapSub.LatestMessage;
icMsg = rosmessage('geometry_msgs/Pose',"DataFormat","struct"); % IC topic
icMsg.Position.X =0;
icMsg.Position.Y =0;
icMsg.Orientation.W = 1;
send(icpub,icMsg);

param.ts = 0.1;

param.lowSpeed.amax = 0.005;
param.lowSpeed.vlmax = 0.2;
param.lowSpeed.vamax = 0.3;

param.normalSpeed.amax = 0.01;
param.normalSpeed.vlmax = 0.5;
param.normalSpeed.vamax = 0.5;

param.highSpeed.amax = 0.015;
param.highSpeed.vlmax = 0.8;
param.highSpeed.vamax = 0.8;

% WayPts 2
addposemsg.Position.X = 0;
addposemsg.Position.Y = 0;
addposemsg.Position.Z = 1.5;
addposemsg.Orientation.X =0 ;
addposemsg.Orientation.Y =0 ;
addposemsg.Orientation.Z =0 ;
addposemsg.Frame = uint8(0);
addposemsg.Speed = uint8(1);

Maddposemsg.Pose =addposemsg;

% WayPts 3
addposemsg.Position.X = 0.5 ;
addposemsg.Position.Y = 0;
addposemsg.Position.Z = 2;

addposemsg.Orientation.X =0 ;
addposemsg.Orientation.Y =0 ;
addposemsg.Orientation.Z =0 ;
addposemsg.Frame = uint8(0);
addposemsg.Speed = uint8(2);

Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg];




Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg];
% WayPts 4
addposemsg.Position.X = 9 ;
addposemsg.Position.Y = 0;
addposemsg.Position.Z = 2;
addposemsg.Orientation.X =0 ;
addposemsg.Orientation.Y =0 ;
addposemsg.Orientation.Z = -40 ;
addposemsg.Frame = uint8(0);
addposemsg.Speed = uint8(2);
addposemsg.Fine = 3;
Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg];

% WayPts 6
addposemsg.Position.X = 13 ;
addposemsg.Position.Y = -1.75;
addposemsg.Position.Z = 1.5;
addposemsg.Orientation.X =0 ;
addposemsg.Orientation.Y =0 ;
addposemsg.Orientation.Z =0 ;
addposemsg.Frame = uint8(0);
addposemsg.Speed = uint8(2);
addposemsg.Fine = 0;
Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg];

% WayPts 8
addposemsg.Position.X = 14.721 ;
addposemsg.Position.Y = 0;
addposemsg.Position.Z = 1.186;
addposemsg.Orientation.X =0 ;
addposemsg.Orientation.Y =0 ;
addposemsg.Orientation.Z =90 ;
addposemsg.Frame = uint8(0);
addposemsg.Speed = uint8(2);
Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg];


% WayPts 10
addposemsg.Position.X = 13 ;
addposemsg.Position.Y = 1.75;
addposemsg.Position.Z = 1.5;
addposemsg.Orientation.X =0 ;
addposemsg.Orientation.Y =0 ;
addposemsg.Orientation.Z = 180 ;
addposemsg.Frame = uint8(0);
addposemsg.Speed = uint8(2);
Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg];


% WayPts 11
addposemsg.Position.X = 11.921 ;
addposemsg.Position.Y = 1.364;
addposemsg.Position.Z = 1.696;
addposemsg.Orientation.X = 0 ;
addposemsg.Orientation.Y = 0 ;
addposemsg.Orientation.Z = -(180-39.23) ;
addposemsg.Frame = uint8(0);
addposemsg.Speed = uint8(2);
Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg];

% WayPts 12
addposemsg.Position.X = 8.072 ;
addposemsg.Position.Y = 0;
addposemsg.Position.Z = 2;
addposemsg.Orientation.X =0 ;
addposemsg.Orientation.Y =0 ;
addposemsg.Orientation.Z = 180;
addposemsg.Frame = uint8(0);
addposemsg.Speed = uint8(2);
Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg];

% WayPts 12
addposemsg.Position.X = 6 ;
addposemsg.Position.Y = 0;
addposemsg.Position.Z = 2;
addposemsg.Orientation.X =0 ;
addposemsg.Orientation.Y =0 ;
addposemsg.Orientation.Z = 180;
addposemsg.Frame = uint8(0);
addposemsg.Speed = uint8(2);
Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg];
% WayPts 14
addposemsg.Position.X = 0 ;
addposemsg.Position.Y = 0;
addposemsg.Position.Z = 2;
addposemsg.Orientation.X =0 ;
addposemsg.Orientation.Y =0 ;
addposemsg.Orientation.Z = 180 ;
addposemsg.Frame = uint8(0);
addposemsg.Speed = uint8(2);
Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg];

send(pospub,Maddposemsg);

TG = TrajectoryGenerator(Maddposemsg,param,icMsg,[]);
if TG.status
    test= TG.Compute(trajpub);
    Traj_viewer(test);
end
%taille
size(Maddposemsg.Pose,1);
disp('done')
