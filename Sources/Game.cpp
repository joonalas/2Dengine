#include "Game.h"
#include <iostream>

Game::Game() {
    m_pWindow = 0;
    m_pRenderer = 0;
    m_currentFrame = 0;
    m_bRunning = true;
}

Game::~Game() {}

bool Game::init(const char* title, int xpos, int ypos, int width, 
int height, const int wflag, const int rflag) {
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
        std::cout << "SDL initialization success!" << std::endl;
        m_pWindow = SDL_CreateWindow(
            title, 
            xpos, 
            ypos, 
            width, 
            height,
            wflag
        );
        if(m_pWindow != 0) {
            std::cout << "Window creation success!" << std::endl;
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, rflag);
            if(m_pRenderer != 0) {
                std::cout << "Renderer creation success!" << std::endl;
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255); // fully opaque rgba white
            } else {
                std::cerr << "Renderer creation failure!" << std::endl;
                return false;
            }
        } else {
            std::cerr << "Window creation failure!" << std::endl;
            return false;
        }
    } else {
        std::cerr << "SDL initialization failure!" << std::endl;
        return false; // SDL initialization failure
    }

    std::cout << "Initialization success!" << std::endl;
    m_bRunning = true;
    //Texture loading
    if(!TextureManager::Instance()->load("../Assets/ashsprites.png", "ash", m_pRenderer)) {
        std::cerr << "WARNING!!! Unable to load textures" << std::endl;
    }
    m_go.load(100, 100, 32, 32, "ash");
    m_player.load(300, 300, 32, 32, "ash");

    return true; // SDL initialization success
}

void Game::handleEvents() {
    SDL_Event event;
    if(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                m_bRunning = false;
                break;
            default:
                break;
        }
    }
}

void Game::update() {
    m_go.update();
    m_player.update();
    //m_currentFrame = int( ( (SDL_GetTicks() / 100) % 5 ) );
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);           // clear renderer with drawing color  

    m_go.draw(m_pRenderer);
    m_player.draw(m_pRenderer);

    SDL_RenderPresent(m_pRenderer);         // update the screen
}

void Game::clean() {
    std::cout << "Cleaning up and exiting the game..." << std::endl;
    TextureManager::Instance()->clean();
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

bool Game::isRunning() {
    return m_bRunning;
}