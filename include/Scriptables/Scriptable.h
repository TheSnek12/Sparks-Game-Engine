#pragma once
#include <GameObject.h>


namespace sparks
{
    class GameObject;
    class Scriptable {
        
        private:

        public:
        GameObject* object;
        virtual ~Scriptable() {
            object = nullptr;
            enabled = false;
        };
        virtual void onStart() = 0;
        virtual void onTick() = 0;
        bool enabled = true;
        GameObject* getObject() {return object;};



    };
} // namespace sparks
