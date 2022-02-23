% newmsg = Maddposemsg;
% newmsg.Pose(1).Frame = 1;
% 
% for i =2 : max(size(Maddposemsg.Pose))
% 
%      pose(1) = Maddposemsg.Pose(i).Position.X - Maddposemsg.Pose(i-1).Position.X ;
%      pose(2) = Maddposemsg.Pose(i).Position.Y - Maddposemsg.Pose(i-1).Position.Y;
%      pose(3) = Maddposemsg.Pose(i).Position.Z - Maddposemsg.Pose(i-1).Position.Z;
% 
%      rot =(Maddposemsg.Pose(i).Orientation.Z - Maddposemsg.Pose(i-1).Orientation.Z);
%      
% 
%      if rot> 180
%          rot= 360-rot;
%      end
% 
%      if rot<-180
%          rot = -(360+rot);
%      end
%      
%      newmsg.Pose(i).Orientation.Z = rot;
% 
%     transPose = quatrotate((eul2quat([deg2rad(Maddposemsg.Pose(i).Orientation.Z),0,0],"ZYX")),pose);
% 
%     newmsg.Pose(i).Position.X = transPose(1);
%     newmsg.Pose(i).Position.Y = transPose(2);
%     newmsg.Pose(i).Position.Z = transPose(3);
% 
%     
%     newmsg.Pose(i).Frame = 1;
%     fprintf("X: %d Y: %d Z: %d   yam : %d \n",transPose(1),transPose(2),transPose(3),rot)
% end

for i =1 : max(size(newmsg.Pose))
fprintf("WPTS # %d :: Position { X: %d Y: %d Z: %d } Orientation { yaw : %d } \n",i, newmsg.Pose(i).Position.X,newmsg.Pose(i).Position.Y,newmsg.Pose(i).Position.Z,newmsg.Pose(i).Orientation.Z)
end

iquat= eul2quat(deg2rad([-45,0,0]),"ZYX");
icMsg = rosmessage('geometry_msgs/Pose',"DataFormat","struct"); % IC topic


icMsg.Orientation.W = iquat(1);
icMsg.Orientation.X = iquat(2);
icMsg.Orientation.Y = iquat(3);
icMsg.Orientation.Z = iquat(4);

icMsg.Position.Z = 0.3;
param.ts = 0.1;
param.amax = 0.15;
param.vlmax = 0.8;
param.vamax = deg2rad(45);

TG = TrajectoryGenerator(newmsg,param,icMsg);
if TG.status
    test= TG.Compute(trajpub);
    Traj_viewer(test);
end