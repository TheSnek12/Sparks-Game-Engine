#pragma once
#include <vector>
#include <stdint.h>
#include <cstddef>
namespace s_Renderer
{
    typedef float vec3[3];
    struct Vertex
    {
        vec3 pos;
        vec3 normal;
    };
    

    class Mesh
    {
        private:
        Vertex* _vertices;
        size_t _vert_size;
        uint16_t* _indicies;
        size_t _indic_size;

        protected:
        Vertex* getVertices(size_t*size);
        uint16_t* getIndicies(size_t*size);
        Mesh(Vertex * vertices, size_t _vert_size, uint16_t* _indicies, size_t _indic_size);

        public:
        virtual void bind();

    };
} // namespace sparks