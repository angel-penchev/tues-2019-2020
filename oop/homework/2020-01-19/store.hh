#ifndef STORE_HH
#define STORE_HH

#include <vector>
#include "user.hh"
#include "item.hh"
#include "order.hh"

class Store {
    std::vector<User> users;
    std::vector<Item> items;
    std::vector<Order> orders;

public:
    class ErrorUsernameAlreadyExsists {};
    class ErrorOrderIdAlreadyExsists {};
    class ErrorUserDoesNotExsist {};
    class ErrorOrderedMoreThanAvailableSupply {};
    class ErrorOrderDoesNotExsist {};
    class ErrorOrderStatusError {};

    Store(std::vector<User> users, std::vector<Item> items, std::vector<Order> orders);

    void add_user(User const& user);

    void add_item(Item const& item);

    void create_order(Order const& order);

    std::pair<double, unsigned int> accept_order(unsigned int order_id);

    void send_order(unsigned int order_id);

    std::vector<Order const*> get_orders_by_user(unsigned int user_id) const;

    std::vector<Item const*> get_items_by_supplier(Supplier const& supplier) const;
};

#endif
