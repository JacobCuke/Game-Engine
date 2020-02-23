//
//  Vector2D.hpp
//  RPG
//
//  Created by Jacob Cuke on 2020/02/22.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#pragma once

#include <stdio.h>

struct Vector2D
{
    float x;
    float y;
    
    Vector2D();
    Vector2D(float x, float y);
    
    Vector2D Add(const Vector2D& vec2) const;
    Vector2D Subtract(const Vector2D& vec2) const;
    Vector2D Multiply(const Vector2D& vec2) const;
    Vector2D Divide(const Vector2D& vec2) const;
    
    friend Vector2D operator+(const Vector2D& vec1, const Vector2D& vec2);
    friend Vector2D operator-(const Vector2D& vec1, const Vector2D& vec2);
    friend Vector2D operator*(const Vector2D& vec1, const Vector2D& vec2);
    friend Vector2D operator/(const Vector2D& vec1, const Vector2D& vec2);
    
    Vector2D& operator+=(const Vector2D& vec2);
    Vector2D& operator-=(const Vector2D& vec2);
    Vector2D& operator*=(const Vector2D& vec2);
    Vector2D& operator/=(const Vector2D& vec2);
};
