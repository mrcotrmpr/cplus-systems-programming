cmake_minimum_required(VERSION 3.8)

project(assignment-1)

if (WIN32 OR WIN64)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif ()

include_directories(lib)
add_subdirectory(lib)

add_custom_target(copy_data COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data)

add_executable(${PROJECT_NAME} main.cpp)
add_dependencies(${PROJECT_NAME} copy_data)

target_link_libraries(${PROJECT_NAME} PRIVATE lib-static lib-shared)
