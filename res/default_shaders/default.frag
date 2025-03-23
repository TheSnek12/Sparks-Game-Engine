#version 430 core

// Outputs colors in RGBA
out vec4 FragColor;

// Imports the current position from the Vertex Shader
in vec3 crntPos;
// Imports the normal from the Vertex Shader
in vec3 Normal;
// Imports the color from the Vertex Shader
in vec2 TexCoord;

layout (std430) struct dirLight{
	vec3 rot;
	vec3 color;
	float luminance;

};
layout (std430) struct pointLight{
	vec3 pos;
	vec3 color;
	float luminance;

};
layout (std430) struct spotLight{
	vec3 pos;
	float innerRadius;
	vec3 dir;
	float radius;
	vec3 color;
	float luminance;

};


uniform uint DIR_LIGHTS;
uniform uint POINT_LIGHTS;
uniform uint SPOT_LIGHTS;

uniform sampler2D tex;
layout (std430, binding = 1) buffer DirectionalLightBuffer{
	dirLight light[];
} dirLights;
layout (std430, binding = 2) buffer PointLightBuffer{
	pointLight light[];
} pointLights;
layout (std430, binding = 3) buffer SpotLightBuffer{
	spotLight light[];
} spotLights;




float CalcDirLight(dirLight light, vec3 normal);
float CalcPointLight(pointLight light, vec3 normal, vec3 crntPos);

void main()
{
	// outputs final color
	vec3 norm = normalize(Normal);

	float result;
	for (int i = 0; i < DIR_LIGHTS; i++){
		result += CalcDirLight(dirLights.light[i], norm);
	}
	for (int i = 0; i < POINT_LIGHTS; i++){
		result += CalcPointLight(pointLights.light[i], norm, crntPos);
	}
	for (int i = 0; i < SPOT_LIGHTS; i++){

	}

	FragColor = texture(tex, TexCoord) * result;
	
}

float CalcDirLight(dirLight light, vec3 normal)
{
    vec3 lightDir = normalize(-light.rot);
    float diff = max(dot(normal, lightDir), 0.0);
    return max(diff, 0.0);
}
float CalcPointLight(pointLight light, vec3 normal, vec3 crntPos){
	vec3 lightDir = normalize(light.pos - crntPos);
	return max(dot(normal, lightDir), 0.0);
}