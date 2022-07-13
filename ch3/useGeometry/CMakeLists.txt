cmake_minimum_required(VERSION 3.10)
project(geometry)

include_directories("/usr/include/eigen3")

add_executable(eigenGeometry useGeometry.cpp)