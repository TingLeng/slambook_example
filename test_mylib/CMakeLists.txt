cmake_minimum_required(VERSION 3.10)

project(test)

add_executable(test test.cpp)

find_package(hello_slam REQUIRED)
if(hello_slam_FOUND)
    message("HelloSLAM Include_DIR" ${hello_slam_INCLUDE_DIR})
    message("HelloSLAM LIBRARY" ${hello_slam_LIBRARY})
endif(hello_slam_FOUND)



target_link_libraries(test ${hello_slam_LIBRARY})



