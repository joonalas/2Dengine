#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"

// Constants
const int WINDOWPOS_CENTERED = SDL_WINDOWPOS_CENTERED;

enum WindowFlags {
    FULLSCREEN = SDL_WINDOW_FULLSCREEN,
    OPENGL = SDL_WINDOW_OPENGL,
    SHOWN = SDL_WINDOW_SHOWN,
    HIDDEN = SDL_WINDOW_HIDDEN,
    BORDERLESS = SDL_WINDOW_BORDERLESS,
    RESIZABLE = SDL_WINDOW_RESIZABLE,
    MINIMIZED = SDL_WINDOW_MINIMIZED,
    MAXIMIZED = SDL_WINDOW_MAXIMIZED,
    INPUT_GRABBED = SDL_WINDOW_INPUT_GRABBED,
    INPUT_FOCUS = SDL_WINDOW_INPUT_FOCUS,
    MOUSE_FOCUS = SDL_WINDOW_MOUSE_FOCUS,
    FOREIGN = SDL_WINDOW_FOREIGN
};

enum RendererFlags {
    SOFTWARE = SDL_RENDERER_SOFTWARE,
    ACCELERATED = SDL_RENDERER_ACCELERATED,
    VSYNC = SDL_RENDERER_PRESENTVSYNC,
    RENDERING_TO_TEXTURE = SDL_RENDERER_TARGETTEXTURE
};

class Game {
    public:
        Game();
        ~Game();
        bool init(
            const char* title, 
            int xpos, 
            int ypos, 
            int width, 
            int height, 
            const int wflag, 
            const int rflag
        );
        void handleEvents();
        void update();
        void render();
        void clean();
        bool isRunning();
    private:
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;

        int m_currentFrame;

        bool m_bRunning;
};

#endif