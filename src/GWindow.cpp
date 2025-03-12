#include "GWindow.h"
#include "Game.h"

namespace sparks
{
    double lastX = 400, lastY = 300;
    void mouse_callback(GLFWwindow *window, double xpos, double ypos)
    {
        double xoffset = xpos - lastX;
        double yoffset = lastY - ypos; // reversed since y-coordinates range from bottom to top
        lastX = xpos;
        lastY = ypos;

        Game::getInstance()->onMouseMove(xoffset, yoffset);
    }
    void keyboard_callback(GLFWwindow *window, int key, int scancode, int action, int modifiers)
    {
        if (keyMap.find(key) != keyMap.end())
        {
            Keys m_key = keyMap.at(key);

            switch (action)
            {
            case GLFW_RELEASE:
                Game::getInstance()->onKeyRelease(m_key);
                break;
            case GLFW_PRESS:
                Game::getInstance()->onKeyPress(m_key);
                break;
            default:
                break;
            }
        }
    }

    GWindow::GWindow(IContext *context, uint16_t width, uint16_t height, const char *title) : Window(context, width, height, title) {}
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
        glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glfwSetCursorPosCallback(_window, mouse_callback);
        glfwSetKeyCallback(_window, keyboard_callback);
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
            Game::getInstance()->exitPressed();
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

    Window::procAddr GWindow::getGLProcAddr()
    {
        return (Window::procAddr)glfwGetProcAddress;
    }

    Window::procAddr GWindow::getVKProcAddr()
    {
        return nullptr;
    }
    void GWindow::resize(uint16_t width, uint16_t height)
    {
        this->width = width;
        this->height = height;
        glfwSetWindowSize(_window, width, height);
    }
}