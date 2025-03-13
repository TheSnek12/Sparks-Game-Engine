#include <Scriptables/RenderMesh.h>

namespace sparks
{
    Assimp::Importer RenderMesh::importer;
    RenderMesh::RenderMesh(std::string file)
    {
        objFile = file;
    }

    void RenderMesh::importObj(std::string file)
    {
        const aiScene *scene = importer.ReadFile(file, postprocess);
        const aiMesh *mesh = scene->mMeshes[0];
        std::vector<uint> indicies;
        for (size_t i = 0; i < mesh->mNumFaces; i++)
        {
            for (size_t j = 0; j < mesh->mFaces[i].mNumIndices; j++)
            {
                indicies.push_back(mesh->mFaces[i].mIndices[j]);
            }
        }
        std::vector<s_Renderer::Vertex> verts;
        for (size_t i = 0; i < mesh->mNumVertices; i++)
        {
            verts.push_back(s_Renderer::Vertex(Vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z),
                                               Vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z),
                                               Vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y)));
        }

        createMesh(verts, indicies);
    }

    void RenderMesh::createMesh(std::vector<Vertex> verts, std::vector<uint> indicies)
    {
        switch (Context::getContext()->engineType())
        {
        case OpenGL:
            mesh = new s_Renderer::OpenGLMesh(verts, indicies);

            break;

        default:
            break;
        }
        mesh->dir = &object->getScriptable<Transform>()->rotation;
        mesh->roll = &object->getScriptable<Transform>()->roll;
        mesh->pos = &object->getScriptable<Transform>()->position;
    }

    void RenderMesh::onStart()
    {
        importObj(objFile);

        shader = new OpenGLShader("res/default_shaders/default.vert", "res/default_shaders/default.frag");

        renderObj.mesh = mesh;
        renderObj.shader = shader;
        for (Texture *tex : textures)
        {
            renderObj.textures.push_back(tex);
        }
    }
    void RenderMesh::addTexture(std::string file)
    {
        textures.push_back(new s_Renderer::OpenGLTexture(file));
        renderObj.textures.push_back(textures.back());
    }
    void RenderMesh::onTick()
    {
        Context::getContext()->sendToRenderPool(&renderObj);
    }

    void RenderMesh::removeTexture(int num)
    {
        textures.erase(textures.begin() + num);
        renderObj.textures.erase(renderObj.textures.begin() + num);
    }
    RenderMesh::~RenderMesh()
    {
        delete renderObj.mesh;
        delete renderObj.shader;
        for (Texture *tex : textures)
        {
            delete tex;
        }
    }

} // namespace sparks
