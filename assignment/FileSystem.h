#pragma once

#include <string>
#include <memory>
#include <vector>

class FileSystem
{

    void MountDirectory(const std::string & directory);

    std::string GetPhysicalFilePath( const std::string & filename) const;

    void GetFilesInDirectory( std::vector<std::string> & file_table, const std::string & directory) const;

    void GetFilesWithExtension( std::vector<std::string> & file_table, const std::string & extension) const;

    std::unique_ptr<File> GetFile( const std::string & filename ) const;
};
