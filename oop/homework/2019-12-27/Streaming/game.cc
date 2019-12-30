#include "game.hh"

Game::Game(std::string title, std::string autor, double price, unsigned int playtime)
    : Media(title, autor, price), playtime(playtime) {}

double Game::calcSubscription() const {
    return this->getPrice() * this->playtime;
}