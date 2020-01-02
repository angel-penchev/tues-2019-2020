#include "response.hh"

Response::Response(uint status, std::string message)
    : status(status), message(message) {}

uint Response::getStatus() const {
    return this->status;
}

std::string Response::getMessage() const {
    return this->message;
}