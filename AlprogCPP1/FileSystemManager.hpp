#ifndef FILESYSTEMMANAGER_HPP
#define FILESYSTEMMANAGER_HPP

#include "Directory.hpp"

class FileSystemManager
{
private:
    Directory directory;

public:
    FileSystemManager(Directory dir);
    void touch(string name);
    void echo(string content, string name, int mode);
    void cat(string name);
    void ls();
    void run();
};

#endif
