#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
using namespace std;

class Item {
    private:
    string name;
    string type;

    public:
    Item(string name, string type);
    string getName();
    string getType();
};
#endif