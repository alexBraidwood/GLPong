cmake_minimum_required(VERSION 3.2)

# This is the "solution" file for this project "Codename: FireEngine (Working Title)"
project(FireEngine)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${FireEngine_SOURCE_DIR}/engine/cmake")

set(FireEngine_Binaries ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(FireEngine_BINARY_DIR "${FireEngine_Binaries}")

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

# Subprojects placed here
add_subdirectory(engine)
add_subdirectory(engine_tests)

