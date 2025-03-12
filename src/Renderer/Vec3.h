#pragma once
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>
struct Vec3
{
    float x;
    float y;
    float z;
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
    Vec3(glm::vec3 vector) : x(vector.x), y(vector.y), z(vector.z) {}
    Vec3() : x(0), y(0), z(0) {}

    
    Vec3 cross(const Vec3 &rhs){
        glm::vec3 grhs = glm::vec3(x, y, z);
        glm::vec3 glhs = glm::vec3(rhs.x, rhs.y, rhs.z);
        return Vec3(glm::cross(grhs, glhs));
    }

    float dot(const Vec3 &rhs){
        glm::vec3 grhs = glm::vec3(x, y, z);
        glm::vec3 glhs = glm::vec3(rhs.x, rhs.y, rhs.z);
        return glm::dot(grhs, glhs);
    }

    friend Vec3 &operator+=(Vec3 &lhs, const Vec3 &rhs)
    {
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        lhs.z += rhs.z;

        return lhs;
    }
    friend Vec3 &operator-=(Vec3 &lhs, const Vec3 &rhs)
    {
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        lhs.z -= rhs.z;

        return lhs;
    }
    friend Vec3 &operator*=(Vec3 &lhs, const Vec3 &rhs)
    {
        lhs.x *= rhs.x;
        lhs.y *= rhs.y;
        lhs.z *= rhs.z;
        return lhs;
    }
    friend Vec3 &operator/=(Vec3 &lhs, const Vec3 &rhs)
    {
        lhs.x /= rhs.x;
        lhs.y /= rhs.y;
        lhs.z /= rhs.z;
        return lhs;
    }
    friend Vec3 &operator+=(Vec3 &lhs, const float &rhs)
    {
        lhs.x += rhs;
        lhs.y += rhs;
        lhs.z += rhs;

        return lhs;
    }
    friend Vec3 &operator-=(Vec3 &lhs, const float &rhs)
    {
        lhs.x -= rhs;
        lhs.y -= rhs;
        lhs.z -= rhs;

        return lhs;
    }
    friend Vec3 &operator*=(Vec3 &lhs, const float &rhs)
    {
        lhs.x *= rhs;
        lhs.y *= rhs;
        lhs.z *= rhs;
        return lhs;
    }
    friend Vec3 &operator/=(Vec3 &lhs, const float &rhs)
    {
        lhs.x /= rhs;
        lhs.y /= rhs;
        lhs.z /= rhs;
        return lhs;
    }
    friend Vec3 operator+(Vec3 lhs, const Vec3 &rhs)
    {
        lhs += rhs;
        return lhs;
    }
    friend Vec3 operator-(Vec3 lhs, const Vec3 &rhs)
    {
        lhs -= rhs;
        return lhs;
    }
    friend Vec3 operator*(Vec3 lhs, const Vec3 &rhs)
    {
        lhs *= rhs;
        return lhs;
    }
    friend Vec3 operator/(Vec3 lhs, const Vec3 &rhs)
    {
        lhs /= rhs;
        return lhs;
    }
    friend Vec3 operator+(Vec3 lhs, const float &rhs)
    {
        lhs += rhs;
        return lhs;
    }
    friend Vec3 operator-(Vec3 lhs, const float &rhs)
    {
        lhs -= rhs;
        return lhs;
    }
    friend Vec3 operator*(Vec3 lhs, const float &rhs)
    {
        lhs *= rhs;
        return lhs;
    }
    friend Vec3 operator/(Vec3 lhs, const float &rhs)
    {
        lhs /= rhs;
        return lhs;
    }
};