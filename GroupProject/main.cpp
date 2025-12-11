#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
// might adjust prices later

class OrderSystem {
private:
    vector<string> order;
    double total = 0.0;

    // Prices for items based on size (Small, Medium, Large)
    const double drinkPrices[3]  = {2.00, 3.00, 4.00};
    const double burgerPrices[3] = {7.00, 10.00, 15.00};
    const double friesPrices[3]  = {2.29, 3.29, 4.29};
    const double nuggetPrices[3] = {2.99, 3.99, 4.99}; 
    const double pizzaPrices[3]  = {10.00, 15.00, 20.00};

public:
    void displayMenu() {
        cout << "\nSelect Item\n";
        cout << "1. Drink\n";
        cout << "2. Burger\n";
        cout << "3. Fries\n";
        cout << "4. Nuggets\n";
        cout << "5. Pizza\n";
        cout << "6. Complete Order\n";
    }

    // Adds an item to the order and prints its details. remove what we need to once we succesfully get order.cpp and order.h working with this main file.
    void addItem(const string& item, const string& detail, double price) {
        stringstream ss;
        ss << fixed << setprecision(2) << price;

        order.push_back(item + " - " + detail + " : $" + ss.str());

        total += price;

        cout << fixed << setprecision(2);
        cout << "Added " << item << " (" << detail << ") - $" << price << "\n";
    }

    // Prints the complete order summary. remove what we need to once we succesfully get order.cpp and order.h working with this main file.
    void completeOrder() {
        cout << "\nORDER COMPLETE\n";

        if (order.empty()) {
            cout << "No items selected.\n";
        } else {
            for (const auto& item : order) {
                cout << "- " << item << "\n";
            }
        }

        cout << fixed << setprecision(2);
        cout << "TOTAL: $" << total << "\n";
    }

    // Returns index chosen from the given options
    int askOption(const string options[], int count, const string& prompt) {
        cout << prompt << "\n";
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << options[i] << "\n";
        }
        int choice;
        do {
            cout << "Choice: ";
            cin >> choice;
        } while (choice < 1 || choice > count);
        return choice - 1;
    }

    // Processes the choice selected by the user
    void processChoice(int choice) {
        static string Sizes[] = {"Small", "Medium", "Large"};
        static string NuggetTypes[] = {"4 Piece", "8 Piece", "12 Piece"};
        static string PizzaTypes[] = {"Pepperoni", "Sausage", "Cheese", "Custom"};

        
        static string SauseTypes[] = {"Ketchup", "Mustard", "Mayo", "None"};

        
        switch (choice) {
            case 1: { // Drink (size-based price)
                int size = askOption(Sizes, 3, "Select drink size (1-3):");
                addItem("Drink", Sizes[size], drinkPrices[size]);
                break;
            }
            case 2: { // Burger (size-based price)
                int size = askOption(Sizes, 3, "Select burger size (1-3):");
                addItem("Burger", Sizes[size], burgerPrices[size]);
                break;
            }
            case 3: { // Fries (size-based price)
                int size = askOption(Sizes, 3, "Select fries size (1-3):");
                addItem("Fries", Sizes[size], friesPrices[size]);
                break;
            }
            case 4: { // Nuggets (size-based price)
                int size = askOption(NuggetTypes, 3, "Select nugget size (1-3):");
                
                int type = askOption(SauseTypes, 4, "Select a sause (1-4):");
                string desc = Sizes[size] + string(" ") + SauseTypes[type];
                
                addItem("Nuggets", NuggetTypes[size], nuggetPrices[size]);
                break;
                
            }
            case 5: { // Pizza (size-based price + type label)
                int size = askOption(Sizes, 3, "Select pizza size (1-3):");
                int type = askOption(PizzaTypes, 4, "Select pizza type (1-4):");

                string desc = Sizes[size] + string(" ") + PizzaTypes[type];
                addItem("Pizza", desc, pizzaPrices[size]);
                break;
            }
        }
    }
};

// put put total price in function. To display in the OrderDisplay class? or to order.cpp and .h file instead of this.
void totalPrice() {
  // code to be executed
}
int main() {
    cout << "MENU\n";

    // Read the menu from a file remove what we need to once we succesfully get menu.cpp and menu.h working with this main file.
    string filename = "menu.txt";
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }
    inputFile.close(); // last line of file read code

    // Create the OrderSystem object
    OrderSystem os;
    int choice = 0;

    // Main loop for taking the user's order
    while (true) {
        os.displayMenu();
        cout << "Select an option (1-6): ";
        cin >> choice;

        // Process the user's selection
        if (choice >= 1 && choice <= 5)
            os.processChoice(choice);
        else if (choice == 6) {
            os.completeOrder();
            return 0;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;

}
