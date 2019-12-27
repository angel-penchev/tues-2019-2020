#include "cpu.hh"

CPU::CPU(double price, unsigned int cores, double clock)
    : Component(price), cores(cores), clock(clock) {}

double CPU::get_own_score() const {
    return cores * clock;
}

double CPU::get_total_score() const {
    return get_own_score();
}
