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
        bool prepareForRenderer(s_Renderer::Renderer renderEngine) override;
        procAddr getGLProcAddr() override;
        procAddr getVKProcAddr() override;

        GWindow(IContext *context, uint16_t width, uint16_t height, const char* title);

    private:

        GLFWwindow *_window;
    };
} // namespace sparks