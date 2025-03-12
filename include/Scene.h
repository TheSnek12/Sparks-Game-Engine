#pragma once
#include "src/Base.h"
#include "GameObject.h"
#include "src/Context.h"
#include <Camera.h>
#include "src/Renderer/IRenderEngine.h"
#include <vector>
#include <queue>

namespace sparks
{
    typedef unsigned long ObjID;
    class GameObject;
    class Camera;

    class Scene
    {
    private:
        const char *name = "Untitled Scene";
        std::vector<GameObject*> sceneObjects;
        bool running = false;
        
        

    public:
        Camera * activeCamera;
        ObjID addObject(GameObject* obj);
        bool nameExists(std::string name);
        void removeObject(ObjID objID);
        void removeObject(std::string objName);
        GameObject* getObject(ObjID ObjID);
        GameObject* getObject(std::string objName);
        void update();
        void start();
        ~Scene();

    };

}
