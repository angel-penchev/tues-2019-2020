#include "payment.hh"

Payment::Payment(time_t period_beginning, time_t period_end, std::vector<Media> medias, double price, bool is_purchased)
    : period_beginning(period_beginning), period_end(period_end), medias(medias), price(price), is_purchased(is_purchased) {}

bool Payment::getIsPurchased() const {
    return this->is_purchased;
}

void Payment::setIsPurchased(bool is_purchased) {
    this->is_purchased = is_purchased;
}

time_t Payment::getPeriodBeginning() const {
    return this->period_beginning;
}

time_t Payment::getPeriodEnd() const {
    return this->period_end;
}

std::vector<Media> Payment::getMedias() const {
    return this->medias;
}

double Payment::getPrice() const {
    return this->price;
}