//
//  Map.cpp
//  TineEngine
//
//  Created by Juan Souza on 02/05/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include "Game.h"
#include "Map.h"
#include "./Components/TileComponent.h"
#include "EntityManager.h"

extern EntityManager manager;

Map::Map(std::string textureId, int scale, int tileSize){
    this->textureId = textureId;
    this->scale = scale;
    this->tileSize = tileSize;
}

void Map::LoadMap(std::string filePath, int mapSizeY, int mapSizeX){
    std::fstream mapFile;
    mapFile.open(filePath);

    for(int y = 0; y<mapSizeY; y++){
        for (int x = 0; x < mapSizeX; x++)
        {
            char ch;
            mapFile.get(ch);
            int sourceRectY = atoi(&ch) * tileSize;
            mapFile.get(ch);
            int sourceRectX = atoi(&ch) * tileSize;

            AddTile(sourceRectX,sourceRectY, x * (scale * tileSize), y * (scale * tileSize));
            mapFile.ignore();
        }
        
    }
    mapFile.close();
}

void Map::AddTile(int sourceRectX, int sourceRectY, int x, int y){
    Entity& newTile(manager.AddEntity("Tile",TILEMAP_LAYER));
    newTile.AddComponent<TileComponent>(sourceRectX,sourceRectY,x,y, tileSize,scale, textureId);
}
