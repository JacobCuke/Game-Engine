//
//  Vector2D.cpp
//  RPG
//
//  Created by Jacob Cuke on 2020/02/22.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#include "Vector2D.hpp"

Vector2D::Vector2D()
    : x(0), y(0)
{}

Vector2D::Vector2D(float x, float y)
    : x(x), y(y)
{}

Vector2D Vector2D::Add(const Vector2D &vec2) const
{
    return Vector2D(x + vec2.x, y + vec2.y);
}

Vector2D Vector2D::Subtract(const Vector2D &vec2) const
{
    return Vector2D(x - vec2.x, y - vec2.y);
}

Vector2D Vector2D::Multiply(const Vector2D &vec2) const
{
    return Vector2D(x * vec2.x, y * vec2.y);
}

Vector2D Vector2D::Divide(const Vector2D &vec2) const
{
    return Vector2D(x / vec2.x, y / vec2.y);
}

Vector2D operator+(const Vector2D& vec1, const Vector2D& vec2)
{
    return vec1.Add(vec2);
}

Vector2D operator-(const Vector2D& vec1, const Vector2D& vec2)
{
    return vec1.Subtract(vec2);
}

Vector2D operator*(const Vector2D& vec1, const Vector2D& vec2)
{
    return vec1.Multiply(vec2);
}

Vector2D operator/(const Vector2D& vec1, const Vector2D& vec2)
{
    return vec1.Divide(vec2);
}

Vector2D& Vector2D::operator+=(const Vector2D& vec2)
{
    this->x += vec2.x;
    this->y += vec2.y;
    
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& vec2)
{
    this->x -= vec2.x;
    this->y -= vec2.y;
    
    return *this;
}

Vector2D& Vector2D::operator*=(const Vector2D& vec2)
{
    this->x *= vec2.x;
    this->y *= vec2.y;
    
    return *this;
}

Vector2D& Vector2D::operator/=(const Vector2D& vec2)
{
    this->x /= vec2.x;
    this->y /= vec2.y;
    
    return *this;
}
