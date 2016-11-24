#Virtual filesystem


##Why?

- Searching for files is slow
- Require precise knowledge of the layout
- Might change from platform to platform
    - Some platform separate read-only and read-write path
- How to manage different version?
- How to manage files in archives


##Solution

- A virtual file system
    - List all the files at startup ( or compile-time )
    - Sort them, filter them
    - Access them by best methods ( filename, filetype, version )


## First step

- Mount all files from a given directory
- Use windows API
- Write those methods :

```
class FileSystem
{    
    void MountDirectory(const string & directory);
    string GetPhysicalFilePath(const string & filename) const;
    void GetFilesInDirectory(
        vector<string> & file_table, const string & directory) const;
    void GetFilesWithExtension(
        vector<string> & file_table, const string & extension) const;
};
```


##More abstraction

- What if file has no path? (archive, network)
- What if API is different ? (save system)
- Abstract the file!


##Second step

```
class File
{
    virtual bool open( Mode mode ) = 0;
    virtual size_t read( uint8_t * buffer, size_t size ) = 0;
    virtual size_t write( const uint8_t * buffer, size_t size ) = 0;
    virtual void close() = 0;
}
class FileSystem
{    
    bool GetPhysicalFilePath(
        string & filepath, const string & filename) const;
    void GetFilesInDirectory(
        vector<string> & file_table, const string & directory) const;
    void GetFilesWithExtension(
        vector<string> & file_table, const string & extension) const;
    unique_ptr<File> GetFile( const string & filename ) const;
};
```

##Exam assignment

- Implement for Linux (using Pieter's techniques)
- Implement a pack system (preferably custom)
