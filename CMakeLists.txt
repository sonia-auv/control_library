# \file     CMakeLists.txt
# \author   Olivier Lavoie <olavoie9507@gmail.com>
# \date     23/09/2016
#
# \copyright Copyright (c) 2016 S.O.N.I.A. All rights reserved.
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

#===============================================================================
# C A T K I N   C O N F I G U R A T I O N
find_package(
        catkin REQUIRED COMPONENTS
        roscpp
)

file(GLOB_RECURSE SOURCE_FILES *.cc)
file(GLOB HEADER_FILES *.h)

#===============================================================================
# I N C L U D E   F I L E S
add_library(control SHARED ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(control ${Eigen_LIBRARIES} yaml-cpp)

# Build option
target_compile_options(control PRIVATE -W -Wall -Wextra -Werror -O3 -std=c++11)

install(TARGETS control DESTINATION build)

#==========================================================================
# U N I T   T E S T S
if (${CATKIN_ENABLE_TESTING})
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
endif ()
