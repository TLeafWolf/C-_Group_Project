#pragma once

#include <string>
#include <vector>

#include "order.h"

// Class representing the restaurant's menu.
class Menu {
public:
    bool open(std::string filename);
    void display();
    Order::Item processOption();

private:
    struct Option {
        std::vector<std::string> names;
        std::vector<double> prices;
    };

    struct Item {
        std::string name;
        std::vector<Option> options;
    };

    std::vector<Item> items;
};
