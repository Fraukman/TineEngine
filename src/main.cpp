//
//  main.cpp
//  TineEngine
//
//  Created by Juan Souza on 30/04/20.
//  Copyright © 2020 Juan Souza. All rights reserved.
//

#include <iostream>
#include "Constants.h"
#include "Game.h"

int main(int argc, const char * argv[]) {
    Game *game = new Game();
    
    game->initialize(WINDOW_WIDTH,WINDOW_HEIGHT);
    
    
    while (game->IsRunning()) {
        game->ProcessInput();
        game->Update();
        game->Render();
    }
    
    game->Destroy();
    
    return 0;
}
