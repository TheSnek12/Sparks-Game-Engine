#ifndef HBASE
#define HBASE

#include <cassert>
#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdio>
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

    static Platform PLATFORM;
    static WindowType WINDOWTYPE;
}

#endif