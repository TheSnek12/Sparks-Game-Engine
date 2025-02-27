#pragma once
#include "src/Base.h"
#include "GameObject.h"
#include <vector>
#include <queue>

namespace sparks
{
    typedef unsigned long ObjID;
    class GameObject;

    class Scene
    {
    private:
        const char *name;
        std::vector<GameObject*> sceneObjects;
        

    public:
        ObjID addObject(GameObject* obj);
        bool nameExists(std::string name);
        void removeObject(ObjID objID);
        void removeObject(std::string objName);
        GameObject* getObject(ObjID ObjID);
        GameObject* getObject(std::string objName);
        void update();

    };

}
