#include "handler.hh"

Response* Handler::handleRequest(Request* req) {
    try {
        if (req->getPath().substr(req->getPath().find_last_of(".")) == ".html") {
            std::stringstream msg;
            msg << "<html>" << req->getPath() << "</html>";

            static Response response = Response(200, msg.str());
            return &response;
        }
    } catch(std::out_of_range) { }

    if (req->getPath() == "/api/login") {
        if (req->getParams().size() == 0) {
            static Response response = Response(403, "Unauthorized");
            return &response;
        }

        for (uint i = 0; i < USERS.size(); i++) {
            if (USERS[i] == req->getParams()[0]) {
                static Response response = Response(200, "OK");
                return &response;
            }
        }

        static Response response = Response(403, "Unauthorized");
        return &response;        
    }

    if (req->getPath() == "/api/get_users") {
        std::stringstream msg;
        
        msg << "[";
        for (uint i = 0; i < USERS.size(); i++) {
            msg << '\"' << USERS[i] << '\"';
            
            if (i != USERS.size() - 1) {
                msg << ", ";
            }
        }
        msg << "]";
    
        static Response response = Response(200, msg.str());
        return &response;
    }

    static Response response = Response(404, "NOT FOUND!");
    return &response;
}