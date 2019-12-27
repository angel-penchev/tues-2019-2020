#include "component.hh"

Component::Component(double price)
    : price(price) {}

float Component::get_own_price() const {
    return price;
}

float Component::get_total_price() const {
    return get_own_price();
}