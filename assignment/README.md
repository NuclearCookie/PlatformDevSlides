## Platform dev assignment


The goal of the assignment is to create a virtual file system. The system should compile and run on at least 2 platforms. We advised to choose windows and linux, but you can implement on any other C++ target.

The system should contain the following features :

- Mount directory from user provided path
    - Mounting means listing and caching all existing file path into a structure
    - This structure is left unspecified
- Return the full path from a file name
- Get a list of file inside a directory
- Get a list of file with a given extension
- Return a valid File object, that allows file read/write

You can find several helpers to get your started :

- example.cpp : This is how your class could be used, but doesn't have to be exactly like this.
- File.h : A sample version of the File class, can be modified.
- FileSystem.h : A sample version of the FileSystem interface.


We will cover pack in class, but it will not be mandatory for the assignment.
