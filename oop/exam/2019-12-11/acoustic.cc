#include "acoustic.hh"

Acoustic::Acoustic()
    : Guitar(0, 0, "", 0, 0, 0), output(0) {}

Acoustic::Acoustic(unsigned int id, double price, std::string brand, unsigned int strings, unsigned int frets, double weigth, double output)
    : Guitar(id, price, brand, strings, frets, weigth), output(output) {}

double Acoustic::getOutput() const {
    return output;
}

Acoustic& Acoustic::operator=(Acoustic const& other) {
    if (this == &other) {
        return *this;
    }

    (Guitar)*this = other;
    this->output = other.output;
}