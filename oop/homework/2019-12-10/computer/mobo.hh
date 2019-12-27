#ifndef MOBO_HH
#define MOBO_HH

#include <vector>

#include "component.hh"
#include "cpu.hh"
#include "ram.hh"

class MOBO : public Component {
    CPU cpu;
    RAM ram_sticks[4];
    unsigned int ram_count;

public:
    MOBO(double price, CPU cpu, RAM ram_sticks[4], unsigned int ram_count);

    MOBO& operator=(MOBO const& other);

    double get_own_score() const;

    double get_total_score() const;
};

#endif
