#include "menu.h"

#include <fstream>
#include <sstream>
#include <iostream>

// Open a menu and load it (returns true if successful, false if failure).
bool Menu::open(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        Option option;
        option.name = line;

        std::getline(file, line);
        std::istringstream details(line);
        std::getline(file, line);
        std::istringstream prices(line);

        details >> option.details[0] >> option.details[1] >> option.details[2];
        prices >> option.prices[0] >> option.prices[1] >> option.prices[2];

        items.push_back(option);
    }
    
    return true;
}

// Display all the menu items.
void Menu::display() {
    std::cout << "MENU:" << std::endl;
    for (int i = 0; i < items.size(); ++i)
        std::cout << i + 1 << ". " << items[i].name << std::endl;
    std::cout << items.size() + 1 << ". Complete Order" << std::endl;
}

Order::Item Menu::processOption() {
    int option;
    int detail;
    for (;;) {
        std::cout << "Select an Option (1-" << items.size() + 1 << "): ";
        std::cin >> option;

        if (option >= 1 && option <= items.size() + 1) {
            if (option == items.size() + 1) {
                Order::Item item;
                item.name = "";
                return item;
            }
            break;
        }

        std::cout << "Invalid option" << std::endl;
    }

    std::cout << std::endl;

    for (;;) {
        std::cout << "OPTIONS:" << std::endl;
        for (int i = 0; i < 3; ++i) {
            std::cout << i + 1 << ". " << items[option - 1].details[i] << std::endl;
        }

        std::cout << "Select an Option (1-3): ";
        std::cin >> detail;

        if (detail >= 1 && detail <= 3) {
            break;
        }

        std::cout << "Invalid option" << std::endl;
    }

    Order::Item item;

    item.name = items[option - 1].name;
    item.detail = items[option - 1].details[detail - 1];
    item.price = items[option - 1].prices[detail - 1];

    return item;
}
