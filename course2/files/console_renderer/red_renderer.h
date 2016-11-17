#include "base_renderer.h"

class RedRenderer : public BaseRenderer {
public:

    RedRenderer() :
        BaseRenderer()
    {
        m_ColorCode = "\033[31;1m";
    }
};
