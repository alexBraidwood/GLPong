cmake_minimum_required(VERSION 3.2)
project(GameProject)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message("64 bit compiler")
    set(EX_PLATFORM 64)
    set(EX_PLATFORM_NAME "x64")
else(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message("32 bit compiler")
    set(EX_PLATFORM 32)
    set(EX_PLATFORM_NAME "x86")
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)

add_definitions(-std=c++14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${GameProject_SOURCE_DIR}/cmake")

set(GameProject_Binaries ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(GameProject_BINARY_DIR "${GameProject_Binaries}")

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
include_directories(pong/include)
include_directories(gamelib/include)
include_directories(gamelib/include/external)
link_directories(lib)

# Subprojects placed here
add_subdirectory(gamelib)
add_subdirectory(gamelib_tests)
add_subdirectory(pong)

if (WIN32)
    if(EX_PLATFORM EQUAL 64)
        include_directories(gamelib/SDL2/x86_64-w64-mingw32/include/SDL2)
        link_directories(gamelib/SDL2/x86_64-w64-mingw32/lib)
        set(BINARIES gamelib/SDL2/x86_64-w64-mingw32/bin/SDL2.dll)
    else(EX_PLATFORM EQUAL 64)
        include_directories(gamelib/SDL2/i686-w64-mingw32/include/SDL2)
        set(BINARIES gamelib/SDL2/i686-w64-mingw32/bin/SDL2.dll)
        link_directories(gamelib/SDL2/i686-w64-mingw32/lib)
    endif(EX_PLATFORM EQUAL 64)

    link_directories(gamelib/SOIL)
    set(LINK_OPTIONS common pong)
    add_definitions(-DGLEW_STATIC)

    file(COPY ${BINARIES} DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
else()
    find_package(SDL2 REQUIRED)
    include_directories(/usr/include/SDL2)
    set(LINK_OPTIONS common pong)
endif()

set(SOURCE_FILES main.cpp)

add_executable(Game ${SOURCE_FILES})

if (WIN32)
    target_link_libraries(Game ${OPENGL_LIBRARY} ${SDL2_LIBRARIES} ${LINK_OPTIONS})
else(WIN32)
    target_link_libraries(Game ${LINK_OPTIONS} ${OPENGL_LIBRARY} ${SDL2_LIBRARIES})
endif(WIN32)

