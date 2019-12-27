#ifndef HDD_HH
#define HDD_HH

#include "component.hh"

class HDD : public Component {
    unsigned int size;
    double speed;

public:
    HDD(double price, unsigned int size, double speed);

    double get_own_score() const;

    double get_total_score() const;
};

#endif
