#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

int main() {
    // Create the grocery tracker.
    GroceryTracker tracker;

    // Load grocery items from the input file.
    tracker.LoadData("CS210_Project_Three_Input_File.txt");

    // Create the backup file when the program starts.
    tracker.SaveFrequencyData("frequency.dat");

    int menuChoice = 0;
    string itemName;

    // Display the menu until the user chooses to exit.
    while (menuChoice != 4) {
        cout << "\n===== Corner Grocer =====" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Display item frequencies" << endl;
        cout << "3. Display item histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        // Validate that the user enters a number.
        if (!(cin >> menuChoice)) {
            cout << "Invalid input. Please enter a number from 1 to 4." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (menuChoice) {
        case 1:
            cout << "Enter the grocery item to search for: ";
            cin >> itemName;

            cout << itemName << " was purchased "
                << tracker.GetItemFrequency(itemName)
                << " time(s)." << endl;
            break;

        case 2:
            tracker.PrintFrequencies();
            break;

        case 3:
            tracker.PrintHistogram();
            break;

        case 4:
            cout << "Thank you for using Corner Grocer!" << endl;
            break;

        default:
            cout << "Invalid choice. Please select an option from 1 to 4."
                << endl;
            break;
        }
    }

    return 0;

}
