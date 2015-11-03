cmake_minimum_required(VERSION 3.2)

# This is the "solution" file for this project "Codename: FireEngine (Working Title)"
project(GLPong)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${GLPong_SOURCE_DIR}/engine/cmake")

set(GLPong_Binaries ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(GLPong_BINARY_DIR "${GLPong_Binaries}")

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

# Subprojects placed here
add_subdirectory(engine)
add_subdirectory(engine_tests)

