#ifndef TECHNOLOGY_HH
#define TECHNOLOGY_HH

#include "item.hh"

enum class TechnologyType { WhiteElectronics, BlackElectronics, Consumable };

class Technology : public Item {
    TechnologyType type;
    unsigned int warranty;
    unsigned int weight;

public:
    Technology(
        std::string name,
        double price,
        unsigned int supply,
        Supplier supplier,
        unsigned int delivery_time,
        TechnologyType type,
        unsigned int warranty,
        unsigned int weight);
};

#endif
