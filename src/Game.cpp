#include <Game.h>
namespace sparks
{

    Game::Game()
    {
        assert(_instance == nullptr);

        _instance = this;
    }

    bool Game::run()
    {
        init();
        if (!_name)
        {
            logger::log(logger::LEVEL_WARN, "No name set within init(), using default");
            setName("Untitled");
        }
        if (_width <= 0 || _height <= 0)
        {
            logger::log(logger::LEVEL_WARN, "No or invalid geometry set, both width and height must be >0. Using default 200x200");
            setGeometry(200, 200);
        }
        #ifdef thing
        logger::log(logger::LEVEL_LOG, "haha")
        #endif

        return true;
    }

    void Game::init()
    {
    }

    Game::~Game()
    {

        _instance = nullptr;
    }
    Game *Game::getInstance()
    {
        return _instance;
    }

    void Game::update()
    {
    }

    void Game::setName(const char *name)
    {
        _name = name;
    }
    const char *Game::getName()
    {
        return _name;
    }

    void Game::frame()
    {
        update();
        if (activeScene != NULL)
        {
            activeScene->update();
        }
    }
    void Game::loadScene(Scene *scene)
    {
        activeScene = scene;
        scene->start();
    }

    u_int16_t Game::getWidth()
    {
        return _width;
    }
    u_int16_t Game::getHeight()
    {
        return _height;
    }
    void Game::setGeometry(uint16_t w, uint16_t h)
    {
        _width = w;
        _height = h;
        Context::getContext()->resize(w, h);
        
    }

    void Game::handleAbort()
    {
        delete activeScene;
        Context::getContext()->abort();
    }
    void Game::handleClose()
    {
        delete activeScene;
        activeScene = nullptr;
        Context::getContext()->close();
    }
    void Game::onMouseMove(double x, double y){

    }
    void Game::onKeyPress(Keys key){

    }
    void Game::onKeyRelease(Keys key){

    }
    void Game::abort()
    {
        handleAbort();
    }
    void Game::close()
    {
        handleClose();
    }
    void Game::exitPressed()
    {
        close();
    }

}