#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "PlayState.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
    for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->update();
    }
}

void MenuState::render() {
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool MenuState::onEnter() {
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
    m_gameObjects.push_back(new MenuButton(pParams, s_menuToPlay));
    delete pParams;
    pParams = new LoaderParams(265, 280, 110, 33, "exitbutton");
    m_gameObjects.push_back(new MenuButton(pParams, s_exitFromMenu));
    delete pParams;

    return true;
}

bool MenuState::onExit() {
    for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
        delete m_gameObjects[i];
    }
    m_gameObjects.clear();
    TextureManager::Instance()->clearFromTextureMap("playbutton");
    TextureManager::Instance()->clearFromTextureMap("exitbutton");
    return true;
}

void MenuState::s_menuToPlay() {
    Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu() {
    Game::Instance()->quit();
}