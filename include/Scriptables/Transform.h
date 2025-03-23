#pragma once
#include <Scriptables/Scriptable.h>
#include <Vec3.h>

namespace sparks
{
    class Transform : public Scriptable {
        

        public:
        void onStart() override {};
        void onTick() override {};
        ~Transform() override{
            
        };
        Vec3 position;
        Vec3 scale = Vec3(1, 1, 1);
        float roll;
        Vec3 rotation = Vec3(0, 0, 1);
    };
} // namespace sparks
