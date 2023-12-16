#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iomanip>

// Reads input from a file and processes the cargo data
void readInput() {
    string type, abrv, id, dest;
    int air;
    double wt;
    double totwt737 = 0, totwt767 = 0; // Total weights for Boeing 737 and 767
    string datafile;
    ifstream inputFile;
    forward_list<Boeing737> list737; // List to store Boeing737 cargo
    forward_list<Boeing767> list767; // List to store Boeing767 cargo
    int unitSequence = 0; // Counter for sequence number

    // Loop to ensure valid file name is entered
    do {
        try {
            inputFile.clear();
            cout << "\nWhat's the name of your data file?\n";
            getline(cin, datafile);
            cout << "Datafile: " << datafile << endl << endl;
            inputFile.open(datafile);
            if (!inputFile)
                throw runtime_error(datafile + " Bad filename\n\n");
            cout << "File is open.\n\n";
        }
        catch (runtime_error& excpt) {
            cout << datafile << " " << excpt.what();
        }
    } while (!inputFile);

    // Reads each cargo unit and processes it
    while (inputFile >> type) {
        try {
            unitSequence++; // Increment sequence number
            inputFile >> abrv >> id >> air >> wt >> dest;
            checkUldType(type); // Check for Container or Pallet
            checkPlaneType(air); // Check for valid plane type
            checkAbbreviation(abrv, air); // Check for valid abbreviation

            // Process cargo based on aircraft type
            if (air == 737) {
                cout << "Processing unit #" << unitSequence << " for Boeing 737\n";
                load737(list737, type, abrv, id, air, wt, dest, totwt737);
            }
            else if (air == 767) {
                cout << "Processing unit #" << unitSequence << " for Boeing 767\n";
                load767(list767, type, abrv, id, air, wt, dest, totwt767);
            }
        }
        catch (runtime_error& excpt) {
            cout << excpt.what();
        }
    }

    inputFile.close();
    cout << "\nFile is closed.\n";

    // Print the cargo details and total weights for each aircraft
    printCargo(list737, list767);
    cout << "\nTotal weight for 737 load is " << totwt737 << endl;
    cout << "Total weight for 767 load is " << totwt767 << endl;
}

// Checks if the aircraft type is valid (either 737 or 767)
void checkPlaneType(int aircraftType) {
    if (aircraftType != 737 && aircraftType != 767)
        throw runtime_error(to_string(aircraftType) + " bad airplane type\n");
}

// Checks if the ULD type is valid (either Container or Pallet)
void checkUldType(const string& type) {
    if (type != "Container" && type != "Pallet")
        throw runtime_error(type + " not Container or Pallet, rejected load.\n");
}

// Checks if the abbreviation is valid for the given aircraft type
void checkAbbreviation(const string& abrv, int aircraftType) {
    // Logic for checking the abbreviation based on aircraft type
    if (aircraftType == 737) {
        if (abrv != "AYF" &&
            abrv != "AYK" &&
            abrv != "AAA" &&
            abrv != "AYY" &&
            abrv != "PAG" &&
            abrv != "PMC" &&
            abrv != "PLA")
            throw runtime_error("The " + abrv + " container is not compatible with the 737 aircraft.\n");
    }
    if (aircraftType == 767) {
        if (abrv != "AKE" &&
            abrv != "APE" &&
            abrv != "AKC" &&
            abrv != "AQP" &&
            abrv != "AQF" &&
            abrv != "AAP" &&
            abrv != "P1P" &&
            abrv != "P6P")
            throw runtime_error("The " + abrv + " container is not compatible with the 767 aircraft.\n");
    }
}

// Prints the details of all cargo in the Boeing737 and Boeing767 lists
void printCargo(const forward_list<Boeing737>& list737, const forward_list<Boeing767>& list767) {
    // Print header and cargo details for Boeing 737
    printHeader("737", "IBA0123");
    for (const auto& cargo : list737) {
        cargo.output();
    }

    // Print header and cargo details for Boeing 767
    printHeader("767", "IBA0456");
    for (const auto& cargo : list767) {
        cargo.output();
    }
}

// Prints the header for cargo details output
void printHeader(const string& aircraftType, const string& aircraftId) {
    cout << "\nLoad out of " << aircraftType << " aircraft " << aircraftId << endl;
    cout << left;
    cout << setw(20) << "Pallet/Container";
    cout << setw(16) << "Aircraft Type";
    cout << setw(16) << "Identifier";
    cout << setw(20) << "Weight (pounds)";
    cout << setw(16) << "Destination";
    cout << endl;
}