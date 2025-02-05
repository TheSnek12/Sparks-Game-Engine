#pragma once
#include "../Shader.h"
#include <stdint.h>
#include <glad/glad.h>
namespace s_Renderer{
    class OpenGLShader : public Shader {
        private:
        uint16_t ID;
        public:
        OpenGLShader(const char* vertex_file, const char* fragment_file);
        ~OpenGLShader();
        void bind() override;

    };
}