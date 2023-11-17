cmake_minimum_required (VERSION 3.8)

project (assignment-2)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ./src/*.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS ./include/*.hpp)

add_subdirectory(plugins)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

add_custom_target(copy_data COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data)
add_dependencies(${PROJECT_NAME} copy_data)

target_include_directories(assignment-2 PUBLIC include)
