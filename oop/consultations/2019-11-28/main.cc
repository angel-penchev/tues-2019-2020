#include <iostream>
#include "person.hh"

int main(int argc, char const *argv[]) {
    Person person("Ivan", "Dobrev", 23);

    std::cout << person << '\n';
    return 0;
}
