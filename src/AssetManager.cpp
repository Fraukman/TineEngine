//
//  AssetManager.cpp
//  TineEngine
//
//  Created by Juan Souza on 01/05/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#include <stdio.h>
#include "AssetManager.h"

AssetManager::AssetManager(EntityManager* manager): manager (manager) {
    
}

void AssetManager::ClearData(){
    textures.clear();
    fonts.clear();
}

void AssetManager::AddTexture(std::string textureId, const char *filePath){
    textures.emplace(textureId, TextureManager::LoadTexture(filePath));
}

void AssetManager::AddFont(std::string fontId, const char *filePath, int fontSize){
    fonts.emplace(fontId,FontManager::LoadFont(filePath, fontSize));
}

SDL_Texture* AssetManager::GetTexture(std::string textureId){
    return textures[textureId];
}

TTF_Font* AssetManager::GetFont(std::string fontId){
    return fonts[fontId];
}
