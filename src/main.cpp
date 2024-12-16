#include "include/Game.h"
using namespace sparks;

int main(int argc, char const *argv[])
{
    std::freopen("log.txt", "w", stderr);

    Game* instance = Game::getInstance();
    assert(instance != nullptr);
    LOG("Hello World");
    
    return 0;
}
