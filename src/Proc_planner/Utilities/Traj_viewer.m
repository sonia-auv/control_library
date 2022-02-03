
% Initialise array
n = size(trajMsg.Transforms,1);
pose = zeros(n,3);
quat = zeros(n,4);
velocity = zeros(n,3);
angularRate = zeros(n,3);


 for i=1 : size(trajMsg.Transforms,1)
     pose(i,1) = trajMsg.Transforms(i).Translation.X;
     pose(i,2) = trajMsg.Transforms(i).Translation.Y;
     pose(i,3) = trajMsg.Transforms(i).Translation.Z;

     quat(i,1) = trajMsg.Transforms(i).Rotation.W;
     quat(i,2) = trajMsg.Transforms(i).Rotation.X;
     quat(i,3) = trajMsg.Transforms(i).Rotation.Y;
     quat(i,4) = trajMsg.Transforms(i).Rotation.Z;

     velocity(i,1) = trajMsg.Velocities(i).Linear.X;
     velocity(i,2) = trajMsg.Velocities(i).Linear.Y;
     velocity(i,3) = trajMsg.Velocities(i).Linear.Z;
     %velocity(i,:)=quatrotate(quat(i,:),velocity(i,:));

     angularRate(i,1) = trajMsg.Velocities(i).Angular.X;
     angularRate(i,2) = trajMsg.Velocities(i).Angular.Y;
     angularRate(i,3) = trajMsg.Velocities(i).Angular.Z;

 end

 tvec  = (0:1:n-1);
 plot(tvec,angularRate.');
 plot(tvec, pose.');

 plotTransforms(pose(1:100:end,:),quat(1:100:end,:),'InertialZDirection','Down')