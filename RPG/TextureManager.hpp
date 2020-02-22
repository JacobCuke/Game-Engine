//
//  TextureManager.hpp
//  RPG
//
//  Created by Jacob Cuke on 2020/02/15.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "Game.hpp"

class TextureManager {
    
public:
    static SDL_Texture* loadTexture(const char* fileName);
    static void drawTexture(SDL_Texture *texture, SDL_Rect srcRect, SDL_Rect destRect);
    
};
