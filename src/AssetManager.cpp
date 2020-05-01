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
}

void AssetManager::AddTexture(std::string textureId, const char *filePath){
    textures.emplace(textureId, TextureManager::LoadTexture(filePath));
}

SDL_Texture* AssetManager::GetTexture(std::string textureId){
    return textures[textureId];
}
