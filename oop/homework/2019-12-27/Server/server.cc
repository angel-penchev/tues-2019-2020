#include "server.hh"

Server::Server(std::vector<std::string> paths)
    : paths(paths) {}

Response* Server::routeRequest(Request* req) {
    for (uint i = 0; i < this->paths.size(); i++) {
        if (req->getPath() == this->paths[i]) {
            Handler handler;
            return handler.handleRequest(req);
        }
    }

    static Response response = Response(404, "NOT FOUND");
    return &response;
}