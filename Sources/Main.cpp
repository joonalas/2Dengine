#include "Game.h"
#include "FPSfixer.h"
#include <iostream>

using namespace std;

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main() {

    FPSfixer::Instance()->setFPS(FPS);
    FPSfixer::Instance()->setDelayTime(DELAY_TIME);

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
        
        FPSfixer::Instance()->startFrame();
        Game::Instance()->handleEvents();
        Game::Instance()->update();
        Game::Instance()->render();
        FPSfixer::Instance()->stopFrame();
        /*frameTime = SDL_GetTicks() - frameStart;
        if(frameTime < DELAY_TIME) {
            SDL_Delay((int)(DELAY_TIME - frameTime));
        }*/
    }
    
    Game::Instance()->clean();
    FPSfixer::Instance()->clean();
    return 0;
}