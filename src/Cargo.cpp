#include <iostream>
#include <iomanip>
#include "Cargo.h"

// Default constructor for Cargo class
// Initializes Cargo object with default values
Cargo::Cargo() : uldType("XXX"), abbreviation(" "), uldId("xxxxxIB"),
aircraftType(700), weight(0.0), destination("NONE") {}

// Constructor with parameters for the Cargo class
// Initializes Cargo object with specific values for its properties
Cargo::Cargo(const string& uldType, const string& abbreviation, const string& uldId,
    int aircraftType, double weight, const string& destination)
    : uldType(uldType), abbreviation(abbreviation), uldId(uldId),
    aircraftType(aircraftType), weight(weight), destination(destination) {}

// Copy constructor for the Cargo class
// Initializes a new Cargo object as a copy of an existing object
Cargo::Cargo(const Cargo& other) : uldType(other.uldType), abbreviation(other.abbreviation),
uldId(other.uldId), aircraftType(other.aircraftType),
weight(other.weight), destination(other.destination) {}

// Destructor implementation for Cargo class
Cargo::~Cargo() {}

// Setters for Cargo properties
void Cargo::setUldType(const string& type) { uldType = type; }
void Cargo::setAbbreviation(const string& abrv) { abbreviation = abrv; }
void Cargo::setUldId(const string& id) { uldId = id; }
void Cargo::setAircraftType(int air) { aircraftType = air; }
void Cargo::setWeight(double wt) { weight = wt; }
void Cargo::setDestination(const string& dest) { destination = dest; }

// Getters for Cargo properties
string Cargo::getUldType() const { return uldType; }
string Cargo::getAbbreviation() const { return abbreviation; }
string Cargo::getUldId() const { return uldId; }
int Cargo::getAircraftType() const { return aircraftType; }
double Cargo::getWeight() const { return weight; }
string Cargo::getDestination() const { return destination; }

// Output function for displaying Cargo details
// Prints the Cargo's details in a formatted manner
void Cargo::output() const {
    cout << left;
    cout << setw(20) << uldType;
    cout << setw(16) << aircraftType;
    cout << setw(16) << uldId;
    cout << setw(20) << weight;
    cout << setw(16) << destination;
    cout << endl;
}