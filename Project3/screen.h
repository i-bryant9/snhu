#ifndef SCREEN_H
#define SCREEN_H
//header files
#include <iostream>
#include <string>
#include <limits>
#include "GroceryTracker.h"   
//functions of menu
void clearScreen();
int displayMenuAndGetChoice();
//menu option functions
void frequencyLookup(const GroceryTracker& tracker);
void printList(const GroceryTracker& tracker);       
void printHistogram(const GroceryTracker& tracker);  
void endProgram(const GroceryTracker& tracker);
#endif