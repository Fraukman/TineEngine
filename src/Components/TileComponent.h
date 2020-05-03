//
//  TileComponent.h
//  TineEngine
//
//  Created by Juan Souza on 02/05/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#ifndef TileComponent_h
#define TileComponent_h

#include <SDL2/SDL.h>
#include "../EntityManager.h"
#include "../AssetManager.h"
#include "../../lib/glm/glm.hpp"


class TileComponent: public Component {
public:
    SDL_Texture *texture;
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
    glm::vec2 position;
    
    TileComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, std::string assetTextureId){
        texture = Game::assetManager->GetTexture(assetTextureId);
        
        sourceRectangle.x = sourceRectX;
        sourceRectangle.y = sourceRectY;
        sourceRectangle.w = tileSize;
        sourceRectangle.h = tileSize;

        destinationRectangle.x = x;
        destinationRectangle.y = y;
        destinationRectangle.w = tileSize * tileScale;
        destinationRectangle.h = tileSize * tileScale;

        position.x=x;
        position.y=y;
        
    }
    
    ~TileComponent(){
        SDL_DestroyTexture(texture);
    }
    
    void Update(float deltaTime) override{
        //TODO: here is where we will take care of the tile positions
        //based on the camera control
    }
    
    void Render() override{
        TextureManager::Draw(texture, sourceRectangle, destinationRectangle, SDL_FLIP_NONE);
    }
    
};

#endif /* TileComponent_h */