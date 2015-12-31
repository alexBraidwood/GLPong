cmake_minimum_required(VERSION 3.2)
project(GamelibTests)

link_directories(lib/gtest)
set(LINK_OPTIONS gtest gtest_main)


set(SOURCES
        src/main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(googletest)

add_executable(gamelib_tests ${SOURCES})
target_include_directories(gamelib_tests PUBLIC
        include
        googletest/googletest/include
        ../gamelib/include
        ../gamelib/external
        ../gamelib/external/glm)

target_link_libraries(gamelib_tests ${LINK_OPTIONS})
