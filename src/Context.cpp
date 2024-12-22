#include "Context.h"

namespace sparks
{


    bool Context::initRenderer() {
        return true;
    }
    bool Context::destroyRenderer() {
        return true;
    }



    bool Context::init(){
        logger::log(logger::LEVEL_LOG, "Initializing..");
        if (!_game->run()){
            logger::log(logger::LEVEL_FATAL, "Game failed to launch");
            return false;
        }
        if (!initWindow()) {
            logger::log(logger::LEVEL_FATAL, "Failed to initialize window");
            return false;
        }
        if (!initRenderer()) {
            logger::log(logger::LEVEL_FATAL, "Failed to initialize renderer");
            return false;    
        }

        logger::log(logger::LEVEL_LOG, "Finished initialization");

        return true;
    }

    
    
    bool Context::cleanup(){

        logger::log(logger::LEVEL_LOG, "Shutting down engine..");
        if (!destroyRenderer()) {
            logger::log(logger::LEVEL_ERROR, "Failed to cleanly destroy renderer");
            return false;
        }
        if (!destroyWindow()) {
            logger::log(logger::LEVEL_ERROR, "Failed to cleanly destroy window");
            return false;    
        }
        return true;
    }

    void Context::messageLoop(){
        //do some preparations
        if (_state == PREINIT){
            if (!init()){
                logger::log(logger::LEVEL_FATAL, "Failed to initialize context");
                throw std::runtime_error("Init failed!");
            }
            _state = RUNNING;
        }
        while (_state == RUNNING){
            pollWindowEvents();
            _game->frame();
        }
        if (_state == ABORTING){
            logger::log(logger::LEVEL_FATAL, "Received ABORT from game");
            throw std::runtime_error("Game aborted unexpectedly!");
        }

        if(!cleanup()){
            logger::log(logger::LEVEL_ERROR, "Errors occurred during clean up!");
        }




    }

    Context::Context():
    _state(PREINIT), _game(Game::getInstance())
    {
        assert(_instance == nullptr);
        _instance = this;
        messageLoop();
        

    }

    void Context::abort(){
        _state = ABORTING;
    }
    void Context::close(){
        _state = CLOSING;
    }

    Context * Context::getContext(){
        return _instance;
    }

    Context::~Context(){
        _instance = nullptr;
    }
    
} // namespace sparks
