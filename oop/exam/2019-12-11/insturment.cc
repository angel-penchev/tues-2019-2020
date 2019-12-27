#include "instrument.hh"

Instrument::Instrument(unsigned int id, double price, std::string brand)
    : id(id), price(price), brand(brand) {}

unsigned int Instrument::getId() const {
    return id;
}

double Instrument::getPrice() const {
    return price;
}

std::string Instrument::getBrand() const {
    return brand;
}