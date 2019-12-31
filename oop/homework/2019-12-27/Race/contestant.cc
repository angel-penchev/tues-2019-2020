#include "contestant.hh"

Contestant::Contestant(std::string name, unsigned int speed)
    : name(name), speed(speed) {}

std::string Contestant::getName() const {
    return this->name;
}

std::array<long int, 2> Contestant::getPosition() const {
    return this->position;
}

void Contestant::setPosition(std::array<long int, 2> position) {
    this->position = position;
}

unsigned int Contestant::getSpeed() const {
    return this->speed;
}

void Contestant::moveForward(std::vector<std::vector<Contestant*> > *track, unsigned int move) {
    if(this->position[1] + this->speed >= int((*track)[0].size())) {
        throw FinishedTheRace();
        return;
    }

    switch (move) {
    // Move 1
    case 1:
        if ((*track)[this->position[0]][this->position[1] + this->speed] == NULL) {     // Right

            this->position = { this->position[0], this->position[1] + this->speed };
            (*track)[this->position[0]][this->position[1]] = this;
            return;
        }
        break;

    // Move 2
    // (btw, may i ask, is the driver drunk or is the writer the one with the tequila bottle?)
    case 2:
        // Catching the case if the car, exits the track
        if (this->position[0] + 1 >= int((*track).size())) {
            throw ErrorCarOutOfBounds();
            return;
        }

        if ((*track)[this->position[0] + 1][this->position[1] + 1] == NULL &&           // Down + Right
            (*track)[this->position[0] + 1][this->position[1]    ] == NULL &&           // Then Left -> Down from start
            (*track)[this->position[0]][this->position[1] + this->speed] == NULL) {     // Then Up -> Beggining; Then Right

            this->position = { this->position[0], this->position[1] + this->speed };
            (*track)[this->position[0]][this->position[1]] = this;
            return;
        }
        break;

    // Move 3
    case 3:
        // Catching the case if the car, exits the track
        if (this->position[0] - 1 < 0) {
            throw ErrorCarOutOfBounds();
            return;
        }

        if ((*track)[this->position[0] - 1][this->position[1]    ] == NULL &&           // Up
            (*track)[this->position[0] - 1][this->position[1] + this->speed] == NULL) { // Then Right

            this->position = { this->position[0] - 1, this->position[1] + this->speed };
            (*track)[this->position[0]][this->position[1]] = this;
            return;
        }
        break;
    
    default:
        throw ErrorInvalidMoveIndex();
        return;
    }

    throw ErrorMoveIsImpossibleToPerform();
}
