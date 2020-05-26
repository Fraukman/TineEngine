//
//  ProjectileEmitter.h
//  TineEngine
//
//  Created by Juan Souza on 26/05/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#pragma once

#include "./TransformComponent.h"
#include "../../lib/glm/glm.hpp"
#include "../EntityManager.h"

class ProjectileEmitter: public Component
{
private:
    TransformComponent* transform;
    glm::vec2 origin;
    int speed;
    int range;
    float angleRad;
    bool shouldLoop;
public:
    ProjectileEmitter(int speed, int angle, int range, bool shouldLoop){
        this->speed = speed;
        this->range = range;
        this->shouldLoop = shouldLoop;
        this->angleRad = glm::radians(static_cast<float>(angle));
    }

    void Initialize() override{
        transform = owner->GetComponent<TransformComponent>();
        origin = glm::vec2(transform->position.x, transform->position.y);
        transform->velocity = glm::vec2(glm::cos(angleRad)*speed,glm::sin(angleRad)*speed);
    }

    void Update(float deltaTime) override{
        if(glm::distance(transform->position, origin)>range){
            if(shouldLoop){
                transform->position.x = origin.x;
                transform->position.y = origin.y;
            }else{
                owner->Destroy();
            }
        }
    }
    
};

