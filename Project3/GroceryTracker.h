
/*checks if the header file has already been included, if not, it defines GROCERY_TRACKER_H and includes the contents of the file.
 This prevents multiple inclusions of the same header file, which can lead to compilation errors.
 */
 #ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
class GroceryTracker {
private:
 map<string, int> itemCounts;  // key = item name, value = frequency

    void loadFromFile(const std::string& filename);

public:
	// Constructor that loads data from the specified file i choose to save as grocery.txt
    GroceryTracker(const std::string& filename = "grocery.txt");

    // Option 1: Get count for one specific item
    int getFrequency(const std::string& item) const;

    // Option 2: Print list
    void printFrequencyList() const;

    // Option 3: Print histogram with asterisks
    void printHistogram() const;

	// Option 4: Exit download a file with items and frequencies 
	void saveToFile(const std::string& filename = "frequency.dat") const;
};

#endif