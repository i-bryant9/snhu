#include "GroceryTracker.h"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

GroceryTracker::GroceryTracker(const string& filename) {
    loadFromFile(filename);
}
// Reads items from the specified file and counts their frequencies
void GroceryTracker::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error: Could not open '" << filename << "'" << endl;
        return;
    }
	// Read each line (item) and count frequencies
    string item;
    while (getline(inFile, item)) {
        if (!item.empty()) {              // skip blank lines
            itemCounts[item]++;           // auto-creates 0 if new, then ++
        }
    }
	// Close the file after reading
    inFile.close();
}
// Returns the frequency of the specified item, or 0 if not found
int GroceryTracker::getFrequency(const string& item) const {
    auto isItem = item;
    // Capitalize first letter for lookup
	isItem[0] = toupper(isItem[0]); 
    auto it = itemCounts.find(isItem);
	// If item is not found return 0
    return (it != itemCounts.end()) ? it->second : 0;
}
// Prints a formatted list of items and their frequencies
void GroceryTracker::printFrequencyList() const {
	//print the frequency list header
    cout << endl <<"            FREQUENCY LIST"<< endl;
    cout << string(40, '-') << endl;
    cout << left << setw(25) << "Item" << "Count" << endl;
    cout << string(40, '-') << endl;

	// Loop through the map and print each item and its count
    for (const auto& pair : itemCounts) {
        cout << left << setw(25) << pair.first 
             << pair.second << endl;
    }
    cout << endl;
}
// Prints a histogram of items using asterisks to represent frequency

void GroceryTracker::printHistogram() const {
	//print the histogram header
    cout << endl <<"            ITEM HISTOGRAM" << endl;
    cout << string(50, '-') << endl;
	// Loop through the map and print each item followed by a number of asterisks equal to its count
    for (const auto& pair : itemCounts) {
        cout << left << setw(22) << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

// Saves the item frequencies to a file in a simple text format

void GroceryTracker::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error: Could not open '" << filename << "' for writing" << endl;
        return;
    }
    // Write each item and its frequency to the file
    for (const auto& pair : itemCounts) {
        outFile << pair.first << ": " << pair.second << endl;
    }
    // Close the file after writing
    outFile.close();
}