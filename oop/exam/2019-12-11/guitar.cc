#include "guitar.hh"

Guitar::Guitar(unsigned int id, double price, std::string brand, unsigned int strings, unsigned int frets, double weigth)
    : Instrument(id, price, brand), strings(strings), frets(frets), weigth(weigth) {}

unsigned int Guitar::getStrings() const {
    return strings;
}

unsigned int Guitar::getFrets() const {
    return frets;
}

double Guitar::getWeigth() const {
    return weigth;
}