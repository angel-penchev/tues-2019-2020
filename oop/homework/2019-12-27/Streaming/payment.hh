#ifndef PAYMENT_HH
#define PAYMENT_HH

#include <ctime>
#include <vector>
#include "media.hh"

class Payment {
    time_t period_beginning;
    time_t period_end;
    std::vector<Media> medias;
    double price;
    bool is_purchased;

public:
    Payment(time_t period_beginning, time_t period_end, std::vector<Media> medias, double price, bool is_purchased);

    time_t getPeriodBeginning() const;

    time_t getPeriodEnd() const;

    std::vector<Media> getMedias() const;

    double getPrice() const;

    bool getIsPurchased() const;

    void setIsPurchased(bool is_purchased);
};

#endif
