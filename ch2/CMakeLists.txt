cmake_minimum_required(VERSION 3.10)

project(useHelloSLAM)

#include_directories(HelloSLAM)
#add_subdirectory(HelloSLAM)

add_executable(useHelloSLAM useHelloSLAM.cpp)

find_package(hello_slam REQUIRED)
if(hello_slam_FOUND)
    message("HelloSLAM INCLUDE_DIR" ${hello_slam_INCLUDE_DIR})
    message("HelloSLAM LIBRARY" ${hello_slam_LIBRARY})
endif(hello_slam_FOUND)

target_link_libraries(useHelloSLAM ${hello_slam_LIBRARY})