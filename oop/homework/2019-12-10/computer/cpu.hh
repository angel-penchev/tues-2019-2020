#ifndef CPU_HH
#define CPU_HH

#include "component.hh"

class CPU : public Component {
    unsigned int cores;
    double clock;

public:
    CPU(double price, unsigned int cores, double clock);

    double get_own_score() const;

    double get_total_score() const;
};

#endif
