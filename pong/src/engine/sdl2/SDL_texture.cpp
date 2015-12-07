//
// Created by Maddog on 12/6/2015.
//

#include <sdl2/SDL_texture.h>

using namespace engine::sdl2;
using namespace engine::graphics;

auto SDL_texture::create(const std::string& path, const Rect& source,
        const Rect& destination) -> std::unique_ptr<SDL_texture>
{
    
}

auto SDL_texture::set_image(const std::string& path, const Rect& sourceRect,
        const Rect& destRect) -> void
{
    image_path_ = path;
    source_rectangle = sourceRect;
    destination_rectangle = destRect;
}

SDL_texture::SDL_texture(SDL_Texture* handle)
    : texture_handle{handle} {}

SDL_texture::~SDL_texture()
{
    if (texture_handle != nullptr) {
        SDL_DestroyTexture(texture_handle);
    }
}

auto SDL_texture::get() const -> SDL_Texture*
{
    return texture_handle;
}

auto SDL_texture::reset(SDL_Texture* texture) -> void
{
    texture_handle = texture;
}

SDL_texture::SDL_texture(SDL_texture&& texture)
{
    if (this != &texture) {
        this->texture_handle = texture.get();
        texture.reset(nullptr);
    }
}

auto SDL_texture::operator=(SDL_texture&& texture) -> SDL_texture&
{
    if (this != &texture) {
        this->texture_handle = texture.get();
        texture.reset(nullptr);
    }
    return *this;
}