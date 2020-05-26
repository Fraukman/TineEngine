//
//  TextLabelComponent.h
//  TineEngine
//
//  Created by Juan Souza on 26/05/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#ifndef TextLabelComponent_h
#define TextLabelComponent_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../EntityManager.h"
#include "../AssetManager.h"
#include "../Game.h"

class TextLabelComponent: public Component{
private:
    SDL_Rect position;
    std::string text;
    std::string fontFamily;
    SDL_Color color;
    SDL_Texture* texture;
public:
    TextLabelComponent(int x, int y, std::string text, std::string fontFamily, const SDL_Color& color){
        this->position.x = x;
        this->position.y = y;
        this->text = text;
        this->fontFamily = fontFamily;
        this->color = color;
        SetLabelText(text, fontFamily);
    }

    void SetLabelText(std::string text, std::string fontFamily){
        SDL_Surface* surface = TTF_RenderText_Blended(Game::assetManager->GetFont(fontFamily),text.c_str(),color);
        texture = SDL_CreateTextureFromSurface(Game::renderer,surface);
        SDL_FreeSurface(surface);
        SDL_QueryTexture(texture,NULL,NULL,&position.w,&position.h);
    }

    void Render() override{
        FontManager::Draw(texture,position);
    }
};

#endif /* TextLabelComponent_h */
