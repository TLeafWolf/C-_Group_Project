#include "menu.h"

#include <fstream>
#include <iostream>

// Construct Menu object from given filename.
Menu::Menu(std::string filename) {
    std::ifstream file(filename);

    std::string line;
    while (std::getline(file, line))
        items.push_back(line);
}

// Display all the menu items.
void Menu::display() {
    std::cout << "Menu: " << std::endl;
    for (std::string &item : items)
        std::cout << item << std::endl;
}
