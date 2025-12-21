#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

#include "menu.h"
#include "order.h"

using namespace std;

int main() {
    // Create a menu
    Menu menu;

    // Check if menu opens successfully
    if (!menu.open("menu.txt")) {
        return 1;
    }

    // Create an order
    Order order;

    // Main loop
    while (true) {
        // Display the menu
        menu.display();

        // Get the chosen item from the menu
        Order::Item item = menu.processOption();

        // If item's name is empty, user has completed the order
        if (item.name.empty()) {
            order.print();
            break;
        }

        // Add the item to the order
        order.addItem(item.name, item.details, item.price);
    }

    // Write the finished order to the file
    order.writeToFile();

    return 0;
}
