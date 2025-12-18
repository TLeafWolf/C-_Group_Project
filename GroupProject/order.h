#pragma once

#include <string>
#include <vector>
#include <iostream>

// Struct representing a single order item.
struct orderItem {
    std::string name;
    int quantity;
    double price;
};

// Class representing a restaurant order.
class Order {
public:
    //Order();

    struct Item {
        std::string name;
        std::string detail;
        double price;
    };

    // Add an item to the order
    void addItem(const std::string& name, const std::string& detail, double price);

    // Print order details
    void print() const;

    // Write to File
    void writeToFile(const std::string& filename = "orders.txt") const;

private:
    std::vector<Item> items;
};
