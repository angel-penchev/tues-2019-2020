#include "ram.hh"

RAM::RAM(): Component(0), size(0), clock(0) {}

RAM::RAM(double price, unsigned int size, double clock)
    : Component(price), size(size), clock(clock) {}

double RAM::get_own_score() const {
    return size * clock;
}

double RAM::get_total_score() const {
    return get_own_score();
}