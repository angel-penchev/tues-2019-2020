#ifndef ITEM_HH
#define ITEM_HH

#include <string>
#include "supplier.hh"

class Item {
    std::string name;
    double price;
    unsigned int supply;
    Supplier supplier;
    unsigned int delivery_time;

public:
    Item(std::string name, double price, unsigned int supply, Supplier supplier, unsigned int delivery_time);

    bool operator<(const Item& item2) const;

    std::string const& get_name() const;

    double const& get_price() const;

    unsigned int const&  get_supply() const;

    Supplier const& get_supplier() const;

    unsigned int const&  get_delivery_time() const;
};

#endif
