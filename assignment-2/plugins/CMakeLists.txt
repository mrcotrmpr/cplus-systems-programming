cmake_minimum_required (VERSION 3.8)

project (plugins)

set(CMAKE_CXX_STANDARD 17)

include_directories(../include)

add_library(myplugin SHARED myplugin.cpp "myplugin.cpp")
set_target_properties(myplugin PROPERTIES SUFFIX ".plug")
