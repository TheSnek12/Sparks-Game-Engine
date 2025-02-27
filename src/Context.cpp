#include "Context.h"

namespace sparks
{
    bool Context::init()
    {
        logger::log(logger::LEVEL_LOG, "Initializing..");
        if (!_game->run())
        {
            logger::log(logger::LEVEL_FATAL, "Game failed to launch");
            return false;
        }
        if (!_window->prepareForRenderer(s_Renderer::OpenGL))
        {
            logger::log(logger::LEVEL_FATAL, "Failed while preparing window for renderer!");
            return false;
        }
        if (!_window->initWindow())
        {
            logger::log(logger::LEVEL_FATAL, "Failed to initialize window");
            return false;
        }
        if (!_renderer->initRenderer())
        {
            logger::log(logger::LEVEL_FATAL, "Failed to initialize renderer");
            return false;
        }

        logger::log(logger::LEVEL_LOG, "Finished initialization");

        return true;
    }

    bool Context::cleanup()
    {

        logger::log(logger::LEVEL_LOG, "Shutting down engine..");
        if (!_renderer->destroyRenderer())
        {
            logger::log(logger::LEVEL_ERROR, "Failed to cleanly destroy renderer");
            return false;
        }
        if (!_window->destroyWindow())
        {
            logger::log(logger::LEVEL_ERROR, "Failed to cleanly destroy window");
            return false;
        }
        return true;
    }

    void Context::messageLoop()
    {
        // do some preparations
        if (_state == PREINIT)
        {

            if (!init())
            {
                logger::log(logger::LEVEL_FATAL, "Failed to initialize context");
                throw std::runtime_error("Init failed!");
            }
            _state = RUNNING;
        }
        while (_state == RUNNING)
        {
            _game->frame();

            _renderer->drawFrame();

            _window->pollWindowEvents();
        }
        if (_state == ABORTING)
        {
            logger::log(logger::LEVEL_FATAL, "Received ABORT from game");
            throw std::runtime_error("Game aborted unexpectedly!");
        }

        if (!cleanup())
        {
            logger::log(logger::LEVEL_ERROR, "Errors occurred during clean up!");
        }
    }

    Context::Context() : _state(PREINIT), _game(Game::getInstance())
    {

        if (WINDOWTYPE == GLFW)
        {

            static GWindow window = GWindow(this, Game::getInstance()->getWidth(), Game::getInstance()->getHeight(), Game::getInstance()->getName());
            _window = &window;
        }

        selectEngine(OpenGL);

        assert(_instance == nullptr);
        _instance = this;

        messageLoop();
    }

    void Context::selectEngine(Renderer renderer)
    {
        s_Renderer::Platform rplatform;

        switch (PLATFORM)
        {
        case LINUX:
            rplatform = s_Renderer::LINUX;
            break;
        case WINDOWS:
            rplatform = s_Renderer::WINDOWS;
            break;
        case MACOS:
            rplatform = s_Renderer::MACOS;
            break;
        default:
            rplatform = s_Renderer::LINUX;
            break;
        }

        if (_renderer != nullptr)
        {
            if (_renderer->destroyRenderer())
            {
                logger::log(logger::LEVEL_ERROR, "Failed to cleanly shut down old engine");
            }
        }
        switch (renderer)
        {
        case OpenGL:
            static OpenGLRenderEngine renderer = OpenGLRenderEngine(rplatform, _game->getWidth(), _game->getHeight(), (GLADloadproc)_window->getGLProcAddr());
            _renderer = &renderer;

            break;
        }
    }

    void Context::abort()
    {
        _state = ABORTING;
    }
    void Context::close()
    {
        _state = CLOSING;
    }

    Context *Context::getContext()
    {
        return _instance;
    }

} // namespace sparks
