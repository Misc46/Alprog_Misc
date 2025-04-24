#include "Directory.hpp"

Directory::Directory(string name)
{
    this->name = name;
}

void Directory::addFile(string fileName)
{
    files.push_back(File(fileName));
}

vector<File> &Directory::getFiles()
{
    return files;
}

string Directory::getName()
{
    return name;
}
