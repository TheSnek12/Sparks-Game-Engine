#include "../Renderer.h"
#include "OpenGLRenderEngine.h"

namespace s_Renderer
{
    OpenGLRenderEngine::OpenGLRenderEngine(Platform platform, uint16_t width, uint16_t height, GLADloadproc procAddr) :
    _platform(platform), _width(width), _height(height), _procAddr(procAddr){
        
    }
    OpenGLRenderEngine::OpenGLRenderEngine(Platform platform, uint16_t width, uint16_t height) :
    _platform(platform), _width(width), _height(height){
        
    }

    bool OpenGLRenderEngine::initRenderer(){

        if (_procAddr){
            if (!gladLoadGLLoader(_procAddr)){
                logger::log(logger::Level::LEVEL_ERROR, "Failed to load external OpenGLLoader! Falling back to default..");

                if (!gladLoadGL()){
                    logger::log(logger::Level::LEVEL_FATAL, "Also failed to load using default loader, is OpenGL installed correctly?");
                    return false;
                }
                
            }
        }else{
             
            if (!gladLoadGL()){
                    logger::log(logger::Level::LEVEL_FATAL, "Failure while loading OpenGL, is OpenGL installed correctly?");
                    return false;
            }
        }

        logger::log(logger::LEVEL_LOG, "Successfully initalized OpenGL renderer!");

        glViewport(0, 0, _width, _height);
        

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        


        return true;

    }

    void OpenGLRenderEngine::addObjectToQueue(RenderObject* renderObject){
        _objectQueue.push_back(renderObject);
    }

    void OpenGLRenderEngine::drawFrame(){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)_width/(float)_height, camera.near, camera.far );

        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 lookDir = glm::normalize(glm::vec3(camera.dir->x, camera.dir->y, camera.dir->z));
        glm::vec3 cameraRight = glm::normalize(glm::cross(up, lookDir));
        glm::vec3 cameraUp = glm::cross(lookDir, cameraRight);
        glm::vec3 cameraPos = glm::vec3(camera.pos->x, camera.pos->y, camera.pos->z);

        glm::mat4 view = glm::lookAt(
            cameraPos,
            cameraPos + lookDir,
            cameraUp
        );




        for (RenderObject *obj : _objectQueue){
            if (obj->shader->isCompiled()){
                obj->mesh->bind();
                obj->shader->bind();
                for (int i = 0; i < obj->textures.size(); i++)
                {
                    obj->textures[i].bind(i);
                }
                
                
                glm::vec3 pos = glm::vec3(obj->mesh->pos->x, obj->mesh->pos->y, obj->mesh->pos->z);
                glm::vec3 dir = glm::normalize(glm::vec3(obj->mesh->dir->x, obj->mesh->dir->y, obj->mesh->dir->z));
                glm::vec3 modelRight = glm::normalize(glm::cross(up, dir));
                glm::vec3 modelUp = glm::cross(dir, modelRight);

                
            

                glm::mat4 model = glm::mat4(1.0f);
                model = glm::translate(model, pos);

                model = (glm::lookAt(pos, dir+pos, glm::vec3(0.f, 1.f, 0.f)));

                float roll = *obj->mesh->roll * M_PI*2;
                model = glm::rotate(model, roll, dir);
                
                int projLoc = glGetUniformLocation(obj->shader->getID(), "projection");
                glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
                int matLoc = glGetUniformLocation(obj->shader->getID(), "model");
                glUniformMatrix4fv(matLoc, 1, GL_FALSE, glm::value_ptr(model));
                int viewLoc = glGetUniformLocation(obj->shader->getID(), "view");
                glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
                            
                glDrawElements(GL_TRIANGLES, obj->mesh->getIndicSize(), GL_UNSIGNED_INT, (void*)0);
        
                
            }

        }
        _objectQueue.clear();
        

    }


    bool OpenGLRenderEngine::destroyRenderer(){
        return true;
    }
    

    Renderer OpenGLRenderEngine::rendererType(){
        return OpenGL;
    }

    void OpenGLRenderEngine::setCamera(Cam cam){
        this->camera = cam;
    }






} // namespace s_Renderer
