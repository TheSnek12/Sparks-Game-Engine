#include "GWindow.h"

namespace sparks
{

    GWindow::GWindow(IContext *context, uint16_t width, uint16_t height, const char* title) :
    Window(context, width, height, title) {}
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
        _window = glfwCreateWindow(width, height, title, nullptr, nullptr);
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
        glfwSwapBuffers(_window);
        glfwPollEvents();
        if (glfwWindowShouldClose(_window))
        {
            _context->close();
        }
    }

    bool GWindow::prepareForRenderer(s_Renderer::Renderer renderEngine)
    {
        switch (renderEngine)
        {
        case OpenGL:
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
            break;
        
        default:
            return false;
            break;
        }

        return true;
    }

    Window::procAddr GWindow::getGLProcAddr(){
        return (Window::procAddr)glfwGetProcAddress;
    }

    Window::procAddr GWindow::getVKProcAddr(){
        return nullptr;
    }
}