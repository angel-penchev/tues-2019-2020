#include "race.hh"

Race::Race(unsigned int track_length)
    : track_length(track_length) {}

void Race::addContestant(Contestant* contestant) {
    for (unsigned int i = 0; i < this->track.size(); i++) {
        if (this->track[i][0]->getName() == contestant->getName()) {
            throw ErrorContestantAlreadyExsists();
        }
    }
    
    contestant->setPosition({int(this->track.size()), 0});
    this->track.push_back({contestant});
}

void Race::startRace() {
    // Scaling the race tracks to the given length
    Race::scaleRaceTrack();

    // Printing the race track and available moves
    std::cout << Race::trackToStr();
    std::cout << Race::movesToStr();

    // Defining a map to keep track of who has not played thier turn
    std::map<std::string, bool> player_turns_map;
    for (unsigned int i = 0; i < this->track.size(); i++) {
        player_turns_map.insert(std::pair<std::string, bool>(this->track[i][0]->getName(), true));
    }

    std::vector<Contestant> winners;

    for (int iter = 0; Race::isTheRaceLive(winners, 3); iter++) {
        std::cout << '\n' << "Iteration " << iter << '\n';

        // Reseting all the player turns
        for (std::map<std::string, bool>::iterator it = player_turns_map.begin(); it != player_turns_map.end(); it++) {
            it->second = true;
        }

        // Goes through the whole the track and if it finds a car, aptempts to move it forward
        for (unsigned int i = 0; i < this->track.size(); i++) {
            for (unsigned int j = 0; j < this->track_length; j++) {
                if (track[i][j] != NULL && player_turns_map[track[i][j]->getName()]) {
                    int move;
                    std::cout << track[i][j]->getName()
                    << " ("
                    << track[i][j]->getPosition()[0]
                    << ", "
                    << track[i][j]->getPosition()[1]
                    << ")"
                    << "\'s turn! What\'s your move: ";

                    for(;;) {
                        try {
                            std::cin >> move;
                            player_turns_map[track[i][j]->getName()] = false;
                            track[i][j]->moveForward(&this->track, move);
                            track[i][j] = NULL;
                            break;
                        } catch (Contestant::FinishedTheRace) {
                            std::cout << "Player " << track[i][j]->getName() << " has finished the race!\n";
                            winners.push_back((*track[i][j]));
                            track[i][j] = NULL;
                            break;
                        } catch (Contestant::ErrorInvalidMoveIndex) {
                            std::cout << "Invalid move index, please make sure the move index is 1, 2 or 3!\n"
                            << "Try again: ";
                            continue;
                        } catch (Contestant::ErrorCarOutOfBounds) {
                            std::cout << "Your car left the track bounds! You miss your turn!\n";
                            break;
                        } catch (Contestant::ErrorMoveIsImpossibleToPerform) {
                            std::cout << "Your car ran into another car! You miss your turn!\n";
                            break;
                        }
                    }
                }
            }
        }

        std::cout << Race::trackToStr();
    }

    std::cout << Race::winnersToStr(winners) << '\n';
}

void Race::scaleRaceTrack() {
    for (unsigned int i = 0; i < this->track.size(); i++) {
        for (unsigned int j = 0; j < this->track_length - 1; j++) {
            this->track[i].push_back(NULL);
        }
    }
}

bool Race::isTheRaceLive(std::vector<Contestant> winners, unsigned int amount_to_finish) {
    return winners.size() < amount_to_finish;
}

std::string Race::trackToStr() {
    std::stringstream ss;

    ss << "[ Race Track ]\n";
    for (unsigned int i = 0; i < this->track.size(); i++) {
        ss << '+';
        for (unsigned int j = 0; j < this->track[0].size(); j++) {
            ss << '-';
        }
        ss << "+\n";

        ss << '|';
        for (unsigned int j = 0; j < this->track[0].size(); j++) {
            if (this->track[i][j] == NULL) {
                ss << ' ';
            } else {
                ss << track[i][j]->getName()[0];
            }
        }
        ss << "|\n";

    }

    ss << '+';
    for (unsigned int j = 0; j < this->track[0].size(); j++) {
        ss << '-';
    }
    ss << "+\n";

    return ss.str();
}

std::string Race::movesToStr() {
    std::stringstream ss;

    ss << "[ Available moves ]\n"
    << "1. \"Just movin' on\"                           (rigth)\n"
    << "2. \"Ay cyka, imma drift those blyats away\"    (down + right -> left -> up + right -> rigth)\n"
    << "3. \"That lane changer who never signals\"      (up + right)\n";

    return ss.str();
}

std::string Race::winnersToStr(std::vector<Contestant> winners) {
    std::stringstream ss;
    ss << "[ Winners ]\n";
    for (unsigned int i = 0; i < winners.size(); i++) {
        ss << i + 1 << ". " << winners[i].getName() << '\n';
    }
    
    return ss.str();
}