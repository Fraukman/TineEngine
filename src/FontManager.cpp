//
//  FontManager.cpp
//  TineEngine
//
//  Created by Juan Souza on 26/05/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#include "./FontManager.h"

TTF_Font* FontManager::LoadFont(const char *fileName, int fontSize){
    return TTF_OpenFont(fileName, fontSize);
}

void FontManager::Draw(SDL_Texture *texture, SDL_Rect position){
    SDL_RenderCopy(Game::renderer, texture, NULL, &position);
}
