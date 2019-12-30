#include "media.hh"

Media::Media(std::string title, std::string autor, double price)
    : title(title), autor(autor), price(price) {}

std::string Media::getTitle() const {
    return this->title;
}

std::string Media::getAutor() const {
    return this->autor;
}

double Media::getPrice() const {
    return this->price;
}