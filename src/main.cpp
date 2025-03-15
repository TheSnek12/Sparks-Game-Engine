#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <assimp/vector3.h>
#include <assimp/postprocess.h>

#include <Game.h>
#include "Context.h"

using namespace sparks;
using namespace logger;


int main(int argc, char const *argv[])
{

    WINDOWTYPE = GLFW;
    PLATFORM = sparks::LINUX;

    Game *instance = Game::getInstance();
    Context context;

    assert(instance != nullptr);

    return 0;
}
