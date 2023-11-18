cmake_minimum_required (VERSION 3.20)

project (plugins)

set(CMAKE_CXX_STANDARD 20)

include_directories(../include)

add_library(lowercase SHARED lowercase_plugin.cpp "lowercase_plugin.cpp")
set_target_properties(lowercase PROPERTIES SUFFIX ".plug")

add_library(vowel_remover SHARED vowel_remover_plugin.cpp "vowel_remover_plugin.cpp")
set_target_properties(vowel_remover PROPERTIES SUFFIX ".plug")
