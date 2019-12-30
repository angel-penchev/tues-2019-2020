#include "user.hh"

User::User(std::string name, std::string email, std::vector<Media> medias, std::vector<Payment> payments)
    : name(name), email(email), medias(medias), payments(payments) {}

std::string User::getName() const {
    return this->name;
}

std::string User::getEmail() const {
    return this->email;
}

std::vector<Media> User::getMedias() const {
    return this->medias;
}

std::vector<Payment> User::getPayments() const {
    return this->payments;
}