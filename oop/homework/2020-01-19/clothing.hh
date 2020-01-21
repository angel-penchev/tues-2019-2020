#ifndef CLOTHING_HH
#define CLOTHING_HH

#include "item.hh"

class Clothing : public Item {
    std::string color;
    char size;
    std::string material;

public:
    Clothing(
        std::string name,
        double price,
        unsigned int supply,
        Supplier supplier,
        unsigned int delivery_time,
        std::string color,
        char size,
        std::string material);
};

#endif
