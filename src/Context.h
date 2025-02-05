#pragma once
#include <Game.h>
#include "IContext.h"
#include "Renderer/OpenGL/OpenGLRenderEngine.h"
#include "GWindow.h"
#include "Base.h"
#include "src/Renderer/OpenGL/OpenGLMesh.h"
#include "src/Renderer/OpenGL/OpenGLShader.h"
#include "src/Renderer/RenderObject.h"

using namespace s_Renderer;
namespace sparks
{

    class Game;

    class Window;
    class GWindow;



    enum GameState
    {
        PREINIT,
        RUNNING,
        CLOSING,
        ABORTING

    };

    class Context final : IContext
    {
    private:
        inline static Context *_instance = nullptr;
        GameState _state;
        IRenderEngine *_renderer = nullptr;
        Window *_window = nullptr;
        Game *_game = nullptr;

        bool init() override;
        bool cleanup() override;
        void messageLoop();

    public:
        static Context *getContext();
        void close() override;
        void abort() override;
        void selectEngine(Renderer renderer) override;

        Context();
    };

} // namespace sparks