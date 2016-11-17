#include "file_system.h"

#if defined(PLATFORM_Linux)
    #include "file_system_linux.hpp"
#elif defined(PLATFORM_Win)
    #include "file_system_win.hpp"
#else
    #include "file_system_stub.hpp"
#endif
