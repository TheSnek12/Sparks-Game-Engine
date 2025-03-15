#version 430 core

// Outputs colors in RGBA
out vec4 FragColor;

// Imports the current position from the Vertex Shader
in vec3 crntPos;
// Imports the normal from the Vertex Shader
in vec3 Normal;
// Imports the color from the Vertex Shader
in vec2 TexCoord;

struct dirLight{
	vec3 rot;
	vec3 color;
	float luminance;

} thing;

uniform sampler2D tex;
layout (std430, binding = 1) buffer LightBuffer{
	dirLight pointLightPositions[];
} lights;



void main()
{
	// outputs final color
	FragColor = texture(tex, TexCoord) * lights.pointLightPositions[0].luminance;
}