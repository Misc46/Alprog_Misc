#ifndef FILE_HPP
#define FILE_HPP

#include <string>
using namespace std;

class File
{
private:
    string name;
    string content;

public:
    File(string name);
    string getName();
    string getContent();
    void setContent(string newContent);
    void appendContent(string extraContent);
};

#endif
