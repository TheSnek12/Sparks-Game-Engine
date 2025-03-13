#pragma once
#include <vector>
#include "src/Context.h"
#include <Scriptables/Scriptable.h>
#include "src/Renderer/Mesh.h"
#include "src/Renderer/RenderObject.h"
#include "src/Renderer/Texture.h"
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <assimp/vector3.h>
#include <assimp/postprocess.h>
#include "src/Renderer/OpenGL/OpenGLMesh.h"
#include "src/Renderer/OpenGL/OpenGLShader.h"
#include "src/Renderer/OpenGL/OpenGLTexture.h"

namespace sparks
{
    class RenderMesh : public Scriptable
    {
        static Assimp::Importer importer;
        const uint postprocess = aiProcess_CalcTangentSpace |
                                 aiProcess_Triangulate |
                                 aiProcess_JoinIdenticalVertices |
                                 aiProcess_SortByPType;
        s_Renderer::RenderObject renderObj;
        // FIX THISSS
        Mesh *mesh;
        std::vector<Texture *> textures;
        Shader *shader;

    private:
        void createMesh(std::vector<s_Renderer::Vertex> verts, std::vector<uint> indicies);
        std::string objFile;

    public:
        ~RenderMesh() override;
        RenderMesh(std::string objFile);
        void onStart() override;
        void importObj(std::string file);
        void addTexture(std::string file);
        void removeTexture(int num);
        void onTick() override;
    };
} // namespace sparks
