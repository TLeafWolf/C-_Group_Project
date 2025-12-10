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
    Order(int orderID);

    // Add an item to the order
    void addItem(const std::string& itemName, int quantity, double price);

    // Print order details
    void print() const;

private:
    int orderID;
    std::vector<std::string> items;
};
