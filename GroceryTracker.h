#ifndef CORNER_GROCER_GROCERY_TRACKER_H_
#define CORNER_GROCER_GROCERY_TRACKER_H_

#include <string>
#include <map>

class GroceryTracker {
public:
    // Constructor automatically loads the data and creates frequency.dat
    GroceryTracker(const std::string& t_inputFileName);

    // Menu option methods
    int GetItemFrequency(const std::string& t_item) const;
    void PrintAllFrequencies() const;
    void PrintFrequencyHistogram() const;

private:
    // Core data structure
    std::map<std::string, int> m_itemFrequencies;

    // Helper methods
    void LoadFromFile(const std::string& t_fileName);
    void SaveBackupFile(const std::string& t_backupFileName) const;
};

#endif // CORNER_GROCER_GROCERY_TRACKER_H_