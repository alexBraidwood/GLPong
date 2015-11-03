cmake_minimum_required(VERSION 3.2)
project(GLPong)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${GLPong_SOURCE_DIR}/cmake")

include_directories(include)
include_directories(include/engine)
include_directories(include/external)

find_package(OpenGL REQUIRED)

if (WIN32)
    include_directories(SDL2/i686-w64-mingw32/include/SDL2)
    set(BINARIES SDL2/i686-w64-mingw32/bin/SDL2.dll)
    link_directories(SDL2/i686-w64-mingw32/lib)
    link_directories(SOIL)
    set(LINK_OPTIONS mingw32 SDL2Main SDL2)
    add_definitions(-DGLEW_STATIC)
else()
    find_package(SDL2 REQUIRED)
    include_directories(/usr/include/SDL2)
    link_directories(SOIL)
    set(LINK_OPTIONS SDL2)
endif()


set(SOURCES
        src/main.cpp
        src/engine/Renderer.cpp
        src/engine/Game.cpp
        src/external/glew/glew.c
        src/engine/sdl2/GL_window.cpp
        src/engine/sdl2/SdlKeyEvent.cpp
        include/engine/graphics/Rect.h
        include/engine/sdl2/ListenerType.h
        include/engine/sdl2/EventType.h
        include/engine/sdl2/SdlKeyEvent.h
        include/engine/events/Subject.h
        include/engine/sdl2/GL_window.h
        include/external/GL/glew.h
        include/external/GL/glxew.h
        include/external/GL/wglew.h
        include/engine/Renderer.h
        include/engine/Game.h
        include/external/graphics/SOIL.h
        include/engine/sdl2/Keycode.h
        include/engine/sdl2/SDL_window.h
        src/engine/sdl2/SDL_window.cpp
        src/graphics/Texture2d.cpp
        include/engine/graphics/Texture2d.h
        include/engine/graphics/Textures.h)

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
add_library(GLPongTest ${SOURCES})
if (WIN32)
    target_link_libraries(GLPong ${OPENGL_LIBRARY} ${SDL2_LIBRARIES} ${LINK_OPTIONS})
else()
    target_link_libraries(GLPong ${LINK_OPTIONS} ${OPENGL_LIBRARY} ${SDL2_LIBRARIES})
endif()
