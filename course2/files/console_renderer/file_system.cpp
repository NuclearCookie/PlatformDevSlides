// file_system.cpp
#include "file_system.h"

#if defined(PLATFORM_Windows)
    #include "file_system_windows.hpp"
#elif defined(PLATFORM_Linux)
    #include "file_system_linux.hpp"
#else
    #include "file_system_stub.hpp"
#endif
