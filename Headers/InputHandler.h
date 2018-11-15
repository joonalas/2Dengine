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
        bool isKeyDown(SDL_Scancode key);

        Vector2D* getMousePosition() { return m_mousePosition; }

    private:
        InputHandler();
        static InputHandler* s_pInstance;
        std::vector<bool> m_mouseButtonStates;
        Vector2D* m_mousePosition;
        const Uint8* m_keystates;
        void onKeyDown();
        void onKeyUp();
        void onMouseMotion(SDL_Event& event);
        void onMouseButtonDown(SDL_Event& event);
        void onMouseButtonUp(SDL_Event& event);

        /* Implement later...
        void onJoystickAxisMove(SDL_Event& event);
        void onJoystickButtonDown(SDL_Event& event);
        void onJoystickButtonUp(SDL_Event& event);
        */
};

enum mouse_buttons {
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

#endif