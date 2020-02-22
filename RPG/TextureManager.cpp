//
//  TextureManager.cpp
//  RPG
//
//  Created by Jacob Cuke on 2020/02/15.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#include "TextureManager.hpp"

SDL_Texture* TextureManager::loadTexture(const char *filename) {
    
    SDL_Surface *tmpSurface = IMG_Load(filename);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    
    return texture;
}

void TextureManager::drawTexture(SDL_Texture *texture, SDL_Rect srcRect, SDL_Rect destRect) {
    
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
    
}
