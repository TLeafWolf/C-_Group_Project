#pragma once

#include <string>
#include <vector>

#include "order.h"

// Class representing the restaurant's menu.
class Menu {
public:
    // Opens the menu file, returning true on success
    bool open(std::string filename);

    // Displays the menu
    void display();

    // Processes an option in the menu
    Order::Item processOption();

private:
    // An option for a menu item
    struct Option {
        std::vector<std::string> names;
        std::vector<double> prices;
    };

    // A menu item
    struct Item {
        std::string name;
        std::vector<Option> options;
    };

    // The array of menu items
    std::vector<Item> items;
};
