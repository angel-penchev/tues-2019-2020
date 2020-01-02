#include "request.hh"

Request::Request(std::string ip, std::string path, std::vector<std::string> params)
    : ip(ip), path(path), params(params) {}


std::string Request::getIP() const {
    return this->ip;
}

std::string Request::getPath() const {
    return this->path;
}

std::vector<std::string> Request::getParams() const {
    return this->params;
}