#include "song.hh"

Song::Song(std::string title, std::string autor, double price, unsigned int hits)
    : Media(title, autor, price), hits(hits) {}

double Song::calcSubscription() const {
    return this->getPrice() * this->hits;
}