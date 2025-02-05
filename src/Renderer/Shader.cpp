#include "Shader.h"

std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

namespace s_Renderer{
    Shader::Shader(const char* vertex_file, const char* fragment_file) : 
    _vertex_shader(get_file_contents(vertex_file)), _fragment_shader(get_file_contents(fragment_file)){

    };
	Shader::Shader() :
	_vertex_shader(""), _fragment_shader(""){

	}

	bool Shader::isCompiled(){
		return compiled;
	}

    void Shader::bind(){
        
    }

    Shader::~Shader(){

    }
}