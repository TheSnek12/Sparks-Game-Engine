#pragma once
#include <string>
#include <vector>
#include <Scriptables/Scriptable.h>
#include <Scene.h>

namespace sparks{
    class Scene;
    class Scriptable;
    typedef unsigned long ObjID;

    class GameObject{
    private:
    std::string name = "unnamed";

    
            
    public:
    std::vector<Scriptable*> scriptables;
    Scene * parentScene = nullptr;
    ObjID _sceneID = 0;    
    void setName(std::string name);
    std::string getName();
    };
}