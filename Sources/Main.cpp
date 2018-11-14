#include "Game.h"
#include <iostream>

using namespace std;

int main() {
    int wflag = 0;
    int rflag = 0;
    if(!Game::Instance()->init(
        "Hello SDL", 
        WINDOWPOS_CENTERED, 
        WINDOWPOS_CENTERED, 
        640, 
        480, 
        wflag, 
        rflag
        )) {
        
        return -1;
    }

    while(Game::Instance()->isRunning()) {
        Game::Instance()->handleEvents();
        Game::Instance()->update();
        Game::Instance()->render();
        SDL_Delay(20);
    }
    
    Game::Instance()->clean();
    return 0;
}