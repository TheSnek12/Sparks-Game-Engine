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
        OpenGLMesh(Vertex * vertices, size_t vert_size, uint16_t* indicies, size_t indic_size);
        ~OpenGLMesh();
        void bind() override;
    };
    
} // namespace s_Renderer