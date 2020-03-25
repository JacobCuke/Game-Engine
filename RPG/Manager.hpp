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
#include "Components.hpp"
#include "TileMap.hpp"

class Manager
{
private:
    std::vector<std::unique_ptr<Entity>> entities;
    bool CollisionSystem(PositionComponent& positionCom, TileMap* tilemap);
    int getPositionFromCoords(int x, int y);
    bool hasCollidableAtPosition(int position, std::vector<int> collidableTiles);
    
public:
    Entity& addEntity();
    void PositionSystem(TileMap* tilemap);
    void DrawSystem();
    void AnimationSystem();
    void ControlSystem(int& keyPressed);
};

