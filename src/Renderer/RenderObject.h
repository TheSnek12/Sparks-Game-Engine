#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include <vector>





namespace s_Renderer
{
    struct RenderObject
    {
        Mesh* mesh;
        Shader* shader;
        std::vector<Texture*> textures;
        
        RenderObject() : mesh(nullptr), shader(nullptr), textures({}) {

        };
        ~RenderObject() = default;
    };
    
}
