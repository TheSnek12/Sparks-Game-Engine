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

        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        OpenGLMesh gmesh(nullptr, 12, nullptr, 12);


        return true;

    }

    void OpenGLRenderEngine::addObjectToQueue(){
        
    }

    void OpenGLRenderEngine::drawFrame(){
        glClear(GL_COLOR_BUFFER_BIT);


    }


    bool OpenGLRenderEngine::destroyRenderer(){
        return true;
    }
    

    Renderer OpenGLRenderEngine::rendererType(){
        return OpenGL;
    }






} // namespace s_Renderer
