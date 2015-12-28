//
// Created by Maddog on 12/6/2015.
//

#ifndef GLPONG_SDL_TEXTURE_H
#define GLPONG_SDL_TEXTURE_H

#include <memory>
#include <string>
#include <engine/graphics/Rect.h>

struct SDL_Texture;

namespace engine {
namespace sdl2 {
class SDL_texture {
    SDL_Texture* texture_handle;
    graphics::Rect source_rectangle;
    graphics::Rect destination_rectangle;
    std::string image_path_;

    // Texture-specific code
public:
    void set_image(
            const std::string& path,
            const graphics::Rect& sourceRect,
            const graphics::Rect& destRect);

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
            const graphics::Rect& source,
            const graphics::Rect& destination);
};
}
}
#endif //GLPONG_SDL_TEXTURE_H
