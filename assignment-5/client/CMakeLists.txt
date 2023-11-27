cmake_minimum_required (VERSION 3.20)

project(client)

set(CMAKE_CXX_STANDARD 20)

include_directories(../shared)

file(GLOB_RECURSE SHARED_SOURCE_FILES CONFIGURE_DEPENDS ../shared/*.cpp)

add_executable(${PROJECT_NAME} ${SHARED_SOURCE_FILES} main.cpp)
