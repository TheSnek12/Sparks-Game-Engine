#include "include/Game.h"
namespace sparks
{
    Game::Game()
    {
        assert(_instance == nullptr);

        _instance = this;
    }

    bool Game::run(){
        init();
        if (!_name) {
            logger::log(logger::LEVEL_WARN, "No name set within init(), using default");
            setName("Untitled");
        }
        if (_width >= 0 || _height >= 0){
            logger::log(logger::LEVEL_WARN, "No or invalid geometry set, both width and height must be <0. Using default 200x200");
            setGeometry(1, 1);
        }
        return true;
    }

    void Game::init(){

    }

    Game::~Game()
    {

        _instance = nullptr;
    }
    Game *Game::getInstance()
    {
        return _instance;
    }

    void Game::update(){

    }

    void Game::setName(const char * name){
        _name = name;
    }
    const char * Game::getName(){
        return _name;
    }

    void Game::frame(){
        update();

    }

    u_int16_t Game::getWidth(){
        return _width;
    }
    u_int16_t Game::getHeight(){
        return _height;
    }
    void Game::setGeometry(u_int16_t w, u_int16_t h){
        _width = w;
        _height = h;
    } 

    void Game::handleAbort(){
        Context::getContext()->abort();
    }
    void Game::handleClose(){
        Context::getContext()->close();
    }
    void Game::abort(){
        handleAbort();
    }
    void Game::close(){
        handleClose();
    }

}