cmake_minimum_required(VERSION 3.20)

project(test)

set(CMAKE_CXX_STANDARD 20)

include_directories(../shared)

add_executable(${PROJECT_NAME} main.cpp plugin_wrapper.cpp)
