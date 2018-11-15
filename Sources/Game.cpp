#include "Game.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"
#include <iostream>

Game* Game::s_pInstance = 0;

Game::Game() {
    m_pWindow = 0;
    m_pRenderer = 0;
    m_currentFrame = 0;
    m_bRunning = true;
}

Game::~Game() {}

Game* Game::Instance() {
    if(s_pInstance == 0) {
        s_pInstance = new Game();
        return s_pInstance;
    }
    return s_pInstance;
}

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

    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MenuState());

    return true; // SDL initialization success
}

void Game::handleEvents() {
    InputHandler::Instance()->handleEvents();

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
        m_pGameStateMachine->changeState(new PlayState());
    }
}

void Game::update() {
    m_pGameStateMachine->update();
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);           // clear renderer with drawing color  

    m_pGameStateMachine->render();

    SDL_RenderPresent(m_pRenderer);         // update the screen
}

void Game::clean() {
    m_pGameStateMachine->popState();
    std::cout << "Cleaning up and exiting the game..." << std::endl;
    TextureManager::Instance()->clean();
    InputHandler::Instance()->clean();
    delete m_pGameStateMachine;
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
    delete s_pInstance;
}

bool Game::isRunning() {
    return m_bRunning;
}