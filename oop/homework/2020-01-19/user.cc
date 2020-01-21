#include "user.hh"

User::User(unsigned int id, std::string username, std::string password)
    : id(id), username(username), password(password) {}

unsigned int const& User::get_id() const {
    return this->id;
}

std::string const& User::get_username() const {
    return this->username;
}

std::string const& User::get_password() const {
    return this->password;
}