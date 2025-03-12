#include <Scene.h>
namespace sparks
{
    ObjID Scene::addObject(GameObject* obj){

        ObjID id = 0;
        for (GameObject* o: sceneObjects){
            if (o->_sceneID > id) 
                id = o->_sceneID; 
            if(o->getName() == obj->getName()) 
                logger::log(logger::LEVEL_WARN, "Ambiguous repeated game object names within a scene! Expect undefined behavior when referencing objects by name, if this is necessary, use object IDs");
        }
        id++;
        sceneObjects.push_back(obj);
        obj->_sceneID = id;
        obj->parentScene = this;
        
        if (running) obj->init();

        return id;

    }
    
    bool Scene::nameExists(std::string name){
        for (GameObject* o: sceneObjects){
            if(o->getName() == name){
                return true;
            } 
        }
        return false;

    }

    void Scene::removeObject(ObjID objID){
        for (ObjID i = 0; i < sceneObjects.size(); i++)
        {
            if (sceneObjects[i]->_sceneID == objID){
                sceneObjects.erase(sceneObjects.begin()+i);
                return;
            }
        }
        
    }
    void Scene::removeObject(std::string objName){
        for (ObjID i = 0; i < sceneObjects.size(); i++)
        {
            if (sceneObjects[i]->getName() == objName){
                sceneObjects.erase(sceneObjects.begin()+i);
                return;
            }
        }
        
    }
    GameObject* Scene::getObject(ObjID objID){
        for (ObjID i = 0; i < sceneObjects.size(); i++)
        {
            if (sceneObjects[i]->_sceneID == objID){
                return sceneObjects[i];
            }
        }
        
    }
    GameObject* Scene::getObject(std::string objName){
        for (ObjID i = 0; i < sceneObjects.size(); i++)
        {
            if (sceneObjects[i]->getName() == objName){
                return sceneObjects[i];
            }
        }
        
    }
    void Scene::update(){
        for (GameObject *obj : sceneObjects){
            obj->tick();
        }
    }
    void Scene::start(){
        for (GameObject *obj : sceneObjects){
            obj->init();
        }
        
        Context::getContext()->setActiveCamera(activeCamera->cam);
        running = true;

    }
    Scene::~Scene(){
        for (GameObject* obj: sceneObjects){
            delete obj;
        }
    }


} // namespace sparks
