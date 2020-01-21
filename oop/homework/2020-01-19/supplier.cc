#include "supplier.hh"

Supplier::Supplier(std::string name)
    : name(name) {}

std::string const& Supplier::get_name() const {
    return this->name;
}