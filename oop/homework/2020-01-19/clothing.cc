#include "clothing.hh"

Clothing::Clothing(
    std::string name,
    double price,
    unsigned int supply,
    Supplier supplier,
    unsigned int delivery_time,
    std::string color,
    char size,
    std::string material)
    :
    Item(name, price, supply, supplier, delivery_time),
    color(color),
    size(size),
    material(material) {}
