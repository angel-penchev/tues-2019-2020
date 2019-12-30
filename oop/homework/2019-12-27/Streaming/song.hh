#ifndef SONG_HH
#define SONG_HH

#include <string>
#include "media.hh"

class Song : public Media {
    unsigned int hits;

public:
    Song(std::string title, std::string autor, double price, unsigned int hits);

    double calcSubscription() const;
};

#endif
