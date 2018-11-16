#include "PauseState.h"
#include "Game.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "StateChangeException.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain() {
    Game::Instance()->getStateMachine()->changeState(new MenuState());
    throw(StateChangeException());
}

void PauseState::s_resumePlay() {
    Game::Instance()->getStateMachine()->popState();
}

void PauseState::update() {
    try {
        for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
            m_gameObjects[i]->update();
        }
    } catch(StateChangeException& e) {}
}

void PauseState::render() {
    for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool PauseState::onEnter() {
    //Texture loading
    if(!TextureManager::Instance()->load("/home/joonas/Documents/C/2Dengine/Assets/playbutton.png", "playbutton", Game::Instance()->getRenderer())) {
        std::cerr << "WARNING!!! Texture load error!" << std::endl;
        return false;
    }
    if(!TextureManager::Instance()->load("/home/joonas/Documents/C/2Dengine/Assets/exitbutton.png", "exitbutton", Game::Instance()->getRenderer())) {
        std::cerr << "WARNING!!! Texture load error!" << std::endl;
        return false;
    }

    //Game objects creation
    LoaderParams* pParams = new LoaderParams(265, 240, 110, 33, "playbutton");
    m_gameObjects.push_back(new MenuButton(pParams, s_resumePlay));
    delete pParams;
    pParams = new LoaderParams(265, 280, 110, 33, "exitbutton");
    m_gameObjects.push_back(new MenuButton(pParams, s_pauseToMain));
    delete pParams;

    return true;
}

bool PauseState::onExit() {
    for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
        delete m_gameObjects[i];
    }
    m_gameObjects.clear();
    TextureManager::Instance()->clearFromTextureMap("playbutton");
    TextureManager::Instance()->clearFromTextureMap("exitbutton");
    return true;
}