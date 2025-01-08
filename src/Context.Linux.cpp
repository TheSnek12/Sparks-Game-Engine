#include "Context.h"
#include <GLFW/glfw3.h>
namespace sparks {

    bool Context::initWindow() {
        if (!glfwInit()){
            
            const char *e;
            glfwGetError(&e);
            logger::log(logger::LEVEL_FATAL, e);
            logger::log(logger::LEVEL_FATAL, "Failed to initalize GLFW library!");
            return false;
        }
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        _window = glfwCreateWindow(Game::getInstance()->getWidth(), Game::getInstance()->getHeight(), Game::getInstance()->getName(), nullptr, nullptr);
        if (!_window){
            
            const char *e;
            glfwGetError(&e);
            logger::log(logger::LEVEL_FATAL, e);
            logger::log(logger::LEVEL_FATAL, "Failed to initalize GLFW window!");
            return false;
        }
        glfwMakeContextCurrent(_window); 
        logger::log(logger::LEVEL_LOG, "Successfully created GLFW window!");
        return true;



    }

    bool Context::destroyWindow() {
        glfwDestroyWindow(_window);
        glfwTerminate();
        logger::log(logger::LEVEL_LOG, "Successfully destroyed window!");
        return true;
    }

    void Context::pollWindowEvents() {
        glfwPollEvents();
        
        glfwSwapBuffers(_window);
        if (glfwWindowShouldClose(_window)){
            close();
        }
    }

}