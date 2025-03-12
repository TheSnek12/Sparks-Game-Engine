#ifndef HBASE
#define HBASE

#include <cassert>
#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdio>
#include <glm/vec3.hpp>
#include <Logger/Logger.h>
#include <glm/vec3.hpp>

namespace sparks
{
    enum WindowType
    {
        GLFW,
    };
    enum Platform{
        LINUX,
        WINDOWS,
        MACOS,
//      MOBILE
    };

    enum Keys{
        KEY_ONE,
        KEY_TWO,
        KEY_THREE,
        KEY_FOUR,
        KEY_FIVE,
        KEY_SIX,
        KEY_SEVEN,
        KEY_EIGHT,
        KEY_NINE,
        KEY_ZERO,
        TILDE,
        MINUS,
        EQUALS,
        TAB,
        Q,
        W,
        E,
        R,
        T,
        Y,
        U,
        I,
        O,
        P,
        LEFT_BRACKET,
        RIGHT_BRACKET,
        BACKSLASH,
        A,
        S,
        D,
        F,
        G,
        H,
        J,
        K,
        L,
        SEMICOLON,
        QUOTE,
        Z,
        X,
        C,
        V,
        B,
        N,
        M,
        COMMA,
        PERIOD,
        SLASH,
        ARROW_LEFT,
        ARROW_RIGHT,
        ARROW_UP,
        ARROW_DOWN

    };

    static Platform PLATFORM;
    static WindowType WINDOWTYPE;
}

#endif