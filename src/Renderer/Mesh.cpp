#include "Mesh.h"
namespace s_Renderer{

    Mesh::Mesh(Vertex * vertices, size_t vert_size, uint16_t* indicies, size_t indic_size):
    _vertices(vertices), _vert_size(vert_size), _indicies(indicies), _indic_size(indic_size)
    {
        
    }

    Vertex* Mesh::getVertices(size_t*size){
        (*size) = _vert_size;
        return _vertices;
        
    }
    uint16_t* Mesh::getIndicies(size_t*size){
        (*size) = _indic_size;
        return _indicies;
    }

    void Mesh::bind(){

    }

}