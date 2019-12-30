#ifndef GAME_HH
#define GAME_HH

#include <string>
#include "media.hh"

class Game : public Media {
    unsigned int playtime;

public:
    Game(std::string title, std::string autor, double price, unsigned int playtime);

    double calcSubscription() const;
};

#endif
