#pragma once

#include "file_handle.h"
#include "file_access_flags.h"
#include "file_access_mode.h"
#include <string>

#if defined(PLATFORM_Linux)
#include "file_system_linux_references.h"
#elif defined(PLATFORM_Win)
#include "file_system_win_references.h"
#endif

class FILE_SYSTEM {
public:
    // linux: int open(const char *pathname,int flags, mode_t mode)
    // windows:
    /*
    HANDLE WINAPI CreateFile(
  _In_     LPCTSTR               lpFileName,
  _In_     DWORD                 dwDesiredAccess,
  _In_     DWORD                 dwShareMode,
  _In_opt_ LPSECURITY_ATTRIBUTES lpSecurityAttributes, // ignore
  _In_     DWORD                 dwCreationDisposition, // ignore
  _In_     DWORD                 dwFlagsAndAttributes, // ignore
  _In_opt_ HANDLE                hTemplateFile // ignore
);
*/
    static FILE_HANDLE Open( const char * pathName, FILE_ACCESS_FLAGS accessFlags, FILE_ACCESS_MODE accessMode );

    // linux: int close(int fd);
    // windows: BOOL WINAPI CloseHandle(_In_ HANDLE hObject);
    static bool Close( FILE_HANDLE handle );

    // linux: ssize_t read(int fd, void *buf, size_t count);
    // windows:
    /* BOOL WINAPI ReadFile(
  _In_        HANDLE       hFile,
  _Out_       LPVOID       lpBuffer,
  _In_        DWORD        nNumberOfBytesToRead,
  _Out_opt_   LPDWORD      lpNumberOfBytesRead,
  _Inout_opt_ LPOVERLAPPED lpOverlapped
    );*/
    static bool ReadFile( FILE_HANDLE handle, std::string & content );

    // linux: ssize_t write(int fd, const void *buf, size_t count);
    // windows:
    /*
    BOOL WINAPI WriteFile(
  _In_        HANDLE       hFile,
  _In_        LPCVOID      lpBuffer,
  _In_        DWORD        nNumberOfBytesToWrite,
  _Out_opt_   LPDWORD      lpNumberOfBytesWritten,
  _Inout_opt_ LPOVERLAPPED lpOverlapped
    ); */
    static bool WriteFile( FILE_HANDLE handle, const std::string & content );

private:
#if defined(PLATFORM_Linux)
    #include "file_system_linux_members.h"
#elif defined(PLATFORM_Win)

#endif
};
