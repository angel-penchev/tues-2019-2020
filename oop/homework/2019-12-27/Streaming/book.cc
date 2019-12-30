#include "book.hh"

Book::Book(std::string title, std::string autor, double price)
    : Media(title, autor, price) {}

double Book::calcSubscription() const {
    return this->getPrice();
}