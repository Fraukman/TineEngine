//
//  Animation.h
//  TineEngine
//
//  Created by Juan Souza on 01/05/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#ifndef Animation_h
#define Animation_h

class Animation{
public:
    unsigned int index;
    unsigned int numFrames;
    unsigned int animationSpeed;
    Animation();
    Animation(unsigned int index, unsigned int numFrames, unsigned int animationSpeed);
};

#endif /* Animation_h */
