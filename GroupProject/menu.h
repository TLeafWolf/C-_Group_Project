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
        std::string name;
        std::string details[3];
        double prices[3];
    };

    std::vector<Option> items;
};
