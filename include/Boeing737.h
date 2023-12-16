#ifndef BOEING737_H
#define BOEING737_H

#include <forward_list>
#include "Cargo.h"

// Boeing737 class, derived from Cargo, to represent cargo specifically for Boeing 737 aircraft
class Boeing737 : public Cargo {
private:
    int total737Wt; // Total weight of the cargo currently loaded on the Boeing 737

public:
    // Constructor for Boeing737 class
    // Initializes a cargo unit for Boeing 737 with given ULD type, abbreviation, ID, aircraft type, weight, and destination
    Boeing737(const string& uldType, const string& abbreviation, const string& uldId,
        int aircraftType, double weight, const string& destination);

    // Overridden method to check if the total weight including the new cargo exceeds the maximum weight limit for Boeing 737
    // Throws an exception if the new weight exceeds the limit
    void checkMaxWeight(double& totalWt737, double wt) override;
};

// Function to load cargo onto a Boeing 737 aircraft
// Takes a list of Boeing 737 cargos, cargo details, and the total weight limit, then attempts to add the new cargo
void load737(forward_list<Boeing737>& list737, const string& type, const string& abrv,
    const string& id, int craft, double wt, const string& dest, double& totwt737);

#endif // BOEING737_H
