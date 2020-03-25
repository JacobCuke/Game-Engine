//
//  TileMap.hpp
//  RPG
//
//  Created by Jacob Cuke on 2020/02/24.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>

struct TileSet
{
    int firstID;
    SDL_Texture* texture;
    int height;
    int width;
};

class TileMap
{
private:
    const char* mapSource;
    
public:
    std::vector<int> collidableTiles;
    
    TileMap(const char* filename);
    
    void init();
    void drawMap();
    SDL_Rect getTilePosition(int tileID, int gridWidth);
    
    static std::vector<int> getTilesAtPosition(const char* filename, int position);
};
