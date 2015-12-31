cmake_minimum_required(VERSION 3.2)
project(common)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message("64 bit compiler")
    set(EX_PLATFORM 64)
    set(EX_PLATFORM_NAME "x64")
else(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message("32 bit compiler")
    set(EX_PLATFORM 32)
    set(EX_PLATFORM_NAME "x86")
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)

find_package(OpenGL REQUIRED)

if (WIN32)
    if(EX_PLATFORM EQUAL 64)
        include_directories(SDL2/x86_64-w64-mingw32/include/SDL2)
        link_directories(gamelib/SDL2/x86_64-w64-mingw32/lib)
        set(BINARIES SDL2/x86_64-w64-mingw32/bin/SDL2.dll)
    else(EX_PLATFORM EQUAL 64)
        include_directories(SDL2/i686-w64-mingw32/include/SDL2)
        link_directories(gamelib/SDL2/i686-w64-mingw32/lib)
        set(BINARIES SDL2/i686-w64-mingw32/bin/SDL2.dll)
    endif(EX_PLATFORM EQUAL 64)

    set(LINK_OPTIONS mingw32 SDL2Main SDL2 SDL2_image glm)

else()
    include_directories(/usr/include/SDL2)
    set(LINK_OPTIONS SDL2 SDL2_image glm)
    find_package(SDL2 REQUIRED)
endif()

set(SOURCES
        src/engine/Renderer.cpp
        src/engine/Game.cpp
        external/GL/glew.c
        src/engine/sdl2/GL_window.cpp
        src/engine/sdl2/Key_event.cpp
        src/engine/sdl2/SDL_window.cpp
        src/engine/graphics/Texture2d.cpp
        src/engine/EventHandler.cpp
        src/engine/sdl2/SDL_renderer.cpp
        src/engine/sdl2/SDL_texture.cpp
        src/engine/sdl2/SDL_surface.cpp
        src/engine/graphics/Color.cpp
        src/engine/GameTimer.cpp include/engine/physics2d/BoxCollider.h src/engine/physics2d/BoxCollider.cpp)

if (OpenGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIR})
endif(OpenGL_FOUND)

file(MAKE_DIRECTORY ../lib)
file(MAKE_DIRECTORY Shaders)

file(COPY
        Shaders/vertex_shader.glsl
        Shaders/fragment_shader.glsl
DESTINATION Shaders)

set(CMAKE_STATIC_LIBRARY_PREFIX "../lib/lib")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(external/glm)
add_library(common ${SOURCES})

target_include_directories(common PUBLIC
        include
        include/engine
        external
        external/glm)

if (WIN32)
    target_link_libraries(common ${OPENGL_LIBRARY} ${SDL2_LIBRARIES} ${LINK_OPTIONS})
else()
    target_link_libraries(common ${LINK_OPTIONS} ${OPENGL_LIBRARY} ${SDL2_LIBRARIES})
endif()
