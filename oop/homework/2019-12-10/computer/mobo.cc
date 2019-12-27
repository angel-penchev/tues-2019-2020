#include "mobo.hh"

MOBO::MOBO(double price, CPU cpu, RAM ram_sticks[4], unsigned int ram_count)
    : Component(price), cpu(cpu), ram_count(ram_count) {
        for (int i = 0; i < ram_count; i++) {
            this->ram_sticks[i] = ram_sticks[i];
        }
    }

MOBO& MOBO::operator=(MOBO const& other) {
    if (this == &other) {
        return *this;
    }

    (Component)*this = other;
    cpu = other.cpu;
    ram_count = other.ram_count;
    for (int i = 0; i < other.ram_count; ++i) {
        ram_sticks[i] = other.ram_sticks[i];
    }
}

double MOBO::get_own_score() const {
    return 0;
}

double MOBO::get_total_score() const {
    return get_own_score();
}
