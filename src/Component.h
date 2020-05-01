//
//  Component.h
//  TineEngine
//
//  Created by Juan Souza on 30/04/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#ifndef Component_h
#define Component_h

class Entity;

class Component{
public:
    
    Entity *owner;
    virtual ~Component(){}
    virtual void Initialize(){}
    virtual void Update(float deltaTime){}
    virtual void Render(){}
    
};

#endif /* Component_h */
