#include <GameObject.h>

namespace sparks
{
    void GameObject::setName(std::string name){
        this->name = name;
        if (parentScene){

        }
    }
    void GameObject::tick(){
        for (Scriptable *script : scriptables){
            if (script->enabled){
                script->onTick();
            }
        }
    }

    void GameObject::init(){
        for (Scriptable *script : scriptables){
            if (script->enabled){
            
                script->onStart();
            }
        }
        running = true;
    }
    void GameObject::addScriptable(Scriptable* script){
        script->object = this;
        scriptables.push_back(script);
        if (running) script->onStart();
    }
    std::string GameObject::getName(){
        return this->name;
    }
    GameObject::~GameObject(){
        for (Scriptable *script : scriptables){
            delete script;
        }
        parentScene = nullptr;
    }
    
} // namespace sparks
