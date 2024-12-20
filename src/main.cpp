#include "include/Game.h"
#include "Logger/Logger.h"
using namespace sparks;
using namespace logger;
int main(int argc, char const *argv[])
{

    log(LEVEL_LOG, "waawawwa");
    log(LEVEL_WARN, "waawawwa");
    log(LEVEL_ERROR, "waawawwa");
    log(LEVEL_FATAL, "waawawwa");

    Game* instance = Game::getInstance();
    assert(instance != nullptr);

    
    return 0;
}
