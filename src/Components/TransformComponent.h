//
//  TransformComponent.hpp
//  TineEngine
//
//  Created by Juan Souza on 30/04/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#ifndef TransformComponent_h
#define TransformComponent_h

#include <SDL2/SDL.h>
#include "../EntityManager.h"
#include "../../lib/glm/glm.hpp"
#include "../Game.h"

class TransformComponent: public Component {
    public:
        glm::vec2 position;
        glm::vec2 velocity;
        int width;
        int height;
        int scale;

        TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s) {
            position = glm::vec2(posX, posY);
            velocity = glm::vec2(velX, velY);
            width = w;
            height = h;
            scale = s;
        }

        void Initialize() override {
        
        }

        void Update(float deltaTime) override {
            position.x += velocity.x * deltaTime;
            position.y += velocity.y * deltaTime;
        }
};

#endif
