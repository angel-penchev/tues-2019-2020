#ifndef PERSON_HH
#define PERSON_HH

#include <string>

class Person {
private:
    std::string first_name;
    std::string last_name;
    uint age;

public:
    Person(std::string first_name, std::string last_name, uint age);

    //  |- резултата няма да се измени
    // \|/              /- забранява промяна на променливата при извикване
    const std::string const& getFirstName();
    const std::string const& getLastName();
    const uint const& getAge();
};

std::ostream& operator<<(std::ostream& os, Person const& person); // cout << person

#endif