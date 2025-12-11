#include "order.h"

#include <iostream>
#include <fstream>

// Add an item to the order
void Order::addItem(const std::string& itemName, int quantity, double price) {
    Item item;
    item.name = itemName;
    item.quantity = quantity;
    item.price = price;
    items.push_back(item);
}

// Prints the order details into console.
void Order::print() const {
    std::cout << "Your order:\n";
    for (const auto& item : items) {
        std::cout << item.name << item.quantity << item.price << std::endl;
    }
}

// Prints the order details to orders.txt
void Order::writeToFile(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    for (const auto& item : items) {
        file << item.name << item.quantity << item.price;
    }

    file.close();
}
