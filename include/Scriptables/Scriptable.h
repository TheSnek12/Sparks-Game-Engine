#pragma once
#include <GameObject.h>


namespace sparks
{
    class GameObject;
    class Scriptable {
        
        public:
        virtual void onStart() = 0;
        virtual void onTick() = 0;
        GameObject* getObject() {return object;};
        private:
        GameObject* object;



    };
} // namespace sparks
