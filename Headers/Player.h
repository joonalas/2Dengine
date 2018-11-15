#ifndef PLAYER_H
#define PLAYER_H

#include "SDLGameObject.h"

class Player : public SDLGameObject {
    public:
        Player(const LoaderParams* pParams);
        ~Player();
        virtual void draw();
        virtual void update();
        virtual void clean();
    protected:
        void handleInput();
};

#endif