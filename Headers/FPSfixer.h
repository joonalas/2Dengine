#ifndef FPS_H
#define FPS_H

#include <SDL.h>

class FPSfixer {
    public:
        static FPSfixer* Instance();
        int getFPS() {return m_fps;}
        int getDelayTime() {return m_delayTime;}
        void setFPS(int fps) {m_fps=fps;}
        void setDelayTime(int delayTime) {m_delayTime = delayTime;}
        Uint32 getFrameStart() {return m_frameStart;}
        Uint32 getFrameTime() {return m_frameTime;}
        void startFrame() {m_frameStart = SDL_GetTicks();}
        void stopFrame() {m_frameTime = SDL_GetTicks() - m_frameStart;}
        void clean() {delete s_pInstance;}
    private:
        FPSfixer() : m_fps(0), m_delayTime(0), m_frameStart(0), m_frameTime(0) {}
        static FPSfixer* s_pInstance;
        int m_fps;
        int m_delayTime;
        Uint32 m_frameStart, m_frameTime;
};

#endif