cmake_minimum_required (VERSION 3.8)
project (systems-programming-processes)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(sample)

add_executable(${PROJECT_NAME} main.cpp)
