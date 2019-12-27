#include "case.hh"

Case::Case(double price, MOBO mobo, PSU psu, HDD hdds[4], unsigned int hdd_count)
    : Component(price), mobo(mobo), psu(psu), hdd_count(hdd_count) {
        for (int i = 0; i < hdd_count; i++) {
            this->hdds[i] = hdds[i];
        }   
    }

Case& Case::operator=(Case const& other) {
    if (this == &other) {
        return *this;
    }

    (Component) *this = other;
    this->mobo = other.mobo;
    this->psu = other.psu;
    this->hdd_count = other.hdd_count;
    for (int i = 0; i < hdd_count; i++) {
        this->hdds[i] = hdds[i];
    }  
}

double Case::get_own_score() const {
    return 0;
}

double Case::get_total_score() const {
    return get_own_score();
}
