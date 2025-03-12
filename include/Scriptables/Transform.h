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
        float roll;
        Vec3 rotation;
    };
} // namespace sparks
