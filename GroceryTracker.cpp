#include "GroceryTracker.h"

// Reads the input file and counts each grocery item.
void GroceryTracker::LoadData(const string& fileName) {
    ifstream inputFile(fileName);
    string itemName;

    // Check whether the input file opened successfully.
    if (!inputFile.is_open()) {
        cout << "Error: Could not open " << fileName << "." << endl;
        return;
    }

    // Read one grocery item at a time until the file ends.
    while (inputFile >> itemName) {
        itemFrequencies[itemName]++;
    }

    inputFile.close();

}

// Returns the frequency of a specific grocery item.
int GroceryTracker::GetItemFrequency(const string& itemName) const {
    auto item = itemFrequencies.find(itemName);

    // Return zero if the item is not in the map.
    if (item == itemFrequencies.end()) {
        return 0;
    }

    return item->second;

}

// Displays all grocery items and their frequencies.
void GroceryTracker::PrintFrequencies() const {
    cout << "\nGrocery Item Frequencies" << endl;
    cout << "------------------------" << endl;

    for (const auto& item : itemFrequencies) {
        cout << item.first << " " << item.second << endl;
    }

}

// Displays a histogram of grocery purchase frequencies.
void GroceryTracker::PrintHistogram() const {
    cout << "\nGrocery Purchase Histogram" << endl;
    cout << "--------------------------" << endl;

    for (const auto& item : itemFrequencies) {
        cout << item.first << " ";

        // Print one asterisk for each purchase.
        for (int count = 0; count < item.second; count++) {
            cout << "*";
        }

        cout << endl;
    }

}

// Saves all grocery item frequencies to a backup file.
void GroceryTracker::SaveFrequencyData(const string& fileName) const {
    ofstream outputFile(fileName);

    // Check whether the backup file opened successfully.
    if (!outputFile.is_open()) {
        cout << "Error: Could not create " << fileName << "." << endl;
        return;
    }

    // Write each grocery item and its frequency to the file.
    for (const auto& item : itemFrequencies) {
        outputFile << item.first << " " << item.second << endl;
    }

    outputFile.close();

}