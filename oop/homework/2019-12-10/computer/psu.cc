#include "psu.hh"

PSU::PSU(double price, unsigned int power)
    : Component(price), power(power) {}

double PSU::get_own_score() const {
    return power / 100;
}

double PSU::get_total_score() const {
    return get_total_score();
}