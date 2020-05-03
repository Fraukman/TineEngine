//
//  Map.h
//  TineEngine
//
//  Created by Juan Souza on 02/05/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#ifndef Map_h
#define Map_h

class Map {
private:
    std::string textureId;
    int scale;
    int tileSize;
public:
    Map(std::string textureId, int scale, int tileSize);
    ~Map();
    void LoadMap(std::string filePath, int mapSizeY, int mapSizeX);
    void AddTile(int sourceX, int sourceY, int x, int y);
};

#endif /* Map_h */
