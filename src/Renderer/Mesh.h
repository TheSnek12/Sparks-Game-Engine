#pragma once
#include <vector>
#include <stdint.h>
#include <cstddef>
#include <vector>
#include "Vec3.h"
#include "Vec2.h"
#include "Renderer.h"
namespace s_Renderer
{

    struct Vertex
    {
        Vec3 pos;
        Vec3 normal;
        Vec2 texCoord;
        Vertex(Vec3 pos, Vec3 normal) : pos(pos), normal(normal), texCoord(0.0f,0.0f){};
        Vertex(Vec3 pos, Vec3 normal, Vec2 texCoord) : pos(pos), normal(normal), texCoord(texCoord){};
    };
    

    class Mesh
    {
        private:
        std::vector<Vertex> _vertices;
        std::vector<uint> _indicies;

        public:
        Vertex* getVertices(size_t*size);
        uint* getIndicies(size_t*size);
        

        public:
        Vec3* pos;
        Vec3* scale;
        float* roll;
        Vec3* dir;
        Mesh();
        Mesh(std::vector<Vertex> vertices, std::vector<uint> _indicies);
        virtual void bind();
        size_t getIndicSize();
        virtual ~Mesh() = default;

    };
} // namespace sparks