#include "PlayState.h"
#include "Game.h"
#include "TextureManager.h"
#include "Player.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "StateChangeException.h"
#include "GameOverState.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        Game::Instance()->getStateMachine()->pushState(new PauseState());
    }
    try {
        for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
            m_gameObjects[i]->update();
        }

        if(checkCollision(dynamic_cast<SDLGameObject*> (m_gameObjects[0]), 
        dynamic_cast<SDLGameObject*> (m_gameObjects[1]))) {
            Game::Instance()->getStateMachine()->pushState(new GameOverState());
        }
    } catch(StateChangeException& e) {}
}

void PlayState::render() {
    for(std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool PlayState::onEnter() {
    if(!TextureManager::Instance()->load("Assets/ashsprites.png", "player", Game::Instance()->getRenderer())) {
        std::cerr << "WARNING!!! Texture load error!" << std::endl;
        return false;
    }

    LoaderParams* pParams = new LoaderParams(10, 10, 32, 32, "player");
    m_gameObjects.push_back(new Player(pParams));
    std::cout << "pparams player: " << pParams->getInitFrame() << pParams->getInitRow() << std::endl;
    delete pParams;

    pParams = new LoaderParams(400, 10, 32, 32, "player");
    m_gameObjects.push_back(new Enemy(pParams));
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

bool PlayState::checkCollision(SDLGameObject* object1, SDLGameObject* object2) {
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = object1->getPosition()->getX();
    rightA = leftA + object1->getWidth();
    topA = object1->getPosition()->getY();
    bottomA = topA + object1->getHeight();

    leftB = object2->getPosition()->getX();
    rightB = leftB + object2->getWidth();
    topB = object2->getPosition()->getY();
    bottomB = topB + object2->getHeight();
    
    if(((bottomA >= topB && bottomA <= bottomB) || (topA <= bottomB && topA >= topB))
    && ((rightA >= leftB && rightA <= rightB) || (leftA <= rightB && leftA >= leftB))) {
        return true;
    }

    return false;
}