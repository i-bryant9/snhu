/*
Isaiah Bryant
2/27/2026
DR. M
CS 210
*/

//header files
#include "screen.h"
#include "GroceryTracker.h"
#include <iostream>
//standard namespace
using namespace std;
//  main function
int main() {
	// Create GroceryTracker instance (loads data from file)
    GroceryTracker tracker;
	// Main menu loop
    bool running = true;
	// Loop until user chooses to exit
    while (running) {
        int option = displayMenuAndGetChoice();
		//switch statement to determine which menu option was selected
        switch (option) {
			//frequency lookup
        case 1:
            frequencyLookup(tracker);
            break;
			//print frequency list
        case 2:
            printList(tracker);
            break;
			//print histogram
        case 3:
            printHistogram(tracker);
            break;
			//exit program
        case 4:
            endProgram(tracker);
            running = false;
            break;
        }
    }

    return 0;
}