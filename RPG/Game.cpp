//
//  Game.cpp
//  RPG
//
//  Created by Jacob Cuke on 2020/02/14.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#include <iostream>
#include <set>

#include "Game.hpp"
#include "ECS.hpp"
#include "Manager.hpp"
#include "Components.hpp"
#include "TileMap.hpp"


SDL_Renderer *Game::renderer = nullptr;
int Game::GAME_WIDTH = 800;
int Game::GAME_HEIGHT = 640;
int Game::TILE_SIZE = 32;

SDL_Keycode keyPressed;
std::set<int> currentKeysPressed;

TileMap *tilemap;

Manager manager;
Entity& player(manager.addEntity());

Game::Game()
{
    
}

Game::~Game()
{
    
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialized!\n";
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Window created!\n";
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!\n";
        }
        
        isRunning = true;
        
    } else
    {
        isRunning = false;
    }
    
    tilemap = new TileMap("tilemaps/testlevel.tmx");
    tilemap->init();
    
    player.addComponent<PositionComponent>(320, 0, 0, 0);
    player.addComponent<SpriteComponent>("assets/player.png");
    player.addComponent<AnimationComponent>();
    player.addComponent<ControlComponent>(true);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type)
    {
        case SDL_KEYDOWN:
            keyPressed = event.key.keysym.sym;
            currentKeysPressed.insert(event.key.keysym.sym);
            break;
            
        case SDL_KEYUP:
            currentKeysPressed.erase(event.key.keysym.sym);
            if (currentKeysPressed.empty()) keyPressed = NULL;
            else keyPressed = *currentKeysPressed.rbegin();
            break;
            
        case SDL_QUIT:
            isRunning = false;
            break;
            
        default:
            break;
    }
}

void Game::update()
{
    manager.ControlSystem(keyPressed);
    manager.PositionSystem();
    manager.CollisionSystem();
    manager.AnimationSystem();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    
    // Add objects to be rendered
    tilemap->drawMap();
    manager.DrawSystem();
    
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned\n";
}
