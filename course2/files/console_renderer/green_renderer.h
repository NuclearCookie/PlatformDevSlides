#pragma once

#include "base_renderer.h"

class GreenRenderer : public BaseRenderer {
public:

    GreenRenderer() :
        BaseRenderer()
    {
        #if defined(PLATFORM_Linux)
            m_ColorCode = "\033[32;1m";
        #else
            // windows implementation
            uncompilable gibberish sdlkadsflaslfdlasdflaskdflkasfjdlkajsf
        #endif
    }
};
