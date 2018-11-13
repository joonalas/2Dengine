#include "Enemy.h"

Enemy::~Enemy() {}

void Enemy::load(int x, int y, int width, int height, std::string textureID) {
    GameObject::load(x,y,width,height,textureID);
}

void Enemy::draw(SDL_Renderer* pRenderer) {
    GameObject::draw(pRenderer);
}

void Enemy::update() {
    m_currentFrame = int( ( (SDL_GetTicks() / 100) % 5 ) );
    m_x++;
}

void Enemy::clean() {
    GameObject::clean();
    std::cout << "cleaning Enemy object." << std::endl;
}