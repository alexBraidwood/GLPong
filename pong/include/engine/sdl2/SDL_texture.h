//
// Created by Maddog on 12/6/2015.
//

#ifndef GLPONG_SDL_TEXTURE_H
#define GLPONG_SDL_TEXTURE_H

#include <sdl.h>
#include <string>

namespace engine {
namespace sdl2 {
class SDL_texture {
    SDL_Texture* texture_handle;
    std::string image_path_;

    // Texture-specific code
public:
    void image_path(const std::string& path);
    const std::string& image_path();

    // RAII and initialization code
public:
    SDL_texture(SDL_Texture* handle);
    virtual ~SDL_texture();

    SDL_Texture* get() const;
    void reset(SDL_Texture* renderer);

    SDL_texture(const SDL_texture&) = delete;
    SDL_texture& operator=(const SDL_texture&) = delete;

    SDL_texture(SDL_texture&&);
    SDL_texture& operator=(SDL_texture&&);
};
}
}
#endif //GLPONG_SDL_TEXTURE_H
