/*
 ============================================================================
 Author      : Marko Martinović
 Description : Copy input file into output file
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "file_system.h"

int main(int argc, char* argv[]) {

    FILE_HANDLE input_fd;
    FILE_HANDLE output_fd;

    /* Are src and dest file name arguments missing */
    if(argc != 3){
        printf ("Usage: cp file1 file2");
        return 1;
    }

    /* Create input file descriptor */

    input_fd = FILE_SYSTEM::Open(argv [1], FILE_ACCESS_FLAGS(), FILE_ACCESS_MODE::Read);
    if (input_fd == FILE_HANDLE_INVALID) {
            std::cerr << "open";
            return 2;
    }

    /* Create output file descriptor */
    FILE_ACCESS_FLAGS output_flags;
    output_flags.SetFlags( FILE_ACCESS_FLAGS::FLAGS::Create | FILE_ACCESS_FLAGS::FLAGS::Truncate );
    output_fd = FILE_SYSTEM::Open(argv[2], output_flags, FILE_ACCESS_MODE::Write );
    if(output_fd == FILE_HANDLE_INVALID){
        std::cerr << "open";
        return 3;
    }

    /* Copy process */
    std::string content;
    FILE_SYSTEM::ReadFile(input_fd, content);
    if ( !FILE_SYSTEM::WriteFile(output_fd, content) )
    {
        std::cerr << "write";
        return 4;
    }

    /* Close file descriptors */
    FILE_SYSTEM::Close (input_fd);
    FILE_SYSTEM::Close (output_fd);

    return (EXIT_SUCCESS);
}
