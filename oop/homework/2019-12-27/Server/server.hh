#ifndef SERVER_HH
#define SERVER_HH

#include <vector>
#include <string>
#include "response.hh"
#include "request.hh"
#include "handler.hh"
#include "global.hh"

class Server {
    std::vector<std::string> paths;
    std::vector<Handler> handlers;

public:
    Server(std::vector<std::string> paths);

    Response* routeRequest(Request* req);
};

#endif
