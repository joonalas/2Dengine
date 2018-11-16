#include "PlayState.h"
#include "Game.h"
#include "TextureManager.h"
#include "Player.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "StateChangeException.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        Game::Instance()->getStateMachine()->pushState(new PauseState());
    }
    try {
        for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
            m_gameObjects[i]->update();
        }
    } catch(StateChangeException& e) {}
}

void PlayState::render() {
    for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool PlayState::onEnter() {
    if(!TextureManager::Instance()->load("/home/joonas/Documents/C/2Dengine/Assets/ashsprites.png", "player", Game::Instance()->getRenderer())) {
        std::cerr << "WARNING!!! Texture load error!" << std::endl;
        return false;
    }

    LoaderParams* pParams = new LoaderParams(10, 10, 32, 32, "player");
    m_gameObjects.push_back(new Player(pParams));
    delete pParams;

    return true;
}

bool PlayState::onExit() {
    std::cout << "Play state exit!!!" << std::endl;
    for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
        delete m_gameObjects[i];
    }
    m_gameObjects.clear();
    TextureManager::Instance()->clearFromTextureMap("player");
    return true;
}