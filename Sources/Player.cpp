#include "Player.h"

Player::~Player() {}

void Player::load(int x, int y, int width, int height, std::string textureID) {
    GameObject::load(x,y,width,height,textureID);
}

void Player::draw(SDL_Renderer* pRenderer) {
    GameObject::draw(pRenderer);
}

void Player::update() {
    m_currentFrame = int( ( (SDL_GetTicks() / 100) % 5 ) );
    m_x--;
}

void Player::clean() {
    GameObject::clean();
    std::cout << "cleaning player object." << std::endl;
}