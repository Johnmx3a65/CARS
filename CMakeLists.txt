cmake_minimum_required(VERSION 3.27)
project(cars)

set(CMAKE_CXX_STANDARD 17)

add_executable(cars main.h main.cpp Car.h Car.cpp)
