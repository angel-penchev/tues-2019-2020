#include "movie.hh"

Movie::Movie(std::string title, std::string autor, double price, unsigned int length,  unsigned int watch_time)
    : Media(title, autor, price), length(length), watch_time(watch_time) {}

double Movie::calcSubscription() const {
    return this->getPrice() * this->watch_time;
}