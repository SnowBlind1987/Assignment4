cmake_minimum_required(VERSION 2.8)

set (CMAKE_CXX_FLAGS "-g -pipe -O2 -std=c++11 -lm")

add_executable(dist edit_distance.cpp)

