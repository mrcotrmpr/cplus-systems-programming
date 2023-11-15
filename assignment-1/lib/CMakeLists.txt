cmake_minimum_required (VERSION 3.8)

project(lib)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ./src/*.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS ./include/*.hpp)

add_library(lib-static STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_library(lib-shared SHARED ${SOURCE_FILES} ${HEADER_FILES})
