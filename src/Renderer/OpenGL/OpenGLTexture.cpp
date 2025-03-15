#include "OpenGLTexture.h"
namespace s_Renderer{
    OpenGLTexture::OpenGLTexture(std::string filename):
    Texture(filename){
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID);

    
        int mode = GL_RGBA;
        if (nrChannels == 3){
            mode = GL_RGB;
        }
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, mode, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        free();

    }
    void OpenGLTexture::bind(int slotNum){
        glActiveTexture(texUnits.at(slotNum));
        glBindTexture(GL_TEXTURE_2D, ID);
    }
    OpenGLTexture::~OpenGLTexture(){

    }
}
