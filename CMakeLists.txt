cmake_minimum_required(VERSION 3.3)
project(FlukaConverter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

set(SOURCE_FILES main.cpp)
add_executable(FlukaConverter ${SOURCE_FILES})