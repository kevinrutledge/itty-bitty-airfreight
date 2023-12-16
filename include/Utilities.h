#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <forward_list>
#include "Boeing737.h"
#include "Boeing767.h"

using namespace std;

// Global constants defining the maximum load capacity for Boeing 737 and 767 aircrafts
const int MAXLOAD737 = 46000; // Maximum load for Boeing 737 in pounds
const int MAXLOAD767 = 116000; // Maximum load for Boeing 767 in pounds

// Function to read cargo data input from a file and process it
void readInput();

// Function to check if the specified aircraft type is valid (either 737 or 767)
void checkPlaneType(int aircraftType);

// Function to validate the ULD (Unit Load Device) type, ensuring it's either a Container or a Pallet
void checkUldType(const string& type);

// Function to check if the abbreviation is appropriate for the specified aircraft type
void checkAbbreviation(const string& abrv, int aircraftType);

// Function to print the header for cargo output, indicating the aircraft type and ID
void printHeader(const string& aircraftType, const string& aircraftId);

// Function to print detailed cargo information for Boeing737 and Boeing767 aircrafts
// The function lists all cargo items along with their details for each aircraft type
void printCargo(const forward_list<Boeing737>& boeing737s, const forward_list<Boeing767>& boeing767s);

#endif // UTILITIES_H
