#pragma once

#include <string>
#include <vector>

// Class representing the restaurant's menu.
class Menu {
public:
    Menu(std::string filename);

    void display();

private:
    std::vector<std::string> items;
};
