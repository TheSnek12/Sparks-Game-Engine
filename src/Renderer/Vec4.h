#pragma once
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>
struct Vec4
{
    float x;
    float y;
    float z;
    float w;
    Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
    Vec4(glm::vec4 vector) : x(vector.x), y(vector.y), z(vector.z), w(vector.w) {}
    Vec4() : x(0), y(0), z(0), w(0) {}

};