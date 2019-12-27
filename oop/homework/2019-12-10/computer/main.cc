#include "cpu.hh"
#include "ram.hh"
#include "hdd.hh"
#include "psu.hh"
#include "mobo.hh"
#include "case.hh"
#include <iostream>

int main() {
    CPU cpu(200, 4, 2);
    RAM ram(60, 16, 4);
    HDD hdd(30, 1000, 42);
    PSU psu(50, 200);

    RAM rams[] = {ram};
    MOBO mobo(70, cpu, rams, 1);

    HDD hdds[] = {hdd};
    Case case1(20, mobo, psu, hdds, 1);

    std::cout
        << case1.get_total_price() << '\n'
        << case1.get_total_score() << '\n';

    return 0;
}