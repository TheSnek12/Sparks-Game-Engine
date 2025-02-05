#include "Mesh.h"
namespace s_Renderer{

    Mesh::Mesh(std::vector<Vertex> vertices, std::vector<uint> indicies):
   // _vertices(vertices), _indicies(indicies) 
     _indicies(indicies) 
    {
        
    }

    Vertex* Mesh::getVertices(size_t*size){
        if (size != nullptr){
            (*size) = _vertices.size();
        }
        return _vertices.data();
        
    }
    uint* Mesh::getIndicies(size_t*size){
        if (size != nullptr){

            (*size) = _indicies.size();
        }
        return _indicies.data();
    }

    size_t Mesh::getIndicSize(){
        return _indicies.size();
    }

    void Mesh::bind(){

    }
    Mesh::Mesh():
    _vertices(std::vector<Vertex>()), _indicies(std::vector<uint>()){

    }

}