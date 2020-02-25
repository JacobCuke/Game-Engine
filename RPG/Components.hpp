//
//  Components.hpp
//  RPG
//
//  Created by Jacob Cuke on 2020/02/19.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "ECS.hpp"


struct PositionComponent : public Component
{
    int destX;
    int destY;
    int deltaX;
    int deltaY;
    
    PositionComponent()
        : destX(0), destY(0), deltaX(0), deltaY(0)
    {}
    
    PositionComponent(int x, int y)
        : destX(x), destY(y), deltaX(0), deltaY(0)
    {}
    
    PositionComponent(int x, int y, int delX, int delY)
        : destX(x), destY(y), deltaX(delX), deltaY(delY)
    {}
};

struct SpriteComponent : public Component
{
    const char* sourceFile;
    int srcX;
    int srcY;
    
    static const int SPRITE_WIDTH = 32;
    static const int SPRITE_HEIGHT = 48;
    
    static const int LEFT_SPRITE = 48;
    static const int RIGHT_SPRITE = 96;
    static const int UP_SPRITE = 144;
    static const int DOWN_SPRITE = 0;
    
    static const int INGAME_WIDTH = 32;
    static const int INGAME_HEIGHT = 64;
    
    SpriteComponent(const char* filename)
        : sourceFile(filename), srcX(0), srcY(0)
    {}
    
    SpriteComponent(const char* filename, int x, int y)
        : sourceFile(filename), srcX(x), srcY(y)
    {}
};

struct AnimationComponent : public Component
{
    int frameCount = 0; // Start at 10 so the animation starts immediately
    int deltaFrame = 1;
};

struct ControlComponent : public Component
{
    bool inControl;
    
    ControlComponent(bool inControl)
        : inControl(inControl)
    {}
};

