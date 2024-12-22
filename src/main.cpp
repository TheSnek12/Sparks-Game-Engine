#include "include/Game.h"
#include "Context.h"

using namespace sparks;
using namespace logger;
int main(int argc, char const *argv[])
{



    Game* instance = Game::getInstance();
    Context context;
    
    assert(instance != nullptr);

    
    return 0;
}
