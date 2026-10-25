#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class GroceryTracker {
private:
	// Stores each grocery item and its purchase frequency.
	map<string, int> itemFrequencies;

public:
	// Reads grocery items from the input file.
	void LoadData(const string& fileName);

	// Returns the frequency of a specific grocery item.
	int GetItemFrequency(const string& itemName) const;

	// Displays every grocery item and its frequency.
	void PrintFrequencies() const;

	// Displays a histogram of grocery purchase frequencies.
	void PrintHistogram() const;

	// Saves item frequencies to the backup file.
	void SaveFrequencyData(const string& fileName) const;

};

#endif
