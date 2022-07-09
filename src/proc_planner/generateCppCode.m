% This Script generate the c++ code for proc_planner.
% Make sure to run this script in src/proc_planner folder.
function generateCppCode(build)

    ROSWS = "~/sonia_ws/";
    
    
% add shared lib folder   
    addpath("../shared_libraries/");

% Set the code generation config
    cfg = coder.config('exe');
    cfg.TargetLang = "C++";
    cfg.GenCodeOnly = true;
    cfg.Hardware = coder.hardware('Robot Operating System (ROS)');
    cfg.BuildConfiguration = "Faster Runs";
    cfg.Hardware.BuildAction = 'none';

% Generate the code
    codegen proc_planner -v -args {} -config cfg

% Load build Info mat
    load('./codegen/exe/proc_planner/buildInfo.mat')

% Generate zip file
    packNGo(buildInfo, 'fileName', 'proc_planner.zip');

% Delete codeGen folders.
    rmpath(genpath('build'));
    rmpath(genpath('codegen'));
    rmpath(genpath('devel'));
    rmpath(genpath('install'));
    rmpath(genpath('log'));
    rmpath(genpath('msgdef'));
    rmpath(genpath('src'));

    try rmdir('build', 's'); end;
    try rmdir('codegen','s'); end;
    try rmdir('devel','s'); end;
    try rmdir('install','s'); end;
    try rmdir('log','s'); end;
    try rmdir('msgdef','s'); end;
    try rmdir('src','s'); end;   

 % Build Code
    if build

       try system(strcat("rm -r ",ROSWS,"/src/proc_planner/src")); end;
        system(strcat("mkdir ",ROSWS,"/src/proc_planner/src"))
        unzip('proc_planner.zip',strcat(ROSWS,"/src/proc_planner/src/"))

        system(strcat("rm -r ",ROSWS,"/build"))
        system(strcat("rm -r ",ROSWS,"/devel"))
      
        work_folder = pwd;

        cd(ROSWS)
        system('catkin_make')
        cd(work_folder)
    end


    disp('Done !');
end