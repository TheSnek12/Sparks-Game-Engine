#pragma once
#include <Scriptables/Scriptable.h>
#include <Vec3.h>

namespace sparks
{
    class Transform : public Scriptable {
        public:
        Vec3 position;
        Vec3 up;
        Vec3 lookDir;
    };
} // namespace sparks
