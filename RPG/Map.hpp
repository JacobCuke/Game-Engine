//
//  Map.hpp
//  RPG
//
//  Created by Jacob Cuke on 2020/02/15.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "Game.hpp"

class Map {
    
public:
    Map();
    ~Map();
    
    void loadMap(int tileMap[20][25]);
    void drawMap();
    
private:
    SDL_Rect srcRect, destRect;
    SDL_Texture *water;
    SDL_Texture *grass;
    SDL_Texture *dirt;
    
    int map[20][25];
    
};
