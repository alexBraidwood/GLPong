cmake_minimum_required(VERSION 3.2)
project(FireEngine)

include_directories(include)

find_package(OpenGL REQUIRED)

link_directories(lib/gtest)
set(LINK_OPTIONS gmock gtest)


set(SOURCES
        src/main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_executable(engine_tests ${SOURCES})
target_link_libraries(engine_tests ${LINK_OPTIONS})
