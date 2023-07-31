## Control Library
This constains our Matlab/Simulink projects to develop the proc_control and proc_planner for AUVs.

If you are interested in this project's documentation, I suggest that you look at the [SONIA's documentation website](https://wiki.sonia.etsmtl.ca/en/software/Navigation-and-Control).

The ReadMe file will focus on the setup procedure.
# Installation
## Prerequisites 
It is possible to develop on Windows but this installation tutorial will focus on Ubuntu 20.04.
You therefore need to have an Ubuntu machine with ROS installed and having a catkin workspace.

## Increase  SWAP
For computers with 16 GB of RAM or less, increase the swap size to avoid killing your machine while compiling or generating code.
``` 
sudo swapoff /swapfile
sudo rm /swapfile
sudo dd if=/dev/zero of=/swapfile bs=1M count=16384
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
reboot
``` 
## Install MATLAB
Since the ROS support in MATLAB is relatively new, the installation procedure may change slightly with newer Matlab versions.
For now, This project is using **MATLAB 2022a**.

First, You can get your copy here

> https://www.mathworks.com/products/new_products/latest_features.html.

You need to unzip the package and add the execution permission to the install script:

` sudo chmod 666 install`

Run the install script.

If the Matlab installer doesn't show up, run this command and rerun the install scipt:

`xhost +SI:localuser:root`

Durning the setup you will have to add an username. Make sure you enter your linux username to avoid liscence mismatch.

The control library project use several toolboxes. Here is the list of the used toolboxes:

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
Matlab requires at least cmake version 3.15 to generate custom ros msgs. You can check your cmake version with the following command:

`cmake --version`

If you need to update cmake, you can follow this tutorial.
> https://www.mathworks.com/matlabcentral/answers/623103-matlab-2020b-rosgenmsg-can-t-find-cmake#answer_753184

## Building ROS custom messages in matlab.
Before building ros custom messages, matlab 2022a require python 3.9 **virtual environment**.

You can install the virtual environment with the following command:

`sudo apt install python3.9 python3.9-venv python3.9-dev`

Next thing is to create a virtual environment. I have already explained it in a matlab answers forum, which you can read here :

> https://www.mathworks.com/matlabcentral/answers/1690800-error-in-building-custom-ros-messages#answer_937270

All the custom ROS messages used by SONIA are located in the sonia_common repo. You have to clone this repo in your catkin workspace.

> https://github.com/sonia-auv/sonia_common

You need to generate the ros message in matlab to be able to use it. To do so, navigate to your src folder in the matlab file explorer, than run the next command and follow the instructions.

`rosgenmsg('./')`

If Matlab doesn't find the python executable, check first if python is installed on your machine. Type in a command windows:

`python3 --version`

Then, you have to tell Matlab where your python executable is. To do so, type the following command in your Matlab console:

`pyenv('Version',<your python executable path>)`

## Add the working folder in the Matlab path.
In your Matlab window, right click on the **src** and click on **Add to Path / Selected Folder and Subfolders**.

After that, execute the following command in your Matlab terminal to save the added folder for the next Matlab start.

`savepath`

## Validate the setup 
A quick way to validate that you have completed the installation successfully is to generate the c++ code of **proc_planner**.

to do so run the following command in your matlab console:

`GeneratePlannerCppCode(false)`

if the command ends with **Done !**, it means that code has been generated successfully.

Next you can open the simulink project of proc_contol located in **src/proc_control/proc_control/simulink/proc_control.slx** and verify if you can run it.
