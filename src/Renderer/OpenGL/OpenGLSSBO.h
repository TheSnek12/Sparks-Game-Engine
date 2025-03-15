#pragma once
#include <glad/glad.h>
#include <stddef.h>
#include <stdint.h>

#include <vector>
namespace s_Renderer
{
    template <typename T>
    class OpenGLSSBO
    {
    private:
        uint32_t ID;
        uint16_t index;
    public:
        std::vector<T> data;
        OpenGLSSBO<T>(uint16_t index, size_t size, void *data) : index(index)
        {

            glGenBuffers(1, &ID);
            glBindBufferRange(GL_SHADER_STORAGE_BUFFER, index, ID, 0, size);
            glBufferData(GL_SHADER_STORAGE_BUFFER, this->data.size() * sizeof(T), this->data.data(), GL_DYNAMIC_COPY);
            glBindBufferBase(GL_SHADER_STORAGE_BUFFER, index, ID);
        }

        void bind() {}
        ~OpenGLSSBO()
        {
            glDeleteBuffers(1, &ID);
        }
    };
} // namespace s_Renderer
