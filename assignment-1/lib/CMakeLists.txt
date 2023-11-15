cmake_minimum_required (VERSION 3.8)

project(lib)

file(GLOB_RECURSE STATIC_SOURCE_FILES CONFIGURE_DEPENDS ./src/split*.cpp)
file(GLOB_RECURSE SHARED_SOURCE_FILES CONFIGURE_DEPENDS ./src/random*.cpp)

add_library(lib-static STATIC ${STATIC_SOURCE_FILES})

add_library(lib-shared SHARED ${SHARED_SOURCE_FILES})
