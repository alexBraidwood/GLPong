//
// Created by Maddog on 11/3/2015.
//

#ifndef FIREENGINE_TEXTURES_H_H
#define FIREENGINE_TEXTURES_H_H

#include <memory>
#include "external/graphics/SOIL.h"

namespace engine {
namespace graphics {

template <typename T>
std::unique_ptr<T> LoadTexture(const std::string& path) const {
    int width;
    int height;

    auto image = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    T::create(image);
}

}

}

#endif //FIREENGINE_TEXTURES_H_H
