#include "hdd.hh"

HDD::HDD(double price, unsigned int size, double speed)
    : Component(price), size(size), speed(speed) {}

double HDD::get_own_score() const {
    return size * speed / 100;
}

double HDD::get_total_score() const {
    return get_own_score();
}
