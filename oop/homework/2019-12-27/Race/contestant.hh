#ifndef CONTESTANT_HH
#define CONTESTANT_HH

#include <string>
#include <vector>
#include <array>
#include <iostream>

class Contestant {
    std::string name;
    std::array<long int, 2> position;
    unsigned int speed;

public:
    class ErrorCarOutOfBounds {};

    class ErrorInvalidMoveIndex {};

    class ErrorMoveIsImpossibleToPerform {};

    class FinishedTheRace {};

    Contestant(std::string name, unsigned int speed);

    std::string getName() const;

    std::array<long int, 2> getPosition() const;

    void setPosition(std::array<long int, 2> position);

    unsigned int getSpeed() const;
    
    void moveForward(std::vector<std::vector<Contestant*> > *track, unsigned int move);
};

#endif
