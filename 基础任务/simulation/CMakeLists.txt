cmake_minimum_required(VERSION 3.0)

PROJECT(SIMULATION)

include_directories(include)

add_executable(main src/main.cpp src/Robot.cpp)
