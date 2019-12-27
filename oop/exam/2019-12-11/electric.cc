#include "electric.hh"

Electric::Electric()
    : Guitar(0, 0, "", 0, 0, 0), pickups(pickups), pickups_output(pickups_output) {}

Electric::Electric(unsigned int id, double price, std::string brand, unsigned int strings, unsigned int frets, double weigth, unsigned int pickups, double pickups_output)
    : Guitar(id, price, brand, strings, frets, weigth), pickups(pickups), pickups_output(pickups_output) {}

unsigned int Electric::getPickups() const {
    return pickups;
}

double Electric::getPickupsOutput() const {
    return pickups_output;
}

Electric& Electric::operator=(Electric const& other) {
    if (this == &other) {
        return *this;
    }

    (Guitar)*this = other;
    this->pickups = other.pickups;
    this->pickups_output = other.pickups_output;
}