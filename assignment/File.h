#pragma once

#include "Mode.h"

class File
{
    virtual bool Open( Mode mode ) = 0;
    virtual size_t Read( uint8_t * buffer, size_t size ) = 0;
    virtual size_t Write( const uint8_t * buffer, size_t size ) = 0;
    virtual void Close() = 0;
};
