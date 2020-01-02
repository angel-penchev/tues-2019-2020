#ifndef HANDLER_HH
#define HANDLER_HH

#include <string>
#include <sstream>
#include "response.hh"
#include "request.hh"
#include "global.hh"

class Handler {
public:
    Response* handleRequest(Request* req);
};

#endif
