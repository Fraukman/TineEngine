//
//  FontManager.h
//  TineEngine
//
//  Created by Juan Souza on 26/05/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#ifndef FontManager_h
#define FontManager_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Game.h"


class FontManager{
public:
    static TTF_Font* LoadFont(const char* fileName, int fontSize);
    static void Draw(SDL_Texture* texture, SDL_Rect position);
};

#endif /* FontManager_h */
