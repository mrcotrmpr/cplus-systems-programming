cmake_minimum_required (VERSION 3.20)

project (assignment-3)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(sample)

add_executable(${PROJECT_NAME} main.cpp)
