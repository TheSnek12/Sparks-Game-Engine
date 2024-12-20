#ifndef HGAME
#define HGAME

#include "src/Base.h"
// singleton class representing the currently running game.
namespace sparks
{
    class Game
    {
    private:
        /* data */
        inline static Game *_instance = nullptr;

    public:
        static Game *getInstance();
        bool run();

        Game(/* args */);
        ~Game();
    };
}
#endif
