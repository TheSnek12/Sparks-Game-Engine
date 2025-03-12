#pragma once
#include "../Texture.h"
#include <glad/glad.h>
#include <map>

namespace s_Renderer{

    static const std::map<int, int> texUnits = {
        {0, GL_TEXTURE0},
        {1, GL_TEXTURE1},
        {2, GL_TEXTURE2},
        {3, GL_TEXTURE3},
        {4, GL_TEXTURE4},
        {5, GL_TEXTURE5},
        {6, GL_TEXTURE6},
        {7, GL_TEXTURE7},
        {8, GL_TEXTURE8},
        {9, GL_TEXTURE9},
        {10, GL_TEXTURE10},
        {11, GL_TEXTURE11},
        {12, GL_TEXTURE12},
        {13, GL_TEXTURE13},
        {14, GL_TEXTURE14},
        {15, GL_TEXTURE15},
        {16, GL_TEXTURE16},
        {17, GL_TEXTURE17},
        {18, GL_TEXTURE18},
        {19, GL_TEXTURE19},
        {20, GL_TEXTURE20},
        {21, GL_TEXTURE21},
        {22, GL_TEXTURE22},
        {23, GL_TEXTURE23},
        {24, GL_TEXTURE24},
        {25, GL_TEXTURE25},
        {26, GL_TEXTURE26},
        {27, GL_TEXTURE27},
        {28, GL_TEXTURE28},
        {29, GL_TEXTURE29},
        {30, GL_TEXTURE30},
        {31, GL_TEXTURE31},
    };

    class OpenGLTexture : public Texture{
        public:
        OpenGLTexture(std::string filename);
        void bind(int slotNum) override;
        ~OpenGLTexture();
        private:
        GLuint ID;

    };

}