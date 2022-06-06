## Control Library
This constains our Matlab/Simulink projects to develop the control for AUVs.
# prerequisites
You need to have ROS installed and have a catkin workspace.
# Installation
Here's the step to flow to execute the current project.

First you need to have Matlab 2021b installed. You can get your copy here

> https://www.mathworks.com/products/new_products/latest_features.html.

You need to unzip the package and add the execution permission to the install script:

` sudo chmod 666 install`

Run the install script.

If the matlab installer doesn't show up. Run this command and rerun the install scipt:

`xhost +SI:localuser:root`

Durning the setup you will have to add an username. Make sure you enter your linux username to avoid liscence mismatch.

The control Library project use servial toolbox. Here the list of the used toolbox:

> - MATLAB                                                
> - Simulink  
> - Areospace Blockset
> - Areospace toolbox                                          
> - Control System Toolbox                               
> - Embedded Coder    
> - lidar Toolbox
> - Mapping Toolbox                                   
> - MATLAB Coder
> - MATLAB Compiler
> - Model Predictive Control Toolbox                      
> - Navigation Toolbox                                    
> - Optimization Toolbox  
> - phased Array Toolbox
> - robotoc system toolbox                             
> - ROS Toolbox       
> - Sensor usion and tracking toolbox
> - simscape
> - simscape electrical
> - Simulink Coder          
> - Simulink compiler
> - Symbolic Math Toolbox                             
> - System Identification                           

Matlab require at least cmake version 3.15 for generate custom ros msg . You can check your cmake version with the following command:

`cmake --version`

If you need to update cmake, you can follow this tutorial.
> https://www.mathworks.com/matlabcentral/answers/623103-matlab-2020b-rosgenmsg-can-t-find-cmake#answer_753184

All the custom ROS message used by sonia are located in the sonia common repo. You have to clone this repo in your catkin workspace.

> https://github.com/sonia-auv/sonia_common

You need to generate the ros message in matlab to be able to use it. To do so, navigate to your src folder in the matlab file explorer than run the next command and follow the instruction.

`rosgenmsg('./')`

If matlab doesn't find python executable, check first if python is install on your machine. Type in a command windows:

`python3 --version`

You need to have version 3.9 or higer. If its the case, you can type the following command to find the path of the python environement.

`which python3`

Then, you have to tell matlab where is your python executable. To do so, type the following command in your matlab console.

`pyenv('Version',<your python executable path>)`

# Use the control
There are multiple mode available:

 0: Kill 

 1-9: special (reserved) 

 
 10-19:  Quaternion Adaptive MPC 

 - 10 :Multi waypoints planning 

 - 11 : single waypoint trajectory 

 - 12 : Hydrophone Mode. 

 - 13 : Alignement vision Front 

 - 14 : Alignement vision bottom  

 - 19 : Space mouse (Semi-manual) 

 

 20-29 : Open Loop 

 - 20 : space mouse Model Base Open loop 

 - 21 : space mouse direct B Matrix 

 

 30-39: Develop  

 - 30 : LTV MPC - single waypoint 

 

 40 – 49 : Legacy 

 - 40 : NLMPC single waypoints (Non compilable) 

 - 41 : Adaptive MPC Euler single waypoints 

You can use the following message to set mode

`rostopic pub /proc_control/setmode std_msgs/uin32 "data: <mode>"`

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
