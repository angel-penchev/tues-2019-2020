#ifndef CASE_HH
#define CASE_HH

#include <vector>

#include "component.hh"
#include "mobo.hh"
#include "psu.hh"
#include "hdd.hh"

class Case : public Component {
    MOBO mobo;
    PSU psu;
    HDD hdds[4];
    unsigned int hdd_count;

public:
    Case(double price, MOBO mobo, PSU psu, HDD hdds[4], unsigned int hdd_count);

    Case& operator=(Case const& other);

    double get_own_score() const;

    double get_total_score() const;
};

#endif
