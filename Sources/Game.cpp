#include "Game.h"
#include <iostream>

Game::Game() {
    m_pWindow = 0;
    m_pRenderer = 0;
    m_currentFrame = 0;
    m_player = 0;
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
    if(!TextureManager::Instance()->load("/home/joonas/Documents/C/2Dengine/Assets/ashsprites.png", "ash", m_pRenderer)) {
        std::cerr << "WARNING!!! Unable to load textures" << std::endl;
    }
    GameObject* enemy1 = new Enemy();
    enemy1->load(100, 100, 32, 32, "ash");
    m_gameObjects.push_back(enemy1);

    m_player = new Player();
    m_player->load(300, 300, 32, 32, "ash");
    m_gameObjects.push_back(m_player);

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
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
        m_gameObjects[i]->update();
    }
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);           // clear renderer with drawing color  

    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw(m_pRenderer);
    }

    SDL_RenderPresent(m_pRenderer);         // update the screen
}

void Game::clean() {
    std::cout << "Cleaning up and exiting the game..." << std::endl;
    std::cout << "Cleaning up game objects..." << std::endl;
    for(std::vector<GameObject*>::iterator itr = m_gameObjects.begin(); itr != m_gameObjects.end(); itr++) {
        delete *itr;
        std::cout << "Game object deleted!" << std::endl;
        m_gameObjects.erase(itr--);
    }
    TextureManager::Instance()->clean();
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

bool Game::isRunning() {
    return m_bRunning;
}