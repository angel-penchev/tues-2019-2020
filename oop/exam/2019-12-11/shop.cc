#include "shop.hh"

Shop::Shop(std::vector<Acoustic> acoustic, std::vector<Electric> electric)
    : acoustic(acoustic), electric(electric) {};

std::vector<Guitar> Shop::get_all_in_price_range(double from_price, double to_price) const {
    std::vector<Guitar> result;
    for (int i = 0; i < acoustic.size(); i++) {
        if (acoustic[i].getPrice() > from_price && acoustic[i].getPrice() > to_price) {
            result.push_back(acoustic[i]);
        }
    }
    return result;
}

std::vector<Acoustic> Shop::get_all_twelve_strings() const {
    std::vector<Acoustic> result;
    for (int i = 0; i < acoustic.size(); i++) {
        if (acoustic[i].getStrings() == 12) {
            result.push_back(acoustic[i]);
        }
    }
    return result;
}

Acoustic const& Shop::get_most_powerful_acoustic() {
    Acoustic result;
    if (acoustic.size() == 0) {
        throw ErrorNoneFound();
    }
    for (int i = 0; i < acoustic.size(); i++) {
        if (acoustic[i].getOutput() > result.getOutput() || result.getId() == 0) { //TODO
            result = acoustic[i];
        }
    }
    return result;
}

Electric const& Shop::get_most_powerful_electric() {
    Electric result;
    for (int i = 0; i < electric.size(); i++) {
        if (electric[i].getPickupsOutput() > result.getPickupsOutput() || result.getId() == 0) {
            result = electric[i];
        }
    }
    return result;
}

void Shop::add_accoustic(Acoustic const& acoustic) {
    this->acoustic.push_back(acoustic);
}

void Shop::add_electric(Electric const& electric) {
    this->electric.push_back(electric);
}

void Shop::buy(Guitar const& guitar) {
    for (int i = 0; i < acoustic.size(); i++) {
        if (guitar.getId() == acoustic[i].getId()) {
            acoustic.erase(acoustic.begin() + i);
            return;
        }
    }
    
    for (int i = 0; i < electric.size(); i++) {
        if (guitar.getId() == electric[i].getId()) {
            electric.erase(electric.begin() + i);
            return;
        }
    }
}