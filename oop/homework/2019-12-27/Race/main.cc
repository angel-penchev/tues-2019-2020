#include "race.hh"

int main() {
    Race r = Race(50);
    Contestant c1 = Contestant("Goshko", 3);
    r.addContestant(&c1);
    Contestant c2 = Contestant("Moshko", 2);
    r.addContestant(&c2);
    Contestant c3 = Contestant("Poshko", 5);
    r.addContestant(&c3);
    Contestant c4 = Contestant("Toshko", 1);
    r.addContestant(&c4);
    r.startRace();
    return 0;
}
