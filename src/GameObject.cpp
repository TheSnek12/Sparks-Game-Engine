#include <GameObject.h>

namespace sparks
{
    void GameObject::setName(std::string name){
        this->name = name;
        if (parentScene){
            if (parentScene->nameExists(name)){
                logger::log(logger::LEVEL_WARN, "Ambiguous repeated game object names within a scene! Expect undefined behavior when referencing objects by name, if this is necessary, use object IDs");
            }
        }
    }
    std::string GameObject::getName(){
        return this->name;
    }
    
} // namespace sparks
