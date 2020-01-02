#ifndef RESPONSE_HH
#define RESPONSE_HH

#include <string>
#include "global.hh"

class Response {
    uint status;
    std::string message;

public:
    Response(uint status, std::string message);

    uint getStatus() const;

    std::string getMessage() const;
};

#endif
