#include "store.hh"
#include "clothing.hh"
#include "technology.hh"
#include <iostream>

int main() {
    std::vector<User> users = {
        User(0, "goshkolosko", "keepingPasswordsInPlainTextAgain,huh?"),
        User(1, "moshkoposhko", "totallyNotGosho'sAltROFL88"),
        User(2, "tsb", "ayy lmao im gonna tsb's username here as well")
    };
    
    std::vector<Item> items = {
        Clothing(std::string("Gucc Gung"), 999.69, 2, Supplier(std::string("Gucc")), 18, std::string("red/white"), 'M', std::string("монет")),
        Clothing(std::string("Generic Gosho"), 0.99, 22, Supplier(std::string("D1Ck")), 28, std::string("black"), 'L', std::string("fabric")),
        Technology(std::string("NuKeIA 3310"), 69.69, 1, Supplier(std::string("NuKeIA")), 2, TechnologyType::WhiteElectronics, 2, 100),
        Technology(std::string("OmegaLuLNovo 7420"), 4200.69, 1, Supplier(std::string("LuLNovo")), 2, TechnologyType::WhiteElectronics, 5, 5),
        Technology(std::string("DRUN"), 100.69, 1, Supplier(std::string("D1Ck")), 35, TechnologyType::BlackElectronics, 0, 1)
    };

    std::vector<Order> orders = {
        Order(0, users[1], std::map<Item*, unsigned int>({{&items[0], 1}})),
        Order(1, users[0], std::map<Item*, unsigned int>({{&items[2], 1}, {&items[4], 2}})),
        Order(2, users[2], std::map<Item*, unsigned int>({{&items[1], 10}})),
        Order(3, users[0], std::map<Item*, unsigned int>({{&items[3], 1}}))
    };
    
    Store store = Store(users, items, orders);

    store.accept_order(1);
    store.accept_order(2);

    store.add_item(Technology(std::string("USB Brick"), 200.99, 33, std::string("Jordanventions"), 35, TechnologyType::Consumable, 10, 10));

    store.add_user(User(3, "tsb", "heh, finally a place where that username is not taken"));

    std::cout << store.get_items_by_supplier(Supplier("D1Ck")).size() << '\n';

    std::cout << store.get_orders_by_user(0).size() << '\n';

    return 0;
}
