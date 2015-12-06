//
// Created by Maddog on 11/3/2015.
//

#ifndef FIREENGINE_TEXTURE_H
#define FIREENGINE_TEXTURE_H

#include <memory>

namespace engine {
namespace graphics {

class Texture2d {
public:
    static std::unique_ptr<Texture2d> create(unsigned char* data);
};

}
}

#endif //FIREENGINE_TEXTURE_H
