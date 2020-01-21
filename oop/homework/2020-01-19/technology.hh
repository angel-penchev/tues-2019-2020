#ifndef TECHNOLOGY_HH
#define TECHNOLOGY_HH

// #include <map>
#include "item.hh"

class Technology : public Item {
    std::string type;
    unsigned int warranty;
    unsigned int weight;

public:
    Technology(
        std::string name,
        double price,
        unsigned int supply,
        Supplier supplier,
        unsigned int delivery_time,
        std::string type,
        unsigned int warranty,
        unsigned int weight);
};

#endif
