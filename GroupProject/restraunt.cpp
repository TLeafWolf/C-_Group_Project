#include<iostream>
#include <fstream>
#include <string> 
using namespace std;
//will add on to menu.txt for pricing of different sizes and types
int main(){
    cout << "MENU\n\n";
    // Specify the path to your text file
    std::string filename = "menu.txt"; // Replace with your file's name

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

    return 0;
}