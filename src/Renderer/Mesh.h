#pragma once
#include <vector>
#include <stdint.h>
#include <cstddef>
#include <vector>
#include "Vec3.h"
#include "Renderer.h"
namespace s_Renderer
{

    struct Vertex
    {
        Vec3 pos;
        Vec3 normal;
        Vertex(Vec3 pos, Vec3 normal) : pos(pos), normal(normal){};
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
        Mesh();
        Mesh(std::vector<Vertex> vertices, std::vector<uint> _indicies);
        virtual void bind();
        size_t getIndicSize();

    };
} // namespace sparks