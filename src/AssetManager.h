//
//  AssetManager.h
//  TineEngine
//
//  Created by Juan Souza on 01/05/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#ifndef AssetManager_h
#define AssetManager_h

#include <map>
#include <string>
#include <SDL2/SDL_ttf.h>
#include "TextureManager.h"
#include "FontManager.h"
#include "EntityManager.h"

class AssetManager {
private:
    EntityManager* manager;
    std::map<std::string, SDL_Texture*> textures;
    std::map<std::string, TTF_Font*> fonts;
public:
    AssetManager(EntityManager* manager);
    ~AssetManager();
    void ClearData();

    void AddTexture(std::string textureId, const char* filePath);
    void AddFont(std::string fontId, const char* filePath, int fontSize);
    
    SDL_Texture* GetTexture(std:: string textureId);
    TTF_Font* GetFont(std::string fontId);
};

#endif /* AssetManager_h */
