#pragma once
#include <Scriptables/Scriptable.h>
#include <Vec3.h>

namespace sparks
{
    class Transform : public Scriptable {
        

        public:
        void onStart() override {};
        void onTick() override {
            up = position.cross(Vec3(0, 1, 0).cross(position));
        };
        ~Transform() override{
            
        };
        Vec3 position;
        Vec3 up;
        float roll;
        Vec3 rotation;
    };
} // namespace sparks
