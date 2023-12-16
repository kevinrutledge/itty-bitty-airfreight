#include <stdexcept>
#include "Boeing737.h"
#include "Utilities.h"

// Constructor for Boeing737 class
// Initializes base Cargo class with provided values and sets total weight for 737 to 0
Boeing737::Boeing737(const string& uldType, const string& abbreviation, const string& uldId,
    int aircraftType, double weight, const string& destination)
    : Cargo(uldType, abbreviation, uldId, aircraftType, weight, destination), total737Wt(0) {}

// Overridden method to check maximum weight specific to Boeing737
// Ensures that the total weight does not exceed the maximum allowed for Boeing737
void Boeing737::checkMaxWeight(double& totalWt737, double wt) {
    // If adding new weight exceeds maximum load, throw an exception
    if (totalWt737 + wt > MAXLOAD737) {
        throw runtime_error("Unit " + getUldType() + " not added due to weight restrictions for 737.\n");
    }
    else {
        // Update the total weight for the Boeing737
        totalWt737 += wt;
    }
}

// Function to load a Boeing737 cargo unit
// Creates a Boeing737 object and attempts to add it to the list of cargos
void load737(forward_list<Boeing737>& list737, const string& type, const string& abrv,
    const string& id, int craft, double wt, const string& dest, double& totwt737) {
    // Create a Boeing737 cargo unit object
    Boeing737 unitobj737(type, abrv, id, craft, wt, dest);

    // Check if the cargo unit can be added without exceeding the weight limit
    unitobj737.checkMaxWeight(totwt737, wt);

    // If the cargo unit is within the weight limit, add it to the front of the list
    list737.push_front(unitobj737);
}