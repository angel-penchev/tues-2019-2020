#include "item.hh"

Item::Item(std::string name, double price, unsigned int supply, Supplier supplier, unsigned int delivery_time)
    : name(name), price(price), supply(supply), supplier(supplier), delivery_time(delivery_time) {}

bool Item::operator<(const Item& item2) const {
    return (this->price < item2.price);
}

std::string const& Item::get_name() const {
    return this->name;
}

double const& Item::get_price() const {
    return this->price;
}

unsigned int const& Item::get_supply() const {
    return this->supply;
}

void Item::set_supply(unsigned int supply) {
    this->supply = supply;
}

Supplier const& Item::get_supplier() const {
    return this->supplier;
}

unsigned int const& Item::get_delivery_time() const {
    return this->delivery_time;
}