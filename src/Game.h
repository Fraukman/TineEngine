//
//  Game.h
//  TineEngine
//
//  Created by Juan Souza on 30/04/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Entity.h"
#include "Component.h"
#include "EntityManager.h"

class AssetManager;

class Game{
private:
    bool isRunning;
    SDL_Window *window;
public:
    Game();
    ~Game();
    int ticksLastFrame;
    bool IsRunning() const;
    static SDL_Renderer *renderer;
    static AssetManager* assetManager;
    void LoadLevel(int levelNumber);
    void initialize(int width, int height);
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
};


/* Game_h */
