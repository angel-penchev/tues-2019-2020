#include "technology.hh"

Technology::Technology(
    std::string name,
    double price,
    unsigned int supply,
    Supplier supplier,
    unsigned int delivery_time,
    TechnologyType type,
    unsigned int warranty,
    unsigned int weight)
    :
    Item(name, price, supply, supplier, delivery_time),
    type(type),
    warranty(warranty),
    weight(weight) {}