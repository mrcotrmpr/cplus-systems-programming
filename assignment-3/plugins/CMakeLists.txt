cmake_minimum_required (VERSION 3.20)

project (plugins)

set(CMAKE_CXX_STANDARD 20)

include_directories(../shared)

add_library(success_plugin SHARED "success_plugin.cpp")
set_target_properties(success_plugin PROPERTIES SUFFIX ".plug")

add_library(fail_plugin SHARED "fail_plugin.cpp")
set_target_properties(fail_plugin PROPERTIES SUFFIX ".plug")
