#pragma once
#include "Renderer.h"
#include <string>
#include <iostream>
#include <fstream>

namespace s_Renderer
{
    class Shader{
        protected:
        std::string _vertex_shader;
        std::string _fragment_shader;
        bool compiled = false;

        public:

        virtual bool isCompiled();
        Shader(const char* vertex_file, const char* fragment_file);
        Shader();
        virtual void bind();
        virtual uint16_t getID();
        virtual ~Shader() = default;

    };
} // namespace s_Renderer
