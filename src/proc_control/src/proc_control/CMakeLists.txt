cmake_minimum_required(VERSION 3.9)
project(proc_control)
set(CMAKE_VERBOSE_MAKEFILE ON)
# Set CMAKE_BUILD_TYPE
set(CMAKE_BUILD_TYPE Release)
# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()
# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(ALIAS_ROS1_CLASS_LOADER)
    add_definitions(-Dclass_loader=ros1_class_loader)
endif()
## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  nav_msgs
  sensor_msgs
  sonia_common
  trajectory_msgs
)
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  CATKIN_DEPENDS
  geometry_msgs
  nav_msgs
  roscpp
  sensor_msgs
  sonia_common
  std_msgs
  trajectory_msgs
)
###########
## Build ##
###########
## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  include
  ${PROJECT_SOURCE_DIR}
  ${Boost_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
 "/slprj/ert/_sharedutils"
  "include/proc_control"
)
set (CMAKE_SKIP_BUILD_RPATH false)
set (CMAKE_BUILD_WITH_INSTALL_RPATH true)
set (CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set (CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
## Get list of .c files in project source directory
file(GLOB ${PROJECT_NAME}_C_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/*.c)
## Get list of .cpp files in project source directory
file(GLOB ${PROJECT_NAME}_CPP_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/*.cpp)
# Declare executable - Node
add_executable(proc_control
  src/main.cpp
  src/proc_control.cpp
  src/proc_control_data.cpp
  src/rosnodeinterface.cpp
  src/slros_busmsg_conversion.cpp
  src/slros_initialize.cpp
  src/DropConstraint_LFPKTWNz.cpp
  src/DropConstraint_MueFKkTj.cpp
  src/DropConstraint_Tyj4QpAV.cpp
  src/DropConstraint_rIRdy5KO.cpp
  src/Unconstrained_UjzZuo4S.cpp
  src/Unconstrained_VQtVdCHQ.cpp
  src/Unconstrained_dIUZCfbX.cpp
  src/WtMult_eD9sgCWi.cpp
  src/WtMult_xTv5xWC7.cpp
  src/WtMult_xtNnjgO3.cpp
  src/abs_1HbhVWDZ.cpp
  src/abs_4F52yAua.cpp
  src/abs_5XxirU9Z.cpp
  src/abs_9BE3kip1.cpp
  src/abs_HXTuvHNM.cpp
  src/abs_TVF9gj68.cpp
  src/abs_hS9HYvNd.cpp
  src/all_H4RNf0h2.cpp
  src/binsearch_u32d_prevIdx.cpp
  src/binsearch_u32u16_prevIdx.cpp
  src/checkVectorNonFinite_2JllBqp7.cpp
  src/div_nde_s32_floor.cpp
  src/eps_AH2epkhQ.cpp
  src/eye_4CWHrAiR.cpp
  src/isfinite_NLoqvmdK.cpp
  src/kron_5Yeqlajx.cpp
  src/log2_blLsPIAE.cpp
  src/maximum2_I2IGaf8g.cpp
  src/maximum2_d2MhUgrc.cpp
  src/maximum2_goSZU0Rz.cpp
  src/maximum2_nfdZnRQn.cpp
  src/maximum_WmXKrdSr.cpp
  src/maximum_YsmBif7U.cpp
  src/maximum_bZyTUL5K.cpp
  src/minimum_0mT3wHDe.cpp
  src/minimum_NKIx9XVP.cpp
  src/minimum_d12sudeP.cpp
  src/mtimes_3lrguzTZ.cpp
  src/mtimes_mjx3OaTZ.cpp
  src/mtimes_oGNIPo7k.cpp
  src/norm_115oznfV.cpp
  src/norm_8ho9XaR8.cpp
  src/norm_GdpreYkZ.cpp
  src/norm_LIDj52w3.cpp
  src/norm_vTuG6Asx.cpp
  src/plook_u32d_binckpan.cpp
  src/plook_u32d_binckpang.cpp
  src/plook_u32u16_binckpan.cpp
  src/recomputeBlockDiag_qmxFvKVu.cpp
  src/rtGetInf.cpp
  src/rtGetNaN.cpp
  src/rt_atan2d_snf.cpp
  src/rt_nonfinite.cpp
  src/rt_nrand_Upu32_Yd_f_pw_snf.cpp
  src/rt_powd_snf.cpp
  src/rt_urand_Upu32_Yd_f_pw_snf.cpp
  src/trisolve_1QSWDcHY.cpp
  src/trisolve_1nFOis6o.cpp
  src/trisolve_3zyRfoj9.cpp
  src/trisolve_7ULo2Z2J.cpp
  src/trisolve_Ewqm83ue.cpp
  src/trisolve_QLyTZPzT.cpp
  src/trisolve_RerMU7v3.cpp
  src/trisolve_TPUoCQlv.cpp
  src/trisolve_bR4rdVHP.cpp
  src/trisolve_jVll4a1A.cpp
  src/trisolve_kmp7BqBh.cpp
  src/trisolve_nzh2XTxC.cpp
  src/updateWeights_HTL7SM8h.cpp
  src/updateWeights_YixtX2P7.cpp
  src/xgemv_3az3hqLU.cpp
  src/xgemv_5ht9hnKF.cpp
  src/xgemv_AUXWxjLv.cpp
  src/xgemv_F8pkuUXW.cpp
  src/xgemv_Frijm775.cpp
  src/xgemv_hztnEYXM.cpp
  src/xgemv_sOAKB8Uk.cpp
  src/xgemv_wB0hPhuq.cpp
  src/xgerc_6YFUaNlM.cpp
  src/xnrm2_39t0XtQD.cpp
  src/xnrm2_Cmmg4Lta.cpp
  src/xnrm2_H2991AvN.cpp
  src/xnrm2_KuvT0oF6.cpp
  src/xnrm2_LFVDqtKo.cpp
  src/xnrm2_UCgE6veV.cpp
  src/xnrm2_ZWAmJ4ix.cpp
  src/xnrm2_vEpa8zuo.cpp
  src/xnrm2_yAJpxfog.cpp
  src/xrot_3pYuG0oG.cpp
  src/xrot_yqSjxpUW.cpp
  src/xrotg_XzIjz1eG.cpp
  src/xzlarf_2N2eIztg.cpp
  src/rtiostream_interface.c
  src/rtiostream_tcpip.c
  src/slros_generic_param.cpp
)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#target_compile_options(proc_control PUBLIC  $<$<OR:$<COMPILE_LANGUAGE:CXX>,$<COMPILE_LANGUAGE:C>>: -Wall -Wextra -Wpedantic >)
endif()
target_compile_options(proc_control PUBLIC 
  $<$<OR:$<COMPILE_LANGUAGE:CXX>,$<COMPILE_LANGUAGE:C>>:
  -DMODEL=proc_control
  -DNUMST=6
  -DNCSTATES=0
  -DHAVESTDIO
  -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
  -DCLASSIC_INTERFACE=0
  -DALLOCATIONFCN=0
  -DTID01EQ=0
  -DTERMFCN=1
  -DONESTEPFCN=1
  -DMAT_FILE=0
  -DMULTI_INSTANCE_CODE=1
  -DINTEGER_CODE=0
  -DMT=0
  -DROS_PROJECT
  -DMW_SCHED_OTHER
  -DSTACK_SIZE=64
  -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__
  -DRT=RT
     -fpermissive  >
  )
## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
add_dependencies(
  proc_control
  ${catkin_EXPORTED_TARGETS}
)
target_include_directories(proc_control PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
## Specify libraries to link a library or executable target against
target_link_libraries(
  proc_control 
    ${catkin_LIBRARIES}
    ${Boost_LIBRARIES}
    ${CMAKE_DL_LIBS}
)
install(TARGETS proc_control
  EXPORT export_${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME})
foreach(file_i ${CUDA_BINS})
add_custom_command(
                   TARGET proc_control
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND}
                   ARGS -E copy ${PROJECT_SOURCE_DIR}/src/${file_i} ${CATKIN_DEVEL_PREFIX}/proc_control_ert_rtw/${file_i}
				   )
endforeach(file_i)
# Generated on Sun Jul 03 00:34:27 2022
