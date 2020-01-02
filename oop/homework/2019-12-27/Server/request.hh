#ifndef REQUEST_HH
#define REQUEST_HH

#include <string>
#include <vector>
#include "global.hh"

class Request {
    std::string ip;
    std::string path;
    std::vector<std::string> params;

public:
    Request(std::string ip, std::string path, std::vector<std::string> params = {});

    std::string getIP() const;

    std::string getPath() const;

    std::vector<std::string> getParams() const;
};

#endif
