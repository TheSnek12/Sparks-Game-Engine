#include "GWindow.h"

namespace sparks
{

    GWindow::GWindow(IContext *context) : Window(context) {}
    bool GWindow::initWindow()
    {
        if (!glfwInit())
        {

            const char *e;
            glfwGetError(&e);
            logger::log(logger::LEVEL_FATAL, e);
            logger::log(logger::LEVEL_FATAL, "Failed to initalize GLFW library!");
            return false;
        }
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        _window = glfwCreateWindow(Game::getInstance()->getWidth(), Game::getInstance()->getHeight(), Game::getInstance()->getName(), nullptr, nullptr);
        if (!_window)
        {

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

    bool GWindow::destroyWindow()
    {
        glfwDestroyWindow(_window);
        glfwTerminate();
        logger::log(logger::LEVEL_LOG, "Successfully destroyed window!");
        return true;
    }

    void GWindow::pollWindowEvents()
    {
        glfwPollEvents();

        glfwSwapBuffers(_window);
        if (glfwWindowShouldClose(_window))
        {
            _context->close();
        }
    }

    Window::procAddr GWindow::getGLProcAddr(){
        return (Window::procAddr)glfwGetProcAddress;
    }

    Window::procAddr GWindow::getVKProcAddr(){
        return nullptr;
    }
}