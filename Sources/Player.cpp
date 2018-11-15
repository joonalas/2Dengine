#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

Player::~Player() {}

void Player::draw() {
    SDLGameObject::draw();
}

void Player::update() {
    m_velocity.setX(0);
    m_velocity.setY(0);
    handleInput();

    if(m_velocity.getY() > 0) {
        m_currentRow = 4;
    }
    if(m_velocity.getY() < 0) {
        m_currentRow = 3;
    }
    if(m_velocity.getX() > 0) {
        m_currentRow = 1;
        m_spriteFlip = SDL_FLIP_HORIZONTAL;
    }
    if(m_velocity.getX() < 0) {
        m_currentRow = 1;
        m_spriteFlip = SDL_FLIP_NONE;
    }
    if(m_velocity.getX() == 0 && m_velocity.getY() == 0) {
        m_currentFrame = 0;
    } else {
        m_currentFrame = int( ( (SDL_GetTicks() / 100) % 5 ) );
    }

    SDLGameObject::update();
}

void Player::clean() {
    std::cout << "cleaning player object." << std::endl;
}

void Player::handleInput() {
    Vector2D* vec = InputHandler::Instance()->getMousePosition();
    /*m_velocity = (*vec - m_position)/70;*/
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_velocity.setX(2);
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        m_velocity.setX(-2);
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        m_velocity.setY(-2);
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        m_velocity.setY(2);
    }
}