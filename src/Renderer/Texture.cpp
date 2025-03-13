#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "src/ThirdParty/stb_image/stb_image.h"

namespace s_Renderer
{
    Texture::Texture(std::string filename)
    {   
        data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);
        if (!data){
            const char* str = filename.c_str();
            logger::log(logger::LEVEL_ERROR, strcat("Could not load image: ", str));
            data = stbi_load((DEFAULT_RES+IMAGES+"default_tex.png").c_str(), &width, &height, &nrChannels, 0);
        }
    }
    
    void Texture::bind(int slotNum){

    }
    void Texture::free(){
        stbi_image_free(data);
    }
    Texture::~Texture()
    {
    }
} // namespace s_Renderer

