#pragma once
#include "../Mesh.h"
#include "OpenGLRenderEngine.h"
namespace s_Renderer
{
    class OpenGLMesh : public Mesh
    {
    private:
        GLuint VBO;
        GLuint EBO;
        GLuint VAO;
        
        /* data */
    public:
        OpenGLMesh(std::vector<Vertex> vertices, std::vector<uint> indicies);
        ~OpenGLMesh();
        void bind() override;
        
    };

    
} // namespace s_Renderer