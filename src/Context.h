#pragma once
#include <Game.h>
#include "IContext.h"
#include "Renderer/OpenGL/OpenGLRenderEngine.h"
#include "GWindow.h"
#include "Base.h"

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
        void sendToRenderPool(s_Renderer::RenderObject* renderObj) override;
        s_Renderer::Renderer engineType() override;
        void setActiveCamera(s_Renderer::Cam cam) override;
        void close() override;
        void abort() override;
        void selectEngine(Renderer renderer) override;
        void resize(uint16_t width, uint16_t height) override;
        void addDirLight(s_Renderer::DirLight);
        void removeDirLight(s_Renderer::DirLight);
        void addPointLight(s_Renderer::PointLight);
        void removePointLight(s_Renderer::PointLight);
        void addSpotLight(s_Renderer::SpotLight);
        void removeSpotLight(s_Renderer::SpotLight);
        

        Context();
    };
    

} // namespace sparks