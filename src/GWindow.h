#pragma once
#include "Window.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <map>
namespace sparks
{
    static const std::map<int, Keys> keyMap = {
        {GLFW_KEY_1, KEY_ONE},
        {GLFW_KEY_2, KEY_TWO},
        {GLFW_KEY_3, KEY_THREE},
        {GLFW_KEY_4, KEY_FOUR},
        {GLFW_KEY_5, KEY_FIVE},
        {GLFW_KEY_6, KEY_SIX},
        {GLFW_KEY_7, KEY_SEVEN},
        {GLFW_KEY_8, KEY_EIGHT},
        {GLFW_KEY_9, KEY_NINE},
        {GLFW_KEY_0, KEY_ZERO},
        {GLFW_KEY_GRAVE_ACCENT, TILDE},
        {GLFW_KEY_MINUS, MINUS},
        {GLFW_KEY_TAB, TAB},
        {GLFW_KEY_EQUAL, EQUALS},
        {GLFW_KEY_Q, Q},
        {GLFW_KEY_W, W},
        {GLFW_KEY_E, E},
        {GLFW_KEY_R, R},
        {GLFW_KEY_T, T},
        {GLFW_KEY_Y, Y},
        {GLFW_KEY_U, U},
        {GLFW_KEY_I, I},
        {GLFW_KEY_O, O},
        {GLFW_KEY_P, P},
        {GLFW_KEY_LEFT_BRACKET, LEFT_BRACKET},
        {GLFW_KEY_RIGHT_BRACKET, RIGHT_BRACKET},
        {GLFW_KEY_BACKSLASH, BACKSLASH},
        {GLFW_KEY_A, A},
        {GLFW_KEY_S, S},
        {GLFW_KEY_D, D},
        {GLFW_KEY_F, F},
        // finish this sometime later, i cant be bothered right now

    };
    class GWindow : public Window
    {
    public:
        bool initWindow() override;
        bool destroyWindow() override;
        void pollWindowEvents() override;
        bool prepareForRenderer(s_Renderer::Renderer renderEngine) override;
        procAddr getGLProcAddr() override;
        procAddr getVKProcAddr() override;
        void resize(uint16_t width, uint16_t height) override;

        GWindow(IContext *context, uint16_t width, uint16_t height, const char *title);

    private:
        GLFWwindow *_window;
    };
} // namespace sparks