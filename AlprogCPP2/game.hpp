#ifndef GAME_HPP
#define GAME_HPP

#include "inventory.hpp"

class Game {
    private:
    Inventory inventory;

    public:
    void showMenu();
    void handleAddItem();
    void HandleShowItems();
    void countItemTypes();
    void run();
};

#endif 