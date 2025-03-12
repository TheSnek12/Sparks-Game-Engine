#include <assimp/Importer.hpp>
#include <assimp/mesh.h>
#include <assimp/postprocess.h>

#include <Game.h>
#include "Context.h"

using namespace sparks;
using namespace logger;


int main(int argc, char const *argv[])
{

    WINDOWTYPE = GLFW;
    PLATFORM = sparks::LINUX;

    Assimp::Importer importer;
    
    const aiScene* scene = importer.ReadFile(
        "test/res/obj/cottage_obj.obj",
        aiProcess_CalcTangentSpace          |
        aiProcess_Triangulate               |
        aiProcess_JoinIdenticalVertices     |
        aiProcess_SortByPType

    );
    
    
    

    Game *instance = Game::getInstance();
    Context context;

    assert(instance != nullptr);

    return 0;
}
