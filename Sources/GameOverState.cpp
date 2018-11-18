#include "GameOverState.h"
#include "Game.h"
#include "GameOverState.h"
#include "PlayState.h"
#include "StateChangeException.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"
#include "MenuState.h"

const std::string GameOverState::s_gameOverID = "GAME OVER";

void GameOverState::s_gameOverToMain() {
    Game::Instance()->getStateMachine()->changeState(new MenuState());
    throw(StateChangeException());
}

void GameOverState::s_restartPlay() {
    Game::Instance()->getStateMachine()->changeState(new PlayState());
    throw(StateChangeException());
}

void GameOverState::update() {
    try {
        for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
            m_gameObjects[i]->update();
        }
    } catch(StateChangeException& e) {}
}

void GameOverState::render() {
    for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool GameOverState::onEnter() {
    //Texture loading
    if(!TextureManager::Instance()->load("Assets/playbutton.png", "playbutton", Game::Instance()->getRenderer())) {
        std::cerr << "WARNING!!! Texture load error!" << std::endl;
        return false;
    }
    if(!TextureManager::Instance()->load("Assets/exitbutton.png", "exitbutton", Game::Instance()->getRenderer())) {
        std::cerr << "WARNING!!! Texture load error!" << std::endl;
        return false;
    }
    if(!TextureManager::Instance()->load("Assets/gameover.png", "gameover", Game::Instance()->getRenderer())) {
        std::cerr << "WARNING!!! Texture load error!" << std::endl;
        return false;
    }

    //Game objects creation
    LoaderParams* pParams = new LoaderParams(265, 240, 110, 33, "playbutton");
    m_gameObjects.push_back(new MenuButton(pParams, s_restartPlay));
    delete pParams;
    pParams = new LoaderParams(265, 280, 110, 33, "exitbutton");
    m_gameObjects.push_back(new MenuButton(pParams, s_gameOverToMain));
    delete pParams;
    for(int i = 0; i < 8; i++) {
        pParams = new LoaderParams(230+i*21, 100, 21, 21, "gameover", i+1);
        m_gameObjects.push_back(new AnimatedGraphic(pParams, 5, 8));
        delete pParams;
    }

    return true;
}

bool GameOverState::onExit() {
    for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
        delete m_gameObjects[i];
    }
    std::vector<GameObject*> emptyVect;
    m_gameObjects.swap(emptyVect);
    TextureManager::Instance()->clearFromTextureMap("playbutton");
    TextureManager::Instance()->clearFromTextureMap("exitbutton");
    TextureManager::Instance()->clearFromTextureMap("gameover");
    return true;
}