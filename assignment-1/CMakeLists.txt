cmake_minimum_required(VERSION 3.8)

project(assignment-1)

if (WIN32 OR WIN64)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif ()

include_directories(lib)
add_subdirectory(lib)

add_executable(${PROJECT_NAME}-static main.cpp)
target_link_libraries(${PROJECT_NAME}-static PRIVATE lib-static)

add_executable(${PROJECT_NAME}-shared main.cpp)
target_link_libraries(${PROJECT_NAME}-shared PRIVATE lib-shared)

if (EXISTS ${CMAKE_CURRENT_BINARY_DIR}/lib/lib-shared.dll)
    add_custom_command(
        TARGET ${PROJECT_NAME}-shared
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_BINARY_DIR}/lib/lib-shared.dll
                ${CMAKE_CURRENT_BINARY_DIR}
    )
endif()
