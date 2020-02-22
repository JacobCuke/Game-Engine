//
//  Map.cpp
//  RPG
//
//  Created by Jacob Cuke on 2020/02/15.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#include "Map.hpp"
#include "TextureManager.hpp"

int lvl1[20][25] = {
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0 }
};

Map::Map() {
    
    water = TextureManager::loadTexture("assets/water.png");
    grass = TextureManager::loadTexture("assets/grass.png");
    dirt = TextureManager::loadTexture("assets/dirt.png");
    
    loadMap(lvl1);
    
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = srcRect.h = 32;
    destRect.w = destRect.h = 32;
    
    destRect.x = destRect.y = 0;
    
}

void Map::loadMap(int tileMap[20][25]) {
    
    for (int row = 0; row < 20; row++) {
        
        for (int col = 0; col < 25; col++) {
            
            map[row][col] = tileMap[row][col];
            
        }
    }
}

void Map::drawMap() {
    
    int type = 0;
    
    for (int row = 0; row < 20; row++) {
        
        for (int col = 0; col < 25; col++) {
            
            type = map[row][col];
            
            destRect.x = 32 * col;
            destRect.y = 32 * row;
            
            switch (type) {
                case 0:
                    TextureManager::drawTexture(water, srcRect, destRect);
                    break;
                    
                case 1:
                    TextureManager::drawTexture(grass, srcRect, destRect);
                    break;
                    
                case 2:
                    TextureManager::drawTexture(dirt, srcRect, destRect);
                    break;
                    
                default:
                    break;
            }
            
        }
    }
    
}
