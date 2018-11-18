#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {
    m_velocity.setY(2);
}

Enemy::~Enemy() {}

void Enemy::draw() {
    SDLGameObject::draw();
}

void Enemy::update() {
    m_currentFrame = int( ( (SDL_GetTicks() / 100) % 5 ) );
    if(m_position.getY() >= 400) {
        m_velocity.setY(-2);
    } else if(m_position.getY() <= 0) {
        m_velocity.setY(2);
    }
    SDLGameObject::update();
}

void Enemy::clean() {
    std::cout << "cleaning Enemy object." << std::endl;
}