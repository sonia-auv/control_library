# \file     CMakeLists.txt
# \author   Olivier Lavoie <olavoie9507@gmail.com>
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


set(control_library_SRC_DIR "src")

#===============================================================================
# C A T K I N   C O N F I G U R A T I O N

find_package(catkin REQUIRED COMPONENTS
        roscpp
        )

find_package(catkin REQUIRED cmake_modules)
find_package(Eigen3 REQUIRED)

catkin_package(
        INCLUDE_DIRS src
        LIBRARIES sonia_control
        CATKIN_DEPENDS
        roscpp
)

#===============================================================================
# I N C L U D E   F I L E S

file(GLOB_RECURSE control_library_SRC_FILES "${control_library_SRC_DIR}/*.h"
                                "${control_library_SRC_DIR}/*.cc")

include_directories(
        ${catkin_INCLUDE_DIRS}
        ${Eigen_INCLUDE_DIRS}
        ${control_library_SRC_DIR}
)

#==========================================================================
# C R E A T E   E X E C U T A B L E
add_library(sonia_control SHARED ${control_library_SRC_FILES})
target_link_libraries(sonia_control ${catkin_LIBRARIES} ${Eigen_LIBRARIES} yaml-cpp)
set_target_properties(sonia_control PROPERTIES LINKER_LANGUAGE CXX)

install(
        TARGETS ${TARGET_NAME}
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(
        DIRECTORY ${control_library_SRC_DIR}/${PROJECT_NAME}/
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
        PATTERN ".git" EXCLUDE
)

#==========================================================================
# U N I T   T E S T S
if (${CATKIN_ENABLE_TESTING})
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
endif()
