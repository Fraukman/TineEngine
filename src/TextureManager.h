//
//  TextureManager.h
//  TineEngine
//
//  Created by Juan Souza on 01/05/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#ifndef TextureManager_h
#define TextureManager_h

#include "Game.h"

class TextureManager {
    
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* texture, SDL_Rect sourceRectangle, SDL_Rect destinationRectangle, SDL_RendererFlip flip);
    
};


#endif /* TextureManager_h */
