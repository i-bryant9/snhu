//header files
#include "screen.h"
#include <cstdlib>
#include <limits>

using namespace std;
// Clears the console screen 
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
// Displays the menu and gets a valid user choice (1-4)
int displayMenuAndGetChoice() {
    int choice;
    clearScreen();

    cout << string(16, '-') << " Corner Grocer " << string(16, '-') << endl << endl;
    cout << "Please input a number to select a menu option:" << endl << endl;
    cout << "   1: Return an input item's frequency" << endl;
    cout << "   2: Print frequency list" << endl;
    cout << "   3: Print histogram" << endl;
    cout << "   4: Exit" << endl << endl;
    cout << string(47, '-') << endl;

    cout << "   Enter number to match menu option: ";
    //choice input validation
    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cout << "Invalid input. Please enter 1 - 4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return choice;
}
//prompts for input and calls get frequency function
void frequencyLookup(const GroceryTracker& tracker) {
    clearScreen();
    cout << "Item Frequency Lookup" << endl <<endl;
    cout << "Enter item name: ";

    string item;
    getline(cin, item);
    // Capitalize first letter to include any lower case inputs
	item[0] = toupper(item[0]); 
    //sets count to items frequency return
    int count = tracker.getFrequency(item);
    // if there were any prints amount 
    if (count > 0) {
        cout << endl << item << ": " << count << endl;
    }

    // if none tells user there werent any.
    else {
        cout << endl<< '\'' << item << "' was not found." << endl;
    }

    cout << endl << "|Press Enter to return to menu|";
    cin.get();
}
//prints list of items and frequencies, then prompts user to return to menu
void printList(const GroceryTracker& tracker) {
    clearScreen();
    tracker.printFrequencyList();
    cout <<endl << "|Press Enter to return|";
    cin.get();
}
//prints histogram of items and frequencies, then prompts user to return to menu
void printHistogram(const GroceryTracker& tracker) {
    clearScreen();
    tracker.printHistogram();
    cout << endl << "| Press Enter to return | ";
    cin.get();
}
//prints exit message and prompts user to press enter to close program
void endProgram(const GroceryTracker& tracker) {
    clearScreen();
    tracker.saveToFile(); // Save frequencies to file before exiting
    clearScreen();
    cout << "**********Goodbye.**********" << endl << endl;
}