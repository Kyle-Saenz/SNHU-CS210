
 // main.cpp
 // Kyle Saenz
 // June 19, 2026
 

#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include "GroceryTracker.h"

  // Helper function to keep main() uncluttered.
  // Displays the user interface menu options.
void DisplayMenu() {
    std::cout << "\n=====================================" << std::endl;
    std::cout << "       Corner Grocer Main Menu       " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "1. Look up individual item frequency" << std::endl;
    std::cout << "2. Print all unique item frequencies" << std::endl;
    std::cout << "3. Print graphical item histogram" << std::endl;
    std::cout << "4. Exit Program" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Enter selection (1-4): ";
}

int main() {
    // Instantiate tracker object. 
    // This instantly runs the constructor to load file data and back it up.
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt");

    int menuSelection = 0;
    bool keepRunning = true;

    // Core interactive application loop
    while (keepRunning) {
        try {
            DisplayMenu();

            // Validate that the input is a valid integer type
            if (!(std::cin >> menuSelection)) {
                std::cin.clear(); // Reset the stream fail state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Purge corrupt characters
                throw std::runtime_error("Invalid input type. Please enter a valid number.");
            }

            // Validate that the integer falls into the acceptable menu bounds
            if (menuSelection < 1 || menuSelection > 4) {
                throw std::out_of_range("Selection out of bounds. Please choose option 1, 2, 3, or 4.");
            }

            // Execute clean routing if validation passes
            switch (menuSelection) {
            case 1: {
                std::string searchItem;
                std::cout << "Enter the item name to look up: ";
                std::cin >> searchItem;

                int frequency = tracker.GetItemFrequency(searchItem);
                std::cout << "\nFrequency of \"" << searchItem << "\": " << frequency << std::endl;
                break;
            }
            case 2:
                tracker.PrintAllFrequencies();
                break;
            case 3:
                tracker.PrintFrequencyHistogram();
                break;
            case 4:
                std::cout << "\nExiting the Corner Grocer system. Data backed up to frequency.dat. Goodbye!" << std::endl;
                keepRunning = false;
                break;
            }

        }
        catch (const std::exception& t_error) {
            // Catches runtime_error or out_of_range and forces a loop reprint
            std::cout << "\n>>> " << t_error.what() << " <<<\n" << std::endl;
        }
    }

    return 0;
}