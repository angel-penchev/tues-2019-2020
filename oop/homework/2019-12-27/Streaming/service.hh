#ifndef SERVICE_HH
#define SERVICE_HH

#include <string>
#include <vector>
#include "user.hh"

class Service {
    std::vector<User> users;
    std::vector<Media> medias;

public:
    class ErrorListIndexOutOfRange {};
    
    class ErrorMediaNotFound {};
    
    Service(std::vector<User> users, std::vector<Media> medias);

    void addUser(User user);

    void addMedia(Media media);

    std::vector<User> getUsers() const;

    Payment getUserPayment(User User, unsigned int index) const;

    void markPaymentAsComplete(User User, unsigned int index) const;

    Media findMediaByTitle(std::string title);
};

#endif
