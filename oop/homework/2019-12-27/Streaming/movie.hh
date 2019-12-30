#ifndef MOVIE_HH
#define MOVIE_HH

#include <string>
#include "media.hh"

class Movie : public Media {
    unsigned int length;
    unsigned int watch_time;

public:
    Movie(std::string title, std::string autor, double price, unsigned int length,  unsigned int watch_time);

    double calcSubscription() const;
};

#endif
