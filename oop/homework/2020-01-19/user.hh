#ifndef USER_HH
#define USER_HH

#include <string>

class User {
    unsigned int id;
    std::string username;
    std::string password;

public:
    User(unsigned int id, std::string username, std::string password);

    unsigned int const& get_id() const;

    std::string const& get_username() const;

    std::string const& get_password() const;
};

#endif
