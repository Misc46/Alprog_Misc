#include "FileSystemManager.hpp"

int main()
{
    Directory dir("root");
    FileSystemManager manager(dir);
    manager.run();
    return 0;
}