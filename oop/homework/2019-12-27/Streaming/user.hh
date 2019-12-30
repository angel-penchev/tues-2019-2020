#ifndef USER_HH
#define USER_HH

#include <string>
#include <vector>
#include "media.hh"
#include "payment.hh"

class User {
    std::string name;
    std::string email;
    std::vector<Media> medias;
    std::vector<Payment> payments;

public:
    User(std::string name, std::string email, std::vector<Media> medias, std::vector<Payment> payments);

    std::string getName() const;

    std::string getEmail() const;

    std::vector<Media> getMedias() const;

    std::vector<Payment> getPayments() const;
};

#endif
