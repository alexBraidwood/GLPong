//
// Created by alex on 12/12/15.
//

#ifndef GLPONG_COLOR_H
#define GLPONG_COLOR_H

namespace engine {
    namespace graphics {

        using byte = unsigned char;

        struct Color {
            /**
             * /fn Constructs default Color object (white, full alpha)
             */
            explicit Color()
                    : r(255), g(255), b(255), a(255) {}

            /**
             * /fn Constructs full alpha Color object
             */
            Color(byte red, byte green, byte blue)
                    : r(red), g(green), b(blue), a(255) {}

            /**
             * /fn Fully customized color object constructor
             */
            Color(byte red, byte green, byte blue, byte alpha)
                    : r(red), g(green), b(blue), a(alpha) {}

            byte r;
            byte g;
            byte b;
            byte a;

            static Color red();
            static Color blue();
            static Color green();
            static Color white();
        };
    }
}

#endif //GLPONG_COLOR_H
