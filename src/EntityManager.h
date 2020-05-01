//
//  EntityManager.h
//  TineEngine
//
//  Created by Juan Souza on 30/04/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#ifndef EntityManager_h
#define EntityManager_h

#include "Entity.h"
#include <vector>
#include <string>

class Entity;

class EntityManager{
private:
    std::vector<Entity*> entities;
public:
    void ClearData();
    void Update(float deltaTime);
    void Render();
    bool HasNoEntities();
    Entity& AddEntity(std::string entityName);
    std::vector<Entity*> GetEntities() const;
    unsigned int GetEntityCount();
};

#endif /* EntityManager_h */
