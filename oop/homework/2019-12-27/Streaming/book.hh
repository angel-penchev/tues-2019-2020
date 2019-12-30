#ifndef BOOK_HH
#define BOOK_HH

#include <string>
#include "media.hh"

class Book : public Media {

public:
    Book(std::string title, std::string autor, double price);

    double calcSubscription() const;
};

#endif
