cmake_minimum_required(VERSION 3.2)
project(pong)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message("64 bit compiler")
    set(EX_PLATFORM 64)
    set(EX_PLATFORM_NAME "x64")
else(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message("32 bit compiler")
    set(EX_PLATFORM 32)
    set(EX_PLATFORM_NAME "x86")
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)

include_directories(include)
include_directories(../gamelib/include)

if (WIN32)
    if(EX_PLATFORM EQUAL 64)
        include_directories(../gamelib/SDL2/x86_64-w64-mingw32/include/SDL2)
    else(EX_PLATFORM EQUAL 64)
        include_directories(../gamelib/SDL2/i686-w64-mingw32/include/SDL2)
    endif(EX_PLATFORM EQUAL 64)
else()
    include_directories(/usr/include/SDL2)
endif()

set(SOURCES
        src/Ball.cpp
        src/Paddle.cpp)

file(MAKE_DIRECTORY ../lib)

set(CMAKE_STATIC_LIBRARY_PREFIX "../lib/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_library(pong ${SOURCES})
