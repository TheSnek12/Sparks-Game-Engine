#include "OpenGLMesh.h"

namespace s_Renderer
{
    OpenGLMesh::OpenGLMesh(Vertex *vertices, size_t vert_size, uint16_t *indicies, size_t indic_size)
        : Mesh(vertices, vert_size, indicies, indic_size)
    {
        glCreateVertexArrays(1, &this->VAO);
        glBindVertexArray(this->VAO);

        glGenBuffers(1, &this->VBO);
        glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

        glBufferData(GL_ARRAY_BUFFER, vert_size, vertices, GL_STATIC_DRAW);

        if (indic_size > 0)
        {
            glGenBuffers(1, &this->EBO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, indic_size, indicies, GL_STATIC_DRAW);
        }

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, normal));

        glBindVertexArray(0);

    }

    void OpenGLMesh::bind(){
        glBindVertexArray(VAO);
    }

    OpenGLMesh::~OpenGLMesh()
    {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
    }
} // namespace s_Renderer