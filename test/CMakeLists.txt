#project(ControlUnitTest)
#
#file(GLOB_RECURSE unitTEST_HEADERS *.h)
#file(GLOB_RECURSE unitTEST_SOURCES *.cc)
#
## add the executable
#add_executable(ControlUnitTest ${unitTEST_SOURCES} ${unitTEST_HEADERS})
#target_link_libraries(ControlUnitTest control)
#
#target_compile_options(ControlUnitTest PRIVATE -W -Wall -Wextra -Werror -O3 -std=c++11)
#
#install(TARGETS ControlUnitTest DESTINATION build)