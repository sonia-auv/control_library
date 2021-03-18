## Control Library
This constains our Matlab/Simulink projects to develop the control for AUVs.

# Installation
For this project, we are using Matlab R2020a.

You must install these toolbox:
- ROS Toolbox interface for ROS Custom Messages
- [...]

# Use the control
You can now send messages to the control using a rostopic command.

# Example 
### Add pose
`rostopic pub /proc_control_matlab/add_pose proc_control_matlab/AddPose "{Point: {0, 0, 0}, Vector3: {0, 0, 0}, 1, 1, 0.0}"`

### Compute trajectory
`rostopic pub /proc_control_matlab/compute_trajectory proc_control_matlab/ComputeTrajectory '{data: true}'`

### Clear waypoints
`rostopic pub /proc_control_matlab/clear_waypoints proc_control_matlab/ClearTrajectory '{data: true}'`


You can also receive messages from the control.

# Example
...

# How to generate custom messages.
To create a custom message, you must do the following. We highly recommend to use standard messages.
- Follow this procedure to generate a new .srv or .msg file for ROS: https://wiki.ros.org/ROS/Tutorials/CreatingMsgAndSrv
- Don't forget to compile after adding a new custom message.
- Follow this procedure to generate custom message for Matlab: https://www.mathworks.com/help/ros/ug/ros-custom-message-support.html
- Use `rosgenmsg` function: https://www.mathworks.com/help/ros/ref/rosgenmsg.html


# If you have any problem
## Problem with geometry_msg and IMU messages.
https://www.mathworks.com/matlabcentral/answers/553828-having-trouble-building-custom-ros-msgs-in-matlab-2020a

## Warning at compilation phase.
set_param('TrajectoryGeneratorASYNC', 'ModelReferenceSymbolNameMessage', 'none')