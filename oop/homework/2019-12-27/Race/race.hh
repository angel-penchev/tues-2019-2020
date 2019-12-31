#ifndef RACE_HH
#define RACE_HH

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include "contestant.hh"

class Race {
    std::vector<std::vector<Contestant*>> track;
    unsigned int track_length;

public:
    class ErrorContestantAlreadyExsists {};

    Race(unsigned int track_length);

    void addContestant(Contestant* contestant);

    void startRace();

    void scaleRaceTrack();

    bool isTheRaceLive(std::vector<Contestant> winners, unsigned int amount_to_finish);

    std::string trackToStr();

    std::string movesToStr();

    std::string winnersToStr(std::vector<Contestant> winners);
};

#endif
