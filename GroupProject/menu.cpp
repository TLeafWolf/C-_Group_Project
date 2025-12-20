#include "menu.h"

#include <fstream>
#include <sstream>
#include <iomanip>
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
        if (line.empty())
            continue;
        
        // For some reason the online compiler doesn't like the carriage return (\r), so remove it if it exists
        if (line.back() == '\r')
            line.pop_back();
        
        if (line[0] == '-') {
            Item item;
            item.name = line.substr(1);
            items.push_back(item);
            std::getline(file, line);
        }

        std::istringstream names(line);
        std::getline(file, line);
        std::istringstream prices(line);

        Option option;

        std::string name;
        while (names >> name) {
            option.names.push_back(name);
        }

        double price;
        while (prices >> price) {
            option.prices.push_back(price);
        }

        items[items.size() - 1].options.push_back(option);
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
        std::cout << "Select an Item (1-" << items.size() + 1 << "): ";
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

    Item item = items[option - 1];
    int suboption;

    std::vector<std::string> option_names;
    double total = 0.0;
    
    for (int i = 0; i < item.options.size(); ++i) {
        std::cout << "OPTIONS:" << std::endl;

        for (int j = 0; j < item.options[i].names.size(); ++j) {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << j + 1 << ". " << item.options[i].names[j] << " - $" << item.options[i].prices[j] << std::endl;
        }

        std::cout << "Select an Option (1-" << item.options[i].names.size() << "): ";
        std::cin >> suboption;

        if (suboption < 1 || suboption > item.options[i].names.size()) {
            std::cout << "Invalid option." << std::endl;
            --i;
            continue;
        }

        option_names.push_back(item.options[i].names[suboption - 1]);
        total += item.options[i].prices[suboption - 1];
    }

    Order::Item order_item;

    order_item.name = item.name;
    order_item.details = option_names;
    order_item.price = total;

    return order_item;
}
