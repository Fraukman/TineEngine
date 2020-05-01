//
//  Entity.h
//  TineEngine
//
//  Created by Juan Souza on 30/04/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#ifndef Entity_h
#define Entity_h

#include <vector>
#include <string>
#include "EntityManager.h"
#include "Component.h"

class EntityManager;
class Component;

class Entity{
    
private:
    EntityManager& manager;
    bool isActive;
    std::vector<Component*> components;
    
public:
    std::string name;
    Entity(EntityManager& manager);
    Entity(EntityManager& manager, std::string name);
    void Update(float deltaTime);
    void Render();
    void Destroy();
    bool IsActive() const;
    
    template <typename T,typename... TArgs>
    T& AddComponent(TArgs&&... args){
        T* newComponent(new T(std::forward<TArgs>(args)...));
        
        newComponent->owner = this;
        components.emplace_back(newComponent);
        newComponent->Initialize();
        
        return *newComponent;
    }
};

#endif /* Entity_h */
