cmake_minimum_required (VERSION 3.20)

project (plugins)

set(CMAKE_CXX_STANDARD 20)

include_directories(../shared)

add_library(testplugin SHARED test_plugin.cpp "test_plugin.cpp")
set_target_properties(testplugin PROPERTIES SUFFIX ".plug")
