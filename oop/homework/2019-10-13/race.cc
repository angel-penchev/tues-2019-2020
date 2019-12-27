#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

class Contestant {
private:
    std::string name;
    double speed;
    double distance;

public:
    Contestant() {
        this->name = "";
        this->speed = 0;
        this->distance = 0;
    }

    Contestant(std::string name, double speed) {
        this->name = name;
        this->speed = speed;
        this->distance = 0;
    }

    std::string getName() {
        return this->name;
    }

    double getSpeed() {
        return this->speed;
    }
    
    double getDistance() {
        return this->distance;
    }

    void setDistance(double distance) {
        this->distance = distance;
    }

    void calcDistance(int iterations) {
        distance = speed * iterations;
    }
    
};

class Race {
private:
    std::vector<Contestant> contestants;

public:
    std::vector<Contestant> getContestants() {
        return this->contestants;
    }

    void addContestant(Contestant contestant) {
        this->contestants.push_back(contestant);
    }

    void resetContestants() {
        for (int i = 0; i < this->contestants.size(); i++) {
            this->contestants[i].setDistance(0);
        }
        
    }

    void simulateRace(int iteration_count) {
        resetContestants();
        for (int i = 0; i < contestants.size(); i++) {
            contestants[i].calcDistance(iteration_count);
        }

        std::sort(contestants.begin(), contestants.end(), [](Contestant A, Contestant B) {
            return A.getDistance() > B.getDistance();
        });
        
        std::cout << getContestantStanding();
    }

    std::string getContestantStanding() {
        std::stringstream ss;
        for (int i = 0; i < contestants.size(); i++) {
            ss << contestants[i].getName() << ": " << contestants[i].getDistance() << "(" << contestants[i].getSpeed() << ")\n";
        }
        return ss.str();
    }
};

int main() {
    Race race;
    race.addContestant(Contestant("Gosho Losho", 4));
    race.addContestant(Contestant("Tichacho", 5));
    race.addContestant(Contestant("Cybertruckn't", 8));

    race.simulateRace(3);
    return 0;
}