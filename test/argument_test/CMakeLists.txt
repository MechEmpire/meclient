CMAKE_MINIMUM_REQUIRED(VERSION 2.8.5)

INCLUDE_DIRECTORIES()

ADD_EXECUTABLE(argument_test argument_test.cpp)
TARGET_LINK_LIBRARIES(argument_test argument)
TARGET_LINK_LIBRARIES(argument_test gtest gtest_main pthread)