#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL.h>
#include <iostream>
#include <string>
#include "LoaderParams.h"

class GameObject {
    public:
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void clean() = 0;
        virtual ~GameObject() {}
    protected:
        GameObject(const LoaderParams* pParams) { std::cout << "GameObject() constructor says hi!" << std::endl; }
        GameObject() {}
};

#endif