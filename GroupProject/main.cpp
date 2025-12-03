#include<iostream>
#include <fstream>
#include <vector>
#include <string> 
using namespace std;
//might adjust prices on menu.txt to be more realistic prices.

class OrderSystem {
private:
    std::vector<std::string> order;

public:
    void displayMenu() {
        std::cout << "\n=== Base Options ===\n";
        std::cout << "1. Drink\n";
        std::cout << "2. Burger\n";
        std::cout << "3. Fries\n";
        std::cout << "4. Nuggets\n";
        std::cout << "5. Pizza\n";
        std::cout << "6. Complete Order\n";
        std::cout << "====================\n";
    }

    void addItem(const std::string& item) {
        // palce holder till prices added in
        order.push_back(item + " (PRICE TBD)");
        std::cout << "Added " << item << ".\n";
    }

    void completeOrder() {
        
        std::cout << "\n=== ORDER COMPLETE ===\n";
        if (order.empty()) {
            std::cout << "No items selected.\n";
        } else {
            for (const auto& item : order) {
                std::cout << "- " << item << "\n";
            }
        }
        std::cout << "======================\n";
    }
};
int main(){
    cout << "MENU\n";
    // Specify the path to your text file
    std::string filename = "menu.txt"; 

    // Create an ifstream object to read from the file
    std::ifstream inputFile(filename);

    // Check if the file was opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return 1; // Indicate an error
    }

    // Read and display the file content line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    // Close the file
    inputFile.close();
    
    //testing Area: move to where they are needed when done testing or function/class is created for it
    //array for drink and food sizes. for input options later
    cout << "\nSIZES:\n";
    string Sizes[] = {"Small", "Medium", "Large"};
    int Length1 = sizeof(Sizes) / sizeof(Sizes[0]);
        for (int i = 0; i < Length1 ; i++) {
        std::cout << Sizes[i] << "\n";//what prints each item in array
    }
    //array for pizza types. for input options later
    cout << "\nPIZZA TYPE:\n";
    string PizzaTypes[] = {"Pepperoni", "Sausage", "Cheese", "Custom"};
    int Length2 = sizeof(PizzaTypes) / sizeof(PizzaTypes[0]);
        for (int i = 0; i < Length2 ; i++) {
        std::cout << PizzaTypes[i] << "\n"; //what prints each item in array
        }

    //display stuff for order class
    OrderSystem os;
    int choice = 0;

    while (true) {
        os.displayMenu();
        std::cout << "Select an option (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1: os.addItem("Drink"); break;
            case 2: os.addItem("Burger"); break;
            case 3: os.addItem("Fries"); break;
            case 4: os.addItem("Nuggets"); break;
            case 5: os.addItem("Pizza"); break;
            case 6: 
                os.completeOrder();
                return 0;
            default:
                std::cout << "Invalid selection. Try again.\n";
        }
    }
    // return statement don't move
    return 0;
}
