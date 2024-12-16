#include "include/Game.h"
namespace sparks
{
    Game::Game()
    {
        assert(_instance == nullptr);

        _instance = this;
    }

    Game::~Game()
    {

        _instance = nullptr;
    }
    Game *Game::getInstance()
    {
        return _instance;
    }
}