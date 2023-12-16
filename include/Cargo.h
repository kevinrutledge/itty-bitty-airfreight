#ifndef CARGO_H
#define CARGO_H

#include <string>
using namespace std;

// The Cargo class serves as an abstract base class for different types of cargo.
// It holds common attributes for cargo such as ULD type, abbreviation, ID, aircraft type, weight, and destination.
class Cargo {
protected:
    string uldType;         // Type of the Unit Load Device
    string abbreviation;    // Abbreviation of the cargo
    string uldId;           // Identifier of the cargo
    int aircraftType;       // Type of the aircraft intended for this cargo
    double weight;          // Weight of the cargo
    string destination;     // Destination of the cargo

public:
    Cargo();    // Default constructor initializing default values
    // Constructor with parameters to initialize a Cargo object
    Cargo(const string& uldType, const string& abbreviation, const string& uldId,
        int aircraftType, double weight, const string& destination);
    Cargo(const Cargo& other); // Copy constructor
    virtual ~Cargo(); // Virtual destructor

    // Setters for the cargo's properties
    void setUldType(const string& type);
    void setAbbreviation(const string& abrv);
    void setUldId(const string& id);
    void setAircraftType(int air);
    void setWeight(double wt);
    void setDestination(const string& dest);

    // Getters for the cargo's properties
    string getUldType() const;
    string getAbbreviation() const;
    string getUldId() const;
    int getAircraftType() const;
    double getWeight() const;
    string getDestination() const;

    // Pure virtual function to check the maximum weight limit
    // This needs to be implemented by derived classes
    virtual void checkMaxWeight(double& totalWeight, double wt) = 0;

    // Function to output the cargo details
    void output() const;
};

#endif // CARGO_H