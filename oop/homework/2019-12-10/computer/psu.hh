#ifndef PSU_HH
#define PSU_HH

#include "component.hh"

class PSU : public Component {
    unsigned int power;

public:
    PSU(double price, unsigned int power);

    double get_own_score() const;

    double get_total_score() const;
};

#endif
