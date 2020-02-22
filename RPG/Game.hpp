//
//  Game.hpp
//  RPG
//
//  Created by Jacob Cuke on 2020/02/14.
//  Copyright © 2020 Jacob Cuke. All rights reserved.
//

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Game {
    
public:
    Game();
    ~Game();
    
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running() { return isRunning; }
    
    static SDL_Renderer *renderer;
    
private:
    int count = 0;
    bool isRunning;
    SDL_Window *window;
};
