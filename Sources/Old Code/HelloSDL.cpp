/*#include <SDL.h>
#include <iostream>

using namespace std;

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = true;

bool init(const char* title, int xpos, int ypos, int width, int height, int wflags, int rflags);
void handleEvents();
void update();
void render();
void clean();

int main() {
    if(!init(
        "Hello SDL", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        640, 
        480, 
        SDL_WINDOW_SHOWN, 
        0
        )) {
        cerr << "SDL initialization failure..." << endl;
        return 1;
    }

    while(g_bRunning) {
        handleEvents();
        update();
        render();
        g_bRunning = false;
        SDL_Delay(5000);
    }
    
    clean();
    return 0;
}

// wflags are window flags, rflags are renderer flags
bool init(const char* title, int xpos, int ypos, int width, int height, int wflags, int rflags) {
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
        g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, wflags);
        if(g_pWindow != 0) {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, rflags);
        }
    } else {
        return false; // SDL initialization failure
    }

    return true; // SDL initialization success
}

void handleEvents() {
    cerr << "handleEvents() not implemented yet..." << endl;
}

void update() {
    cerr << "update() not implemented yet..." << endl;
}

void render() {
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255); // fully opaque rgba black
    SDL_RenderClear(g_pRenderer);           // clear renderer with drawing color
    SDL_RenderPresent(g_pRenderer);         // update the screen
}

void clean() {
    SDL_Quit();
}*/