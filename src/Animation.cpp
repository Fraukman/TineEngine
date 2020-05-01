//
//  Animation.cpp
//  TineEngine
//
//  Created by Juan Souza on 01/05/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#include "./Animation.h"

Animation::Animation(){
    
}

Animation::Animation(unsigned int index, unsigned int numFrames, unsigned int animationSpeed){
    this->index = index;
    this->numFrames = numFrames;
    this->animationSpeed = animationSpeed;
}
