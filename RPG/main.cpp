//
//  main.cpp
//  RPG
//
//  Created by Jacob Cuke on 2020/02/14.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#include "Game.hpp"

Game *game = nullptr;

int main(int argc, char *argv[]) {
    
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    
    Uint32 frameStart;
    int frameTime;
    
    game = new Game();
    
    game->init("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    
    while (game->running()) {
        
        frameStart = SDL_GetTicks();
        
        game->handleEvents();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        
        // Limit framerate
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    game->clean();
    
    return EXIT_SUCCESS;
}
