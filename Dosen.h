#ifndef DOSEN_H
#define DOSEN_H

#include <string>
using namespace std;

class Dosen
{
private:
    string name;
    int id;

public:
    Dosen(string name, int id);
    string getName();
    void setName(string name);
    void setId(int id);
};

#endif
