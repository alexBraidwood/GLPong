cmake_minimum_required(VERSION 3.2)
project(GLPong)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message("64 bit compiler")
    set(EX_PLATFORM 64)
    set(EX_PLATFORM_NAME "x64")
else(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message("32 bit compiler")
    set(EX_PLATFORM 32)
    set(EX_PLATFORM_NAME "x86")
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${GLPong_SOURCE_DIR}/cmake")

include_directories(include)
include_directories(include/engine)
include_directories(include/external)

find_package(OpenGL REQUIRED)

if (WIN32)
    if(EX_PLATFORM EQUAL 64)
        include_directories(SDL2/x86_64-w64-mingw32/include/SDL2)
        link_directories(SDL2/x86_64-w64-mingw32/lib)
        set(BINARIES SDL2/x86_64-w64-mingw32/bin/SDL2.dll)
    else(EX_PLATFORM EQUAL 64)
        include_directories(SDL2/i686-w64-mingw32/include/SDL2)
        set(BINARIES SDL2/i686-w64-mingw32/bin/SDL2.dll)
        link_directories(SDL2/i686-w64-mingw32/lib)
    endif(EX_PLATFORM EQUAL 64)

    link_directories(SOIL)
    set(LINK_OPTIONS mingw32 SDL2Main SDL2 SDL2_image)
    add_definitions(-DGLEW_STATIC)
else()
    find_package(SDL2 REQUIRED)
    include_directories(/usr/include/SDL2)
    set(LINK_OPTIONS SDL2 SDL2_image)
endif()


set(SOURCES
        src/main.cpp
        src/engine/Renderer.cpp
        src/engine/Game.cpp
        src/external/glew/glew.c
        src/engine/sdl2/GL_window.cpp
        src/engine/sdl2/SdlKeyEvent.cpp
        src/engine/sdl2/SDL_window.cpp
        src/graphics/Texture2d.cpp
        src/engine/EventHandler.cpp
        src/engine/sdl2/SDL_renderer.cpp src/engine/sdl2/SDL_texture.cpp src/engine/sdl2/SDL_surface.cpp src/pong/Paddle.cpp src/graphics/Color.cpp src/engine/sdl2/GameTimer.cpp)

if (OpenGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIR})
endif(OpenGL_FOUND)

file(MAKE_DIRECTORY Shaders)

file(COPY
        Shaders/vertex_shader.glsl
        Shaders/fragment_shader.glsl
DESTINATION Shaders)

file(COPY
${BINARIES}
DESTINATION .)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_executable(GLPong ${SOURCES})

if (WIN32)
    target_link_libraries(GLPong ${OPENGL_LIBRARY} ${SDL2_LIBRARIES} ${LINK_OPTIONS})
else()
    target_link_libraries(GLPong ${LINK_OPTIONS} ${OPENGL_LIBRARY} ${SDL2_LIBRARIES})
endif()
