#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL.h>
#include <vector>
#include "Vector2D.h"

class InputHandler {
    public:
        static InputHandler* Instance() {
            if(s_pInstance == 0) {
                s_pInstance = new InputHandler();
                return s_pInstance;
            }

            return s_pInstance;
        }

        //void update();
        void handleEvents();
        void clean();
        bool getMouseButtonState(int buttonNumber) {
            return m_mouseButtonStates[buttonNumber];
        }

        Vector2D* getMousePosition() { return m_mousePosition; }

    private:
        InputHandler();
        static InputHandler* s_pInstance;
        std::vector<bool> m_mouseButtonStates;
        Vector2D* m_mousePosition;
};

enum mouse_buttons {
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

#endif