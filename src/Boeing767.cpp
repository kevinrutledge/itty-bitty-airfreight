#include <stdexcept>
#include "Boeing767.h"
#include "Utilities.h"

// Constructor for Boeing767 class
// Initializes base Cargo class with provided values and sets total weight to 0
Boeing767::Boeing767(const string& uldType, const string& abbreviation, const string& uldId,
    int aircraftType, double weight, const string& destination)
    : Cargo(uldType, abbreviation, uldId, aircraftType, weight, destination), total767Wt(0) {}

// Overridden method to check maximum weight specific to Boeing767
// Ensures that the total weight does not exceed the maximum allowed for Boeing767
void Boeing767::checkMaxWeight(double& totalWt767, double wt) {
    // If adding new weight exceeds maximum load, throw an exception
    if (totalWt767 + wt > MAXLOAD767) {
        throw runtime_error("Unit " + getUldType() + " not added due to weight restrictions for 767.\n");
    }
    else {
        // Update the total weight for the Boeing767
        totalWt767 += wt;
    }
}

// Function to load a Boeing767 cargo unit
// Creates a Boeing767 object and attempts to add it to the list of cargos
void load767(forward_list<Boeing767>& list767, const string& type, const string& abrv,
    const string& id, int craft, double wt, const string& dest, double& totwt767) {
    // Create a Boeing767 cargo unit object
    Boeing767 unitobj767(type, abrv, id, craft, wt, dest);

    // Check if the cargo unit can be added without exceeding the weight limit
    unitobj767.checkMaxWeight(totwt767, wt);

    // If the cargo unit is within the weight limit, add it to the front of the list
    list767.push_front(unitobj767);
}