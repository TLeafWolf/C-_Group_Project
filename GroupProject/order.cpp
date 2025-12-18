#include "order.h"

#include <iostream>
#include <iomanip>
#include <fstream>

// Add an item to the order
void Order::addItem(const std::string& name, const std::string& detail, double price) {
    Item item;
    item.name = name;
    item.detail = detail;
    item.price = price;
    items.push_back(item);
}

// Prints the order details into console.
void Order::print() const {
    double total = 0.0;

    std::cout << "YOUR ORDER:" << std::endl;
    for (const auto& item : items) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << item.name << " - " << item.detail << ": $" << item.price << std::endl;
        total += item.price;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::endl << "YOUR TOTAL:" << std::endl << '$' << total << std::endl;
}

// Prints the order details to orders.txt (might be uneeded and removed)
void Order::writeToFile(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    for (const auto& item : items) {
        file << item.name << item.detail << item.price;
    }

    file.close();
}
