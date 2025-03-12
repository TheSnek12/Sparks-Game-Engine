#pragma once
#include <Logger/Logger.h>
#include <glm/vec3.hpp>
#include <glm/matrix.hpp>
#include <glm/common.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace s_Renderer
{

    enum Platform
    {
        LINUX,
        WINDOWS,
        MACOS,
        //  MOBILE
    };
    enum Renderer
    {
        OpenGL
    };

}