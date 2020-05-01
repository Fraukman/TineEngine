//
//  Game.cpp
//  TineEngine
//
//  Created by Juan Souza on 30/04/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#include <iostream>
#include "Constants.h"
#include "Game.h"
#include "../lib/glm/glm.hpp"
#include "./Components//TransformComponent.h"

EntityManager manager;
SDL_Renderer* Game::renderer;

Game::Game(){
    this->isRunning = false;
}

Game::~Game(){
    
}

bool Game::IsRunning() const{
    return this->isRunning;
}


void Game::initialize(int width, int height){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cerr<<"Error initialing SDL." << std::endl;
        return;
    }
    window = SDL_CreateWindow(NULL,
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              width,
                              height,
                              SDL_WINDOW_BORDERLESS);
    
    if(!window){
        std::cerr <<"Error creating SDL window" << std::endl;
        return;
    }
    
    renderer = SDL_CreateRenderer(
                                  window,
                                  -1,
                                  0);
    
    if(!renderer){
        std::cerr<<"Error creating SDL renderer."<<std::endl;
        return;
    }
    
    LoadLevel(0);
    
    isRunning = true;
    return;
    
}

void Game::LoadLevel(int levelNumber){
    
    Entity& projectile(manager.AddEntity("Projectile1"));
    projectile.AddComponent<TransformComponent>(0,0,20,20,32,32,1);
    projectile.AddComponent<TransformComponent>(WINDOW_WIDTH/2,WINDOW_HEIGHT/2,20,-20,32,32,1);
    
    
}

void Game::ProcessInput(){
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type){
        case SDL_QUIT:{
            isRunning  = false;
            break;
        }
        case SDL_KEYDOWN: {
            if(event.key.keysym.sym == SDLK_ESCAPE){
                isRunning = false;
            }
        }
        default:{
            break;
        }
    }
}

void Game::Update(){
    //Waste some time / sleep until reach the target frame time
    int waitTime = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);
    
    if(waitTime > 0 && waitTime < FRAME_TARGET_TIME){
        SDL_Delay(waitTime);
    }
    
    //Delta time is the difference in ticks from last frame covereted to seconsds
    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
        
    //sets the new ticks for the current frame to be used in the next pass
    ticksLastFrame = SDL_GetTicks();
    
    manager.Update(deltaTime);
    
}

void Game::Render(){
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);
    
    if(manager.HasNoEntities()){
        return;
    }
    
    manager.Render();
    
    SDL_RenderPresent(renderer);
}

void Game::Destroy(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
