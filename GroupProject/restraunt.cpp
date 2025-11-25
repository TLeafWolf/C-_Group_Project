#include<iostream>
#include <fstream>
#include <string> 
using namespace std;
//might adjust prices on menu.txt to be more realistic prices.
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
    // return statement don't move
    return 0;
}