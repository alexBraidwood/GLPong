//
// Created by Maddog on 12/6/2015.
//

#ifndef GLPONG_SDL_TEXTURE_H
#define GLPONG_SDL_TEXTURE_H

#include <SDL.h>
#include <memory>
#include <string>
#include <graphics/Rect.h>

namespace engine {
namespace sdl2 {
class SDL_texture {
    SDL_Texture* texture_handle;
    Rect source_rectangle;
    Rect destination_rectangle;
    std::string image_path_;

    // Texture-specific code
public:
    void set_image(
            const std::string& path,
            const Rect& sourceRect = nullptr,
            const Rect& destRect = nullptr);

    const std::string& image_path();

    // RAII and initialization code
public:
    SDL_texture(SDL_Texture* handle);
    virtual ~SDL_texture();

    SDL_Texture* get() const;
    void reset(SDL_Texture* texture);

    SDL_texture(const SDL_texture&) = delete;
    SDL_texture& operator=(const SDL_texture&) = delete;

    SDL_texture(SDL_texture&&);
    SDL_texture& operator=(SDL_texture&&);

    static std::unique_ptr<SDL_texture> create(const std::string& path,
            const Rect& source = nullptr,
            const Rect& destination = nullptr);
};
}
}
#endif //GLPONG_SDL_TEXTURE_H
