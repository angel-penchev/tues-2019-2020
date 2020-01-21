#ifndef ORDER_HH
#define ORDER_HH

#include <map>
#include "item.hh"
#include "user.hh"

enum class OrderStatus { New, Accepted, Sent };

class Order {
    unsigned int id;
    User ordered_by;
    std::map<Item, unsigned int> items_ordered;
    OrderStatus status;

public:
    Order(unsigned int id, User ordered_by, std::map<Item, unsigned int> items_ordered);

    void add_item(Item item, unsigned int amount);

    unsigned int const& get_id() const;

    User const& get_ordered_by() const;

    std::map<Item, unsigned int> get_items_ordered() const;

    OrderStatus const& get_status() const;

    void set_status(OrderStatus status);
};

#endif
