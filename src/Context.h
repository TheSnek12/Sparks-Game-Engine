#ifndef HCONTEXT
#define HCONTEXT
#include <Game.h>
#include "IContext.h"
#include "Renderer/OpenGLRenderEngine.h"
#include "GWindow.h"

using namespace s_Renderer;
namespace sparks
{

    class Game;

    class GWindow;
    class Window;



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
#endif