cmake_minimum_required(VERSION 3.2)

# This is the "solution" file for this project "Codename: FireEngine (Working Title)"
project(FireEngine)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${FireEngine_SOURCE_DIR}/engine/cmake")

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

# Subprojects placed here
add_subdirectory(engine)
## add_subdirectory(engine_tests)

