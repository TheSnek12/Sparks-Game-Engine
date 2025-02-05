#include "OpenGLShader.h"

namespace s_Renderer
{
    OpenGLShader::OpenGLShader(const char* vertex_file, const char* fragment_file):
    Shader(vertex_file, fragment_file){
        const char* vertex_contents = _vertex_shader.c_str();
        const char* fragment_contents = _fragment_shader.c_str();

        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertex_contents, NULL);
        glCompileShader(vertexShader);

        GLint hasCompiled;
        GLchar log[1024];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &hasCompiled);
        if (hasCompiled == GL_FALSE){
            glGetShaderInfoLog(vertexShader, 1024, NULL, log);
            logger::log(logger::LEVEL_ERROR, "OpenGL vertex shader compilation failed!");
            logger::log(logger::LEVEL_ERROR, log);
            return;
        }

        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragment_contents, NULL);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &hasCompiled);
        if (hasCompiled == GL_FALSE){
            glGetShaderInfoLog(fragmentShader, 1024, NULL, log);
            logger::log(logger::LEVEL_ERROR, "OpenGL fragment shader compilation failed!");
            logger::log(logger::LEVEL_ERROR, log);
            return;
        }

        ID = glCreateProgram();

        glAttachShader(ID, vertexShader);
        glAttachShader(ID, fragmentShader);

        glLinkProgram(ID);
        glGetProgramiv(ID, GL_LINK_STATUS, &hasCompiled);
        if (hasCompiled == GL_FALSE){
            glGetProgramInfoLog(ID, 1024, NULL, log);
            logger::log(logger::LEVEL_ERROR, "OpenGL shader program linking failed!");
            logger::log(logger::LEVEL_ERROR, log);
            return;
        }    
        
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        compiled = true;

    }

    void OpenGLShader::bind(){
        glUseProgram(ID);
    }

    OpenGLShader::~OpenGLShader(){
        glDeleteProgram(ID);
    }
} // namespace s_Renderer
