#pragma once

#include <string>
#include <iostream>

class BaseRenderer {

public:
    BaseRenderer() = default;

    virtual void RenderText( const char * text ) {
        std::cout << m_ColorCode << text << std::endl;
    }

protected:

    std::string
        m_ColorCode;
};
