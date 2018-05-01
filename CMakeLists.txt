# \file     CMakeLists.txt
# \author   Olivier Lavoie <olavoie9507@gmail.com>
# \date     23/09/2016
#
# \copyright Copyright (c) 2018 S.O.N.I.A. All rights reserved.
#
# \section LICENSE
#
# This file is part of S.O.N.I.A. software.
#
# S.O.N.I.A. software is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# S.O.N.I.A. software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with S.O.N.I.A. software. If not, see <http://www.gnu.org/licenses/>.

#===============================================================================
# G L O B A L   P R O J E C T   C O N F I G U R A T I O N

cmake_minimum_required(VERSION 2.8)
project(control_library)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING
            "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
            FORCE)
endif (NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 -O3 -s")

set(CMAKE_MODULE_PATH "/usr/share/cmake-3.0/Modules")

set(control_SRC_DIR "src")

find_package(catkin)

#===============================================================================
# I N C L U D E   F I L E S

file(GLOB_RECURSE control_FILES
        "${control_SRC_DIR}/*.cc"
        "${control_SRC_DIR}/*.h")

include_directories(
        ${catkin_INCLUDE_DIRS}
        ${control_SRC_DIR}
)

catkin_package(
        INCLUDE_DIRS ${control_SRC_DIR}
        LIBRARIES
        CATKIN_DEPENDS roscpp
)

#==========================================================================
# C R E A T E   E X E C U T A B L E
add_library(control SHARED ${control_FILES})
#add_executable(${PROJECT_NAME} ${control_FILES})
target_link_libraries(control ${catkin_LIBRARIES} ${Eigen_LIBRARIES} yaml-cpp)

#==========================================================================
# U N I T   T E S T S
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
