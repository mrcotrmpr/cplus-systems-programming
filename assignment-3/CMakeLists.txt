cmake_minimum_required (VERSION 3.20)

project (assignment-3)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)
add_subdirectory(plugins)

add_executable(${PROJECT_NAME} main.cpp)
