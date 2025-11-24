#pragma once

#include <string>
#include <vector>

// Class representing a restaurant order.
class Order {
public:
    // TODO: Implement a way to add items to order.

    void print();

private:
    std::vector<std::string> items;
};
