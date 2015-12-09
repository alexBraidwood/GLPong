//
// Created by Maddog on 12/9/2015.
//

#ifndef GLPONG_GAMEOBJECTBASE_H
#define GLPONG_GAMEOBJECTBASE_H

namespace engine {
class Game_object_base {
public:
    virtual auto do_update() -> void = 0;
    virtual auto do_draw() -> void = 0;
};
}

#endif //GLPONG_GAMEOBJECTBASE_H
