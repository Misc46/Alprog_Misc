#include <iostream>
#include "Item.hpp"
#include "inventory.hpp"
#include "game.hpp"

Item::Item(string name, string type) {
    this -> name = name;
    this -> type = type;
}
string Item::getName() { return name; }
string Item::getType() { return type; }

void Inventory::addItem(Item item) {
    items.push_back(item);
}
void Inventory::showItems() {
    cout << "\nCurrent Inventory:\n";
    for (auto &item : items) {
        cout << item.getName() << " (" << item.getType() << ")\n";
    }
}
vector<Item> Inventory::getItems() {
    return items;
}

void Game::showMenu(){
    cout << "\n====Game Inventory Menu====\n";
    cout << "1. Add Item\n";
    cout << "2. Show Inventory\n";
    cout << "3. Count Item Types\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

void Game::handleAddItem(){
    string name, type;
    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter item type (Weapon/Potion): ";
    cin >> type;
    inventory.addItem(Item(name, type));
    cout << "Item added!\n";
}

void Game::HandleShowItems() {
    inventory.showItems();
}

void Game::countItemTypes() {
    int weapon = 0, potion = 0;
    for (Item item : inventory.getItems()) {
        if (item.getType() == "Weapon") weapon++;
        else if (item.getType() == "Potion") potion++;
    }
    cout << "\nItem Types in Inventor:\n";
    cout << "Potion: " << potion << "x\n";
    cout << "Weapon: " << weapon << "x\n";
}

void Game::run() {
    int choice;
    while(1){
        showMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            handleAddItem();
            break;
        case 2:
            HandleShowItems();
            break;
        case 3:
            countItemTypes();
            break;
        case 4:
            cout << "Exiting game!\n";
            return;
        default:
            cout << "Invalid choice.\n";
        }
    }
}

int main(){
    Game g;
    g.run();
    return 0;
}