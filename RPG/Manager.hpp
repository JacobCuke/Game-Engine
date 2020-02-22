//
//  Manager.hpp
//  Learning
//
//  Created by Jacob Cuke on 2020/02/19.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <vector>
#include <memory>

#include "ECS.hpp"

class Manager
{
private:
    std::vector<std::unique_ptr<Entity>> entities;
    
public:
    Entity& addEntity();
    void PositionSystem();
    void DrawSystem();
    void AnimationSystem();
    void ControlSystem(int& keyPressed);
};

