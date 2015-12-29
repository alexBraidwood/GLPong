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

include_directories(include)
include_directories(include/engine)
include_directories(include/external)

find_package(OpenGL REQUIRED)

set(LINK_OPTIONS SDL2 SDL2_image)

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

    set(LINK_OPTIONS "mingw32 SDL2Main ${LINK_OPTIONS}")

else()
    include_directories(/usr/include/SDL2)
    find_package(SDL2 REQUIRED)
endif()

set(HEADERS
        # Engine Core
        include/engine/EventHandler.h
        include/engine/Game.h
        include/engine/GameObject.h
        include/engine/GameTimer.h
        include/engine/Renderer.h

        # Drawing and Graphics
        include/engine/graphics/Circle.h
        include/engine/graphics/Color.h
        include/engine/graphics/Rect.h
        include/engine/graphics/Texture2d.h

        # Physics (2d and 3d)
        include/engine/physics/Collider.h

        # SDL2 Wrappers
        include/engine/sdl2/Event_type.h
        include/engine/sdl2/Keycode.h
        include/engine/sdl2/Listener_type.h
        include/engine/sdl2/SDL_renderer.h
        include/engine/sdl2/SDL_surface.h
        include/engine/sdl2/SDL_texture.h
        include/engine/sdl2/SDL_window.h
        include/engine/sdl2/Key_event.h)

set(SOURCES
        src/engine/Renderer.cpp
        src/engine/Game.cpp
        src/external/glew/glew.c
        src/engine/sdl2/GL_window.cpp
        src/engine/sdl2/Key_event.cpp
        src/engine/sdl2/SDL_window.cpp
        src/graphics/Texture2d.cpp
        src/engine/EventHandler.cpp
        src/engine/sdl2/SDL_renderer.cpp
        src/engine/sdl2/SDL_texture.cpp
        src/engine/sdl2/SDL_surface.cpp
        src/graphics/Color.cpp
        src/engine/GameTimer.cpp)

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

add_library(common ${SOURCES} ${HEADERS})

if (WIN32)
    target_link_libraries(common ${OPENGL_LIBRARY} ${SDL2_LIBRARIES} ${LINK_OPTIONS})
else()
    target_link_libraries(common ${LINK_OPTIONS} ${OPENGL_LIBRARY} ${SDL2_LIBRARIES})
endif()
