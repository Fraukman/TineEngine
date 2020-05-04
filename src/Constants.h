//
//  Constants.h
//  TineEngine
//
//  Created by Juan Souza on 30/04/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#pragma once

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

const unsigned int FPS = 60;
const unsigned int FRAME_TARGET_TIME = 1000/FPS;

enum LayerType {
    TILEMAP_LAYER = 0,
    VEGETATION_LAYER = 1,
    ENEMY_LAYER = 2,
    PLAYER_LAYER = 3,
    PROJECTILE_LAYER = 4,
    UI_LAYER = 5
};

const unsigned int NUM_LAYERS = 6;

/* Constants_h */
