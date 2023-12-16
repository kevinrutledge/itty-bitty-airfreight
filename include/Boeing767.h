#ifndef BOEING767_H
#define BOEING767_H

#include <forward_list>
#include "Cargo.h"

// Boeing767 class, derived from Cargo, to represent cargo specifically for Boeing 767 aircraft
class Boeing767 : public Cargo {
private:
    int total767Wt; // Total weight of the cargo currently loaded on the Boeing 767

public:
    // Constructor for Boeing767 class
    // Initializes a cargo unit for Boeing 767 with given ULD type, abbreviation, ID, aircraft type, weight, and destination
    Boeing767(const string& uldType, const string& abbreviation, const string& uldId,
        int aircraftType, double weight, const string& destination);

    // Overridden method to check if the total weight including the new cargo exceeds the maximum weight limit for Boeing 767
    // Throws an exception if the new weight exceeds the limit
    void checkMaxWeight(double& totalWt767, double wt) override;
};

// Function to load cargo onto a Boeing 767 aircraft
// Takes a list of Boeing 767 cargos, cargo details, and the total weight limit, then attempts to add the new cargo
void load767(forward_list<Boeing767>& list767, const string& type, const string& abrv,
    const string& id, int craft, double wt, const string& dest, double& totwt767);

#endif // BOEING767_H