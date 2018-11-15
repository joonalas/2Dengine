#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

Player::~Player() {}

void Player::draw() {
    SDLGameObject::draw();
}

void Player::update() {
    handleInput();
    m_currentFrame = int( ( (SDL_GetTicks() / 100) % 5 ) );
    SDLGameObject::update();
}

void Player::clean() {
    std::cout << "cleaning player object." << std::endl;
}

void Player::handleInput() {
    Vector2D* vec = InputHandler::Instance()->getMousePosition();
    m_velocity = (*vec - m_position)/70;
    if(m_velocity.getX() > 0) {
        m_spriteFlip = SDL_FLIP_HORIZONTAL;
    }
    if(m_velocity.getX() < 0) {
        m_spriteFlip = SDL_FLIP_NONE;
    }
}