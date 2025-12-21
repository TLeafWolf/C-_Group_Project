#include "menu.h"

#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

// Open a menu and load it (returns true if successful, false if failure).
bool Menu::open(std::string filename) {
    // Open file
    std::ifstream file(filename);

    // Check if file failed to open
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    // Get each line of the file
    std::string line;
    while (std::getline(file, line)) {
        // If line is empty, skip it
        if (line.empty())
            continue;
        
        // For some reason the online compiler doesn't like the carriage return (\r), so remove it if it exists
        if (line.back() == '\r')
            line.pop_back();
        
        // Check if line begins with a hyphen, and if so, create a new item for it
        if (line[0] == '-') {
            Item item;
            item.name = line.substr(1);
            items.push_back(item);
            std::getline(file, line);
        }

        // Get the lines and create istringstreams for them
        std::istringstream names(line);
        std::getline(file, line);
        std::istringstream prices(line);

        // Make a new option
        Option option;

        // Read each name from the line
        std::string name;
        while (names >> name) {
            option.names.push_back(name);
        }

        // Read each price from the line
        double price;
        while (prices >> price) {
            option.prices.push_back(price);
        }

        // Add option to the last item in the array
        items[items.size() - 1].options.push_back(option);
    }
    
    // Menu opened successfully
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
    // The selected option
    int option;

    // Loop through menu items and have user select one
    for (;;) {
        // Prompt user to select an item
        std::cout << "Select an Item (1-" << items.size() + 1 << "): ";
        std::cin >> option;

        // If user selects one, break (or return if option is last option [complete order])
        if (option >= 1 && option <= items.size() + 1) {
            if (option == items.size() + 1) {
                Order::Item item;
                item.name = "";
                return item;
            }
            break;
        }

        // Repeat if option is invalid
        std::cout << "Invalid option" << std::endl;
    }

    std::cout << std::endl;

    // Get the selected menu item
    Item item = items[option - 1];

    // The suboption selected for the current option
    int suboption;

    // The names of the selection options
    std::vector<std::string> option_names;

    // The accumulated total price
    double total = 0.0;
    
    // Loop through all the options until the user has made a valid selection for each
    for (int i = 0; i < item.options.size(); ++i) {
        std::cout << "OPTIONS:" << std::endl;

        // Display option names and prices
        for (int j = 0; j < item.options[i].names.size(); ++j) {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << j + 1 << ". " << item.options[i].names[j] << " - $" << item.options[i].prices[j] << std::endl;
        }

        // Prompt user to select option
        std::cout << "Select an Option (1-" << item.options[i].names.size() << "): ";
        std::cin >> suboption;

        // If selected option is invalid, repeat until it is valid
        if (suboption < 1 || suboption > item.options[i].names.size()) {
            std::cout << "Invalid option." << std::endl;
            --i;
            continue;
        }

        // Add the option's name into the option_names array
        option_names.push_back(item.options[i].names[suboption - 1]);

        // Add the option price to the total
        total += item.options[i].prices[suboption - 1];
    }

    // Create a new order item
    Order::Item order_item;

    // Set the selected options in the order item
    order_item.name = item.name;
    order_item.details = option_names;
    order_item.price = total;

    return order_item;
}
