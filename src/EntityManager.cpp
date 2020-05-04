//
//  EntityManager.cpp
//  TineEngine
//
//  Created by Juan Souza on 30/04/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//


#include "./EntityManager.h"
#include <iostream>

void EntityManager::ClearData(){
    for(auto& entity: entities){
        entity->Destroy();
    }
}

bool EntityManager::HasNoEntities() const{
    return entities.size() == 0;
}

void EntityManager::Update(float deltaTime){
    for(auto& entity: entities){
        entity->Update(deltaTime);
    }
}

void EntityManager::Render(){
    // for(auto& entity: entities){
    //     entity->Render();
    // }

    for(int layerNumber = 0; layerNumber < NUM_LAYERS; layerNumber++){
        for(auto& entity: GetEntitiesByLayer(static_cast<LayerType>(layerNumber))){
            entity->Render();
        }
    }

}

Entity& EntityManager::AddEntity(std::string entityName, LayerType layer){
    Entity *entity = new Entity(*this,entityName, layer);
    entities.emplace_back(entity);
    return *entity;
}

std::vector<Entity*> EntityManager::GetEntities() const{
    return entities;
}

std::vector<Entity*> EntityManager::GetEntitiesByLayer(LayerType layer) const {
    std::vector<Entity*> selectedEntities;
    for(auto& entity: entities){
        if(entity->layer == layer){
            selectedEntities.emplace_back(entity);
        }
    }
    return selectedEntities;
}

unsigned int EntityManager::GetEntityCount() const{
    return entities.size();
}

void EntityManager::ListAllEntities() const{
    unsigned int i = 0;
    for(auto& entity: entities){
        std::cout << "Entity[" << i << "]: " << entity->name << std::endl;
        entity->ListAllComponents();
        i++;
    }
}
 
