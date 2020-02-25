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
#include "XMLParser/rapidxml.hpp"

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
    int gameTileWidth;
    int gameTileHeight;
    
public:
    TileMap(const char* filename);
    
    void init();
    void drawMap();
};
