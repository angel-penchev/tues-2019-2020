#include "service.hh"

Service::Service(std::vector<User> users, std::vector<Media> medias)
    : users(users), medias(medias) {}

void Service::addUser(User user) {
    this->users.push_back(user);
}

void Service::addMedia(Media media) {
    this->medias.push_back(media);
}

std::vector<User> Service::getUsers() const {
    return this->users;
}

Payment Service::getUserPayment(User User, unsigned int index) const {
    if(index > User.getPayments().size()) {
        throw ErrorListIndexOutOfRange();
    }

    return User.getPayments()[index];
}

void Service::markPaymentAsComplete(User User, unsigned int index) const {
    Service::getUserPayment(User, index).setIsPurchased(true);
}

Media Service::findMediaByTitle(std::string title) {
    for (unsigned int i = 0; i < this->medias.size(); i++) {
        if (medias[i].getTitle() == title) {
            return medias[i];
        }
    }

    throw ErrorMediaNotFound();
}