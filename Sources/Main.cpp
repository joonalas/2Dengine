#include "Game.h"
#include <iostream>

using namespace std;

int main() {
    Game game;

    int wflag = 0;
    int rflag = 0;
    if(!game.init(
        "Hello SDL", 
        WINDOWPOS_CENTERED, 
        WINDOWPOS_CENTERED, 
        640, 
        480, 
        wflag, 
        rflag
        )) {
        
        return 1;
    }

    while(game.isRunning()) {
        game.handleEvents();
        game.update();
        game.render();
        SDL_Delay(20);
    }
    
    game.clean();
    return 0;
}