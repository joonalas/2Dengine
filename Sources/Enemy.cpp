#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

Enemy::~Enemy() {}

void Enemy::draw() {
    SDLGameObject::draw();
}

void Enemy::update() {
    m_currentFrame = int( ( (SDL_GetTicks() / 100) % 5 ) );
    m_acceleration.setX(-0.05);
    m_acceleration.setY(-0.05);
    SDLGameObject::update();
}

void Enemy::clean() {
    std::cout << "cleaning Enemy object." << std::endl;
}