#include "FPSfixer.h"

FPSfixer* FPSfixer::s_pInstance = 0;

FPSfixer* FPSfixer::Instance() {
    if(s_pInstance == 0) {
        s_pInstance = new FPSfixer();
        return s_pInstance;
    }

    return s_pInstance;
}

