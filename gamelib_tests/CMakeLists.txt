cmake_minimum_required(VERSION 3.2)
project(GamelibTests)

include_directories(include)
include_directories(googletest/googletest/include)
include_directories(../gamelib/include)

link_directories(lib/gtest)
set(LINK_OPTIONS gtest gtest_main)


set(SOURCES
        src/main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(googletest)

add_executable(gamelib_tests ${SOURCES})
target_link_libraries(gamelib_tests ${LINK_OPTIONS})
