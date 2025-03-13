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

    Assimp::Importer importer;
    
    const aiScene* scene = importer.ReadFile(
        "test/res/obj/cottage_obj.obj",
        aiProcess_CalcTangentSpace          |
        aiProcess_Triangulate               |
        aiProcess_JoinIdenticalVertices     |
        aiProcess_SortByPType

    );

    
    
    
   for (size_t i = 0; i < scene->mMeshes[0]->mNumVertices; i++)
   {
        std::cout << scene->mMeshes[0]->mTextureCoords[0][i].x << " " << scene->mMeshes[0]->mTextureCoords[0][i].y << " " << scene->mMeshes[0]->mTextureCoords[0][i].z << std::endl;
        std::cout << scene->mMeshes[0]->mVertices[i].x << " " << scene->mMeshes[0]->mVertices[i].y << " " << scene->mMeshes[0]->mVertices[i].z << std::endl;
        std::cout << scene->mMeshes[0]->mNormals[i].x << " " << scene->mMeshes[0]->mNormals[i].y << " " << scene->mMeshes[0]->mNormals[i].z << std::endl;
   }
    

    Game *instance = Game::getInstance();
    Context context;

    assert(instance != nullptr);

    return 0;
}
