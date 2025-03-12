#version 330 core

// Positions/Coordinates
layout (location = 0) in vec3 aPos;
// Normals (not necessarily normalized)
layout (location = 1) in vec3 aNormal;



// Outputs the current position for the Fragment Shader
out vec3 crntPos;
// Outputs the normal for the Fragment Shader
out vec3 Normal;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;


void main()
{
	// calculates current position
	crntPos = vec3(vec4(aPos, 1.0f));
	// Assigns the normal from the Vertex Data to "Normal"
	Normal = aNormal;

	
	// Outputs the positions/coordinates of all vertices
	gl_Position = projection*view*model*vec4(crntPos, 1.0) ;
}