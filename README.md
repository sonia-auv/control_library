## Control Library
This constains our Matlab/Simulink projects to develop the control for AUVs.

# Installation
Here's the information about the Matlab used for this project.
You must at least install these toolbox:

MATLAB Version: 9.8.0.1451342 (R2020a) Update 5
Operating System: Linux 4.15.0-76-generic #86-Ubuntu SMP Fri Jan 17 17:24:28 UTC 2020 x86_64
Java Version: Java 1.8.0_202-b08 with Oracle Corporation Java HotSpot(TM) 64-Bit Server VM mixed mode

- MATLAB                                                Version 9.8         (R2020a)
- Simulink                                              Version 10.1        (R2020a)
- Control System Toolbox                                Version 10.8        (R2020a)
- DSP System Toolbox                                    Version 9.10        (R2020a)
- Embedded Coder                                        Version 7.4         (R2020a)
- MATLAB Coder                                          Version 5.0         (R2020a)
- Model Predictive Control Toolbox                      Version 6.4         (R2020a)
- Navigation Toolbox                                    Version 1.1         (R2020a)
- Optimization Toolbox                                  Version 8.5         (R2020a)
- ROS Toolbox                                           Version 1.1         (R2020a)
- Robotics System Toolbox                               Version 3.1         (R2020a)
- Signal Processing Toolbox                             Version 8.4         (R2020a)
- Simulink Coder                                        Version 9.3         (R2020a)
- Symbolic Math Toolbox                                 Version 8.5         (R2020a)
- Vehicle Dynamics Blockset                             Version 1.4         (R2020a)

# Use the control
You can now send messages to the control using a rostopic command.

# Example 
### Add pose
Here's the content of an AddPose message:
- position: Point (x y z)
- orientation: Vector3 (x y z)
- frame: uint8 
    - 0 : Absolute position and absolute angle
    - 1 : Relative position and relative angle
    - 2 : Relative position and absolute angle
    - 3 : Absolute position and relative angle
- speed: uint8
- fine: float64 

`rostopic pub /proc_control_matlab/add_pose sonia_common/AddPose "{Point: {0, 0, 0}, Vector3: {0, 0, 0}, 1, 1, 0.0}"`

### Compute trajectory
`rostopic pub /proc_control_matlab/compute_trajectory std_msgs/Bool '{true}'`

### Clear waypoints
`rostopic pub /proc_control_matlab/clear_waypoints std_msgs/Bool '{true}'`

### Set control mode
Here's the content of a set_mode message:
    - data: uint8
        - 0 : Automatic mode (Trajectories)
        - 1 : Manual mode (SpaceNav)

`rostopic pub /proc_control/set_mode std_msgs/UInt8 '{data: 0}'`

# How to generate custom messages for Matlab.
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
