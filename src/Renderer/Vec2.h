#pragma once
#include <glm/vec2.hpp>
#include <glm/gtc/matrix_transform.hpp>
struct Vec2
{
    float x;
    float y;
    Vec2(float x, float y) : x(x), y(y) {}
    Vec2(glm::vec2 vector) : x(vector.x), y(vector.y) {}
    Vec2() : x(0), y(0) {}

    friend Vec2 &operator+=(Vec2 &lhs, const Vec2 &rhs)
    {
        lhs.x += rhs.x;
        lhs.y += rhs.y;

        return lhs;
    }
    friend Vec2 &operator-=(Vec2 &lhs, const Vec2 &rhs)
    {
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;

        return lhs;
    }
    friend Vec2 &operator*=(Vec2 &lhs, const Vec2 &rhs)
    {
        lhs.x *= rhs.x;
        lhs.y *= rhs.y;

        return lhs;
    }
    friend Vec2 &operator/=(Vec2 &lhs, const Vec2 &rhs)
    {
        lhs.x /= rhs.x;
        lhs.y /= rhs.y;

        return lhs;
    }
    friend Vec2 &operator+=(Vec2 &lhs, const float &rhs)
    {
        lhs.x += rhs;
        lhs.y += rhs;

        return lhs;
    }
    friend Vec2 &operator-=(Vec2 &lhs, const float &rhs)
    {
        lhs.x -= rhs;
        lhs.y -= rhs;

        return lhs;
    }
    friend Vec2 &operator*=(Vec2 &lhs, const float &rhs)
    {
        lhs.x *= rhs;
        lhs.y *= rhs;

        return lhs;
    }
    friend Vec2 &operator/=(Vec2 &lhs, const float &rhs)
    {
        lhs.x /= rhs;
        lhs.y /= rhs;

        return lhs;
    }
    friend Vec2 operator+(Vec2 lhs, const Vec2 &rhs)
    {
        lhs += rhs;
        return lhs;
    }
    friend Vec2 operator-(Vec2 lhs, const Vec2 &rhs)
    {
        lhs -= rhs;
        return lhs;
    }
    friend Vec2 operator*(Vec2 lhs, const Vec2 &rhs)
    {
        lhs *= rhs;
        return lhs;
    }
    friend Vec2 operator/(Vec2 lhs, const Vec2 &rhs)
    {
        lhs /= rhs;
        return lhs;
    }
    friend Vec2 operator+(Vec2 lhs, const float &rhs)
    {
        lhs += rhs;
        return lhs;
    }
    friend Vec2 operator-(Vec2 lhs, const float &rhs)
    {
        lhs -= rhs;
        return lhs;
    }
    friend Vec2 operator*(Vec2 lhs, const float &rhs)
    {
        lhs *= rhs;
        return lhs;
    }
    friend Vec2 operator/(Vec2 lhs, const float &rhs)
    {
        lhs /= rhs;
        return lhs;
    }
};