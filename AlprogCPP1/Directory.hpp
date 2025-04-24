#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include "File.hpp"
#include <vector>
using namespace std;

class Directory
{
private:
    string name;
    vector<File> files;

public:
    Directory(string name);
    void addFile(string fileName);
    vector<File> &getFiles();
    string getName();
};

#endif
