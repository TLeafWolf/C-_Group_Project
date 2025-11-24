#include "order.h"

#include <iostream>

// Prints the order details.
void Order::print() {
    std::cout << "Your order:" << std::endl;
    for (std::string &item : items)
        std::cout << item << std::endl;
}
