#pragma once
#include "Renderer.h"

#define STB_IMAGE_IMPLEMENTATION
#include "src/ThirdParty/stb_image/stb_image.h"

namespace s_Renderer
{
    class Texture
    {
    protected:
    int width, height, nrChannels;
    unsigned char *data;
    void free();

    public:
        Texture(std::string filename);
        virtual void bind(int slotNum);
        ~Texture();
    };
    

    
} // namespace s_Renderer

