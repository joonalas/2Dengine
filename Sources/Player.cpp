#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

Player::~Player() {}

void Player::draw() {
    SDLGameObject::draw();
}

void Player::update() {
    m_currentFrame = int( ( (SDL_GetTicks() / 100) % 5 ) );
    m_x--;
}

void Player::clean() {
    std::cout << "cleaning player object." << std::endl;
}