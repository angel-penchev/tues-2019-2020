#ifndef RAM_HH
#define RAM_HH

#include "component.hh"

class RAM : public Component {
    unsigned int size;
    double clock;

public:
    RAM();
    RAM(double price, unsigned int size, double clock);

    double get_own_score() const;

    double get_total_score() const;
};

#endif
