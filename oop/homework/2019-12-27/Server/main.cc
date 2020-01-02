#include "main.hh"

int main() {
    Server server = Server({"/login.html", "/home.html", "/goshko.html", "/api/login", "/api/get_users"});
    Request req1 = Request("127.0.0.1", "/login.html");
    std::cout << server.routeRequest(&req1)->getStatus() << ", " << server.routeRequest(&req1)->getMessage() << '\n';

    Request req2 = Request("127.0.0.1", "/shshko.html");
    std::cout << server.routeRequest(&req2)->getStatus() << ", " << server.routeRequest(&req2)->getMessage() << '\n';
    
    Request req3 = Request("127.0.0.1", "/api/get_users");
    std::cout << server.routeRequest(&req3)->getStatus() << ", " << server.routeRequest(&req3)->getMessage() << '\n';
    
    Request req4 = Request("127.0.0.1", "/api/login", {"Koshko", "somebodyoncetoldme888"});
    std::cout << server.routeRequest(&req4)->getStatus() << ", " << server.routeRequest(&req4)->getMessage() << '\n';
    
    Request req5 = Request("127.0.0.1", "/api/login", {"AKindMessage:", "MarioTrqbvaDaSeNauchiDaPisheUsloviq<3<3"});
    std::cout << server.routeRequest(&req5)->getStatus() << ", " << server.routeRequest(&req5)->getMessage() << '\n';
    return 0;
}