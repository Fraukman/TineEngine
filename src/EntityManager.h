//
//  EntityManager.h
//  TineEngine
//
//  Created by Juan Souza on 30/04/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#ifndef EntityManager_h
#define EntityManager_h

#include "./Entity.h"
#include "./Component.h"

class EntityManager{
private:
    std::vector<Entity*> entities;
public:
    void ClearData();
    void Update(float deltaTime);
    void Render();
    bool HasNoEntities() const;
    unsigned int GetEntityCount() const;
    void ListAllEntities() const;
    std::vector<Entity*> GetEntities() const;
    std::vector<Entity*> GetEntitiesByLayer(LayerType layer) const;
    Entity& AddEntity(std::string entityName, LayerType layer);
    
};

#endif /* EntityManager_h */
