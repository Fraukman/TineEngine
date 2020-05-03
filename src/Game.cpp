//
//  Game.cpp
//  TineEngine
//
//  Created by Juan Souza on 30/04/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#include <iostream>
#include "./Constants.h"
#include "./Game.h"
#include "./AssetManager.h"
#include "../lib/glm/glm.hpp"
#include "./Map.h"
#include "./Components/TransformComponent.h"
#include "./Components/SpriteComponent.h"
#include "./Components/KeyboardControlComponent.h"

EntityManager manager;
AssetManager* Game::assetManager = new AssetManager(&manager);
SDL_Renderer* Game::renderer;
SDL_Event Game::event;
Map* map;

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
    //manager.ListAllEntities();
    return;
    
    
    
}

void Game::LoadLevel(int levelNumber){
    //Start inclunding new asses to the assetmanager list
    assetManager->AddTexture("tank-Image", std::string("./assets/images/tank-big-right.png").c_str());
    assetManager->AddTexture("chopper-image", std::string("./assets/images/chopper-spritesheet.png").c_str());
    assetManager->AddTexture("jungle-tiletexture", std::string("./assets/tilemaps/jungle.png").c_str());

    map = new Map("jungle-tiletexture", 2 , 32);
    map->LoadMap("./assets/tilemaps/jungle.map", 20,25);

    //Start inclunding entities and also components to them
   Entity& tankEntity(manager.AddEntity("tank"));
   tankEntity.AddComponent<TransformComponent>(32,32,10,10,32,32,2);
   tankEntity.AddComponent<SpriteComponent>("tank-Image");
    
    Entity& chopperEntity(manager.AddEntity("chopper"));
    chopperEntity.AddComponent<TransformComponent>(240,106,0,0,32,32,1);
    chopperEntity.AddComponent<SpriteComponent>("chopper-image",2,90,true,false);
    chopperEntity.AddComponent<KeyboardControlComponent>("up","right","down","left","space");
    
}

void Game::ProcessInput(){
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
