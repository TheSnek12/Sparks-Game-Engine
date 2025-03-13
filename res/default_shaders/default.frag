#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;

// Imports the current position from the Vertex Shader
in vec3 crntPos;
// Imports the normal from the Vertex Shader
in vec3 Normal;
// Imports the color from the Vertex Shader
in vec2 TexCoord;

uniform sampler2D tex;



void main()
{
	// outputs final color
	FragColor = texture(tex, TexCoord);
}