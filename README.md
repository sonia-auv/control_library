## Control Library
This constains our Matlab/Simulink projects to develop the control for AUVs.

If you are interested with this project's documentation, I suggest that you look at the [SONIA's documentation website](https://wiki.sonia.etsmtl.ca/en/software/Navigation-and-Control).

The ReadMe file will focus on the setup procedure.
# Installation
## Prerequisites 
It is possible to develop on windows but this instalation tutorial will focus on Ubuntu 20.04.
You therefore need to have an ubuntu machine with ROS installed and having a catkin workspace.

## Install MATAB
Since ROS support in MATLAB is relatively new, the installation procedure may change sligly we newer matlab version.
For now, This project is using **MATLAB 2022a**.

First, You can get your copy here

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
> - robotoc system toolbox                             
> - ROS Toolbox       
> - Sensor usion and tracking toolbox
> - Simulink Coder          
> - Simulink compiler
> - Symbolic Math Toolbox                             
> - System Identification                           

## Updating cmake if needed
Matlab require at least cmake version 3.15 for generate custom ros msg . You can check your cmake version with the following command:

`cmake --version`

If you need to update cmake, you can follow this tutorial.
> https://www.mathworks.com/matlabcentral/answers/623103-matlab-2020b-rosgenmsg-can-t-find-cmake#answer_753184

## Building ROS customs message in matlab.
Before building ros customs messages, matlab 2022a require python 3.9 **virtual environment**.

You can install the virtual environment with the following command:

`sudo apt install python3.9 python3.9-venv python3.9-dev`

Next thing is to create a virtual environment. I have all ready explained it in a matlab Answers forum that you can read here :

> https://www.mathworks.com/matlabcentral/answers/1690800-error-in-building-custom-ros-messages#answer_937270

All the custom ROS message used by sonia are located in the sonia common repo. You have to clone this repo in your catkin workspace.

> https://github.com/sonia-auv/sonia_common

You need to generate the ros message in matlab to be able to use it. To do so, navigate to your src folder in the matlab file explorer than run the next command and follow the instruction.

`rosgenmsg('./')`

If matlab doesn't find python executable, check first if python is install on your machine. Type in a command windows:

`python3 --version`

Then, you have to tell matlab where is your python executable. To do so, type the following command in your matlab console.

`pyenv('Version',<your python executable path>)`

## Add the working folder in the matlab path.
In your matlab windows, right click on the **src** and click on **Add to Path / Selected Folder and Subfolders**.

After that, execute the following command in your matlab terminal to save the added folder for next matlab start.

`savepath`

## Validate the setup 
A quick way to validate that you have completed the installation successfully is to generate the c++ code of **proc_planner**.

to do so run the following command in your matlab console:

`GeneratePlannerCppCode(false)`

if the command end with **Done !**, it means that code have been generated successfully.

next you can open the simulink project of proc_contol located in **src/proc_control/proc_control/simulink/proc_control.slx** and verify if you can run it.
