#pragma once
#include "Window.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace sparks
{
    class GWindow : public Window
    {

    public:
        bool initWindow() override;
        bool destroyWindow() override;
        void pollWindowEvents() override;
        procAddr getGLProcAddr() override;
        procAddr getVKProcAddr() override;

        GWindow(IContext *context);

    private:

        GLFWwindow *_window;
    };
} // namespace sparks