#pragma once
#include <Vec3.h>
namespace s_Audio
{
    struct Listener{
        float* gain;
        Vec3* pos;
        Vec3* vel;
        Vec3* dir;
        Vec3* up;
    };
} // namespace s_Audio
