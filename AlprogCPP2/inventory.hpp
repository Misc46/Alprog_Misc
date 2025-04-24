#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include "item.hpp"

class Inventory {
    private:
    vector<Item> items;

    public:
    void addItem(Item item);
    void showItems();
    vector<Item> getItems();
};

#endif