#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed, int numOfFrames) : SDLGameObject(pParams), 
m_animSpeed(animSpeed), m_numOfFrames(numOfFrames) {
}

AnimatedGraphic::~AnimatedGraphic() {}

void AnimatedGraphic::draw() {
    SDLGameObject::draw();
}

void AnimatedGraphic::update() {
    m_currentFrame = int( ( (SDL_GetTicks() / (1000 / m_animSpeed) + m_startingFrame) % m_numOfFrames ) );
    SDLGameObject::update();
}

void AnimatedGraphic::clean() {
    std::cout << "cleaning AnimatedGraphic object." << std::endl;
}