cmake_minimum_required(VERSION 3.2)
project(Pong)

include_directories(include)

set(SOURCES
        src/Ball.cpp
        src/Paddle.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_library(Ponglib ${SOURCES})
