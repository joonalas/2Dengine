#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler() {
    for(int i = 0; i < 3; i++) {
        m_mouseButtonStates.push_back(false);
    }
    m_mousePosition = new Vector2D(0, 0);
}

void InputHandler::handleEvents() {
    SDL_Event event;
    if(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                Game::Instance()->quit();
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button == SDL_BUTTON_LEFT) {
                    m_mouseButtonStates[LEFT] = true;
                }
                if(event.button.button == SDL_BUTTON_MIDDLE) {
                    m_mouseButtonStates[MIDDLE] = true;
                }
                if(event.button.button == SDL_BUTTON_RIGHT) {
                    m_mouseButtonStates[RIGHT] = true;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if(event.button.button == SDL_BUTTON_LEFT) {
                    m_mouseButtonStates[LEFT] = false;
                }
                if(event.button.button == SDL_BUTTON_MIDDLE) {
                    m_mouseButtonStates[MIDDLE] = false;
                }
                if(event.button.button == SDL_BUTTON_RIGHT) {
                    m_mouseButtonStates[RIGHT] = false;
                }
                break;
            case SDL_MOUSEMOTION:
                m_mousePosition->setX(event.motion.x);
                m_mousePosition->setY(event.motion.y);
                break;
            default:
                break;
        }
    }
}

void InputHandler::clean() {
    delete m_mousePosition;
    delete s_pInstance;
}