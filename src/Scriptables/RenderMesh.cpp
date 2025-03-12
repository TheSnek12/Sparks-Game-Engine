#include <Scriptables/RenderMesh.h>


namespace sparks
{
    void RenderMesh::onStart(){

        std::vector<s_Renderer::Vertex> verts = {
            s_Renderer::Vertex(Vec3(-0.5f, 0.0f, 0.5f), Vec3(0, 0, 0)),
            s_Renderer::Vertex(Vec3(-0.5f, 0.0f, -0.5f), Vec3(0, 0, 0)),
            s_Renderer::Vertex(Vec3(0.5f, 0.0f, -0.5f), Vec3(0, 0, 0)),
            s_Renderer::Vertex(Vec3(0.5f, 0.0f, 0.5f), Vec3(0, 0, 0)),
            s_Renderer::Vertex(Vec3(0.0f, 0.8f, 0.0f), Vec3(0, 0, 0)),
        };
        std::vector<uint> indicies = {
            0, 1, 2,
            0, 2, 3,
            0, 1, 4,
            1, 2, 4,
            2, 3, 4,
            3, 0, 4  
        };
        
        if (Context::getContext()->engineType() == s_Renderer::OpenGL){

            mesh = new s_Renderer::OpenGLMesh(verts, indicies);
            

 
            mesh->dir = &object->getScriptable<Transform>()->rotation;
            mesh->roll = &object->getScriptable<Transform>()->roll;
            mesh->pos = &object->getScriptable<Transform>()->position;



            shader = new s_Renderer::OpenGLShader("/home/Snek/projects/C++/Sparks-Game-Engine/res/default_shaders/default.vert",
                                            "/home/Snek/projects/C++/Sparks-Game-Engine/res/default_shaders/default.frag");

        }
        renderObj.mesh = mesh;
        renderObj.shader = shader;
        
        
        


    }
    void RenderMesh::onTick(){
        Context::getContext()->sendToRenderPool(&renderObj);

    }
    RenderMesh::~RenderMesh(){
        delete renderObj.mesh;
        delete renderObj.shader;
    }

} // namespace sparks
