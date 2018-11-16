#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H

#include "GameObject.h"
#include "GameState.h"
#include <vector>

class PauseState : public GameState {
    public:
        virtual void update();
        virtual void render();
        virtual bool onEnter();
        virtual bool onExit();
        virtual std::string getStateID() const { return s_pauseID; }
    private:
        static void s_pauseToMain();
        static void s_resumePlay();
        static const std::string s_pauseID;
        std::vector<GameObject*> m_gameObjects;
};

#endif // !PAUSE_STATE_H