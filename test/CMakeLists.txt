catkin_add_gtest(TransferFunctionTest TransferFunctionTest.cc ${SOURCE_FILES})
target_link_libraries(TransferFunctionTest sonia_control)
set_target_properties(TransferFunctionTest PROPERTIES LINKER_LANGUAGE CXX )

catkin_add_gtest(TrajectoryGeneratorTest TrajectoryGeneratorTest.cc ${SOURCE_FILES})
target_link_libraries(TrajectoryGeneratorTest sonia_control)
set_target_properties(TrajectoryGeneratorTest PROPERTIES LINKER_LANGUAGE CXX )

catkin_add_gtest(DynamicModelTest DynamicModelTest.cc ${SOURCE_FILES})
target_link_libraries(DynamicModelTest sonia_control)
set_target_properties(DynamicModelTest PROPERTIES LINKER_LANGUAGE CXX )

catkin_add_gtest(ControllerPIDWithDynamicTest ControllerPIDWithDynamicTest.cc ${SOURCE_FILES})
target_link_libraries(ControllerPIDWithDynamicTest sonia_control)
set_target_properties(ControllerPIDWithDynamicTest PROPERTIES LINKER_LANGUAGE CXX )

catkin_add_gtest(ControllerPIDTest ControllerPIDTest.cc ${SOURCE_FILES})
target_link_libraries(ControllerPIDTest sonia_control)
set_target_properties(ControllerPIDTest PROPERTIES LINKER_LANGUAGE CXX )

catkin_add_gtest(PPISimulationTest PPISimulationTest.cc ${SOURCE_FILES})
target_link_libraries(PPISimulationTest sonia_control)
set_target_properties(PPISimulationTest PROPERTIES LINKER_LANGUAGE CXX )

catkin_add_gtest(CommandBSimulationTest CommandBSimulationTest.cc ${SOURCE_FILES})
target_link_libraries(CommandBSimulationTest sonia_control)
set_target_properties(CommandBSimulationTest PROPERTIES LINKER_LANGUAGE CXX )