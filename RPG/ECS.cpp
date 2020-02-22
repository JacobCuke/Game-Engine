//
//  ECS.cpp
//  RPG
//
//  Created by Jacob Cuke on 2020/02/19.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#include <stdio.h>
#include "Components.hpp"

std::map<const char*, ComponentID> Entity::componentTypeMap =
{
    {typeid(PositionComponent).name(), 0},
    {typeid(SpriteComponent).name(), 1},
    {typeid(AnimationComponent).name(), 2},
    {typeid(ControlComponent).name(), 3}
};

