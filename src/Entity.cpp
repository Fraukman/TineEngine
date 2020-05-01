//
//  Entity.cpp
//  TineEngine
//
//  Created by Juan Souza on 30/04/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#include <iostream>
#include "./Entity.h"

Entity::Entity(EntityManager& manager): manager(manager){
    this->isActive = true;
}

Entity::Entity(EntityManager& manager, std::string name): manager(manager), name(name){
    this->isActive = true;
}

void Entity::Update(float deltaTime){
    for (auto& component: components){
        component->Update(deltaTime);
    }
}

void Entity::Render(){
    for(auto& component: components){
        component->Render();
    }
}

void Entity::Destroy(){
    this->isActive = false;
}

bool Entity::IsActive() const{
    return this->isActive;
}

void Entity::ListAllComponents() const{
    for(auto mapElement: componentTypeMap){
        std::cout << " Component" << mapElement.first->name() << ">" << std::endl;
    }
}
