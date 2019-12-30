#ifndef MEDIA_HH
#define MEDIA_HH

#include <string>

class Media {
    std::string title;
    std::string autor;
    double price;

public:
    Media(std::string title, std::string autor, double price);

    double calcSubscription() const;

    std::string getTitle() const;

    std::string getAutor() const;

    double getPrice() const;
};

#endif
