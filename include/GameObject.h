#pragma once
#include <string>
#include <vector>
#include "src/Base.h"
#include <Scriptables/Scriptable.h>

namespace sparks{
    class Scene;

    class Scriptable;
    typedef unsigned long ObjID;

    class GameObject{
    private:
    std::vector<Scriptable*> scriptables;
    bool running = false;
    std::string name = "unnamed";

    
            
    public:

    template <typename T>
    T* getScriptable (){
        for (Scriptable* script : scriptables){
            if(dynamic_cast<T*>(script) != nullptr){
                return dynamic_cast<T*>(script);
            }
        }
    }

    void addScriptable(Scriptable* script);
    Scene * parentScene = nullptr;
    ObjID _sceneID = 0;    
    void setName(std::string name);
    void tick();
    void init();
    std::string getName();
    ~GameObject();
    };
}