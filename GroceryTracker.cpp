// GroceryTracker.cpp
// Kyle Saenz
// June 19, 2026


#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

  //Constructor: Initializes the object by reading the input file and automatically back up the data.
  
GroceryTracker::GroceryTracker(const std::string& t_inputFileName) {
    // Populate the map from the primary text file
    LoadFromFile(t_inputFileName);

    // Automatically create the required backup file on start
    SaveBackupFile("frequency.dat");
}

 // Read a text file line-by-line and counts item occurrences.
void GroceryTracker::LoadFromFile(const std::string& t_fileName) {
    std::ifstream inputFile(t_fileName);
    std::string item;

    // Check if the file opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file: " << t_fileName << std::endl;
        return;
    }

    // Read line-by-line, automatically adjusting frequency counts
    while (std::getline(inputFile, item)) {

        // Skip empty lines
        if (item.empty()) {
            continue;
        }

        m_itemFrequencies[item]++;
    }

    inputFile.close();
}

// Write the map data out to a backup file.

void GroceryTracker::SaveBackupFile(const std::string& t_backupFileName) const {
    std::ofstream outputFile(t_backupFileName);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to create backup file: " << t_backupFileName << std::endl;
        return;
    }

    // Loop through the map and write pairs to the backup file
    for (const auto& pair : m_itemFrequencies) {
        outputFile << pair.first << " " << pair.second << std::endl;
    }

    outputFile.close();
}

 // Menu Option 1: Looks up and returns the frequency of a single specific item.
int GroceryTracker::GetItemFrequency(const std::string& t_item) const {
    auto it = m_itemFrequencies.find(t_item);

    if (it != m_itemFrequencies.end()) {
        return it->second; // Item found, return actual count
    }

    return 0; // Item not found in the dataset
}

 // Menu Option 2: Prints all unique items and their respective counts.
void GroceryTracker::PrintAllFrequencies() const {
    std::cout << "\n--- Item Frequencies ---" << std::endl;
    for (const auto& pair : m_itemFrequencies) {
        std::cout << std::left << std::setw(15) << pair.first
            << " " << pair.second << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}

// Menu Option 3: Prints an alphabetical list represented as a character histogram.
void GroceryTracker::PrintFrequencyHistogram() const {
    std::cout << "\n--- Item Histogram ---" << std::endl;
    for (const auto& pair : m_itemFrequencies) {
        std::cout << std::left << std::setw(15) << pair.first << " ";

        // Print an asterisk for each count recorded
        for (int i = 0; i < pair.second; ++i) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------" << std::endl;
}