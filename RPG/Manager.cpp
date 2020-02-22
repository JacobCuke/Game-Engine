//
//  Manager.cpp
//  RPG
//
//  Created by Jacob Cuke on 2020/02/19.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#include "Manager.hpp"
#include "Components.hpp"
#include "TextureManager.hpp"

Entity& Manager::addEntity()
{
    Entity* e = new Entity();
    std::unique_ptr<Entity> uPtr { e };
    entities.emplace_back(std::move(uPtr));

    return *e;
}

void Manager::PositionSystem()
{
    for (auto& e : entities)
    {
        if (!e->hasComponent<PositionComponent>()) continue;
        
        auto& positionCom = e->getComponent<PositionComponent>();
        
        // Calculations blah blah blah
        positionCom.destX += positionCom.deltaX * 2;
        positionCom.destY += positionCom.deltaY * 2;
    }
}

void Manager::DrawSystem()
{
    for (auto& e : entities)
    {
        if (!e->hasComponent<PositionComponent>()) continue;
        if (!e->hasComponent<SpriteComponent>()) continue;
        
        auto& positionCom = e->getComponent<PositionComponent>();
        auto& spriteCom = e->getComponent<SpriteComponent>();
        
        SDL_Texture* objTexture = TextureManager::loadTexture(spriteCom.sourceFile);
        SDL_Rect srcRect, destRect;
        
        srcRect.h = srcRect.w = 32;
        srcRect.x = spriteCom.srcX;
        srcRect.y = spriteCom.srcY;
        
        destRect.h = destRect.w = 64;
        destRect.x = positionCom.destX;
        destRect.y = positionCom.destY;
        
        SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
    }
}

void Manager::AnimationSystem()
{
    for (auto& e : entities)
    {
        if (!e->hasComponent<PositionComponent>()) continue;
        if (!e->hasComponent<SpriteComponent>()) continue;
        if (!e->hasComponent<AnimationComponent>()) continue;
        
        auto& positionCom = e->getComponent<PositionComponent>();
        auto& spriteCom = e->getComponent<SpriteComponent>();
        auto& animationCom = e->getComponent<AnimationComponent>();
        
        // If entity is standing still, use the middle sprite
        if (positionCom.deltaX == 0 && positionCom.deltaY == 0)
        {
            spriteCom.srcX = 32;
            animationCom.deltaFrame = 1;
            animationCom.frameCount = 0;
        }
        
        // Direction
        if (positionCom.deltaX == 1) // Right
        {
            spriteCom.srcY = SpriteComponent::RIGHT_SPRITE;
        }
        else if (positionCom.deltaX == -1) // Left
        {
            spriteCom.srcY = SpriteComponent::LEFT_SPRITE;
        }
        else if (positionCom.deltaY == 1) // Down
        {
            spriteCom.srcY = SpriteComponent::DOWN_SPRITE;
        }
        else if (positionCom.deltaY == -1) // Up
        {
            spriteCom.srcY = SpriteComponent::UP_SPRITE;
        }
        
        // Animation frame calculation
        if (animationCom.frameCount == 10)
        {
            spriteCom.srcX += (32 * animationCom.deltaFrame);
            if (spriteCom.srcX == 64)
            {
                animationCom.deltaFrame = -1;
            }
            else if (spriteCom.srcX == 0)
            {
                animationCom.deltaFrame = 1;
            }
            animationCom.frameCount = 0;
        }
        else
        {
            animationCom.frameCount++;
        }
        
    }
}

void Manager::ControlSystem(int& keyPressed)
{
    for (auto& e : entities)
    {
        if (!e->hasComponent<PositionComponent>()) continue;
        if (!e->hasComponent<ControlComponent>()) continue;
        
        if (!e->getComponent<ControlComponent>().inControl) continue;
        
        auto& positionCom = e->getComponent<PositionComponent>();
        
        // Reset direction
        positionCom.deltaX = positionCom.deltaY = 0;
        
        if (keyPressed == SDLK_LEFT)
        {
            positionCom.deltaX = -1;
        }
        if (keyPressed == SDLK_RIGHT)
        {
            positionCom.deltaX = 1;
        }
        if (keyPressed == SDLK_UP)
        {
            positionCom.deltaY = -1;
        }
        if (keyPressed == SDLK_DOWN)
        {
            positionCom.deltaY = 1;
        }
    }
}
