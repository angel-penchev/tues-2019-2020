#ifndef ORDER_HH
#define ORDER_HH

#include <map>
#include "item.hh"
#include "user.hh"

class Order {
    unsigned int id;
    User ordered_by;
    std::map<Item, unsigned int> items_ordered;
    std::string status;

public:
    Order(unsigned int id, User ordered_by, std::map<Item, unsigned int> items_ordered);

    void add_item(Item item, unsigned int amount);

    unsigned int const& get_id() const;

    User const& get_ordered_by() const;

    std::map<Item, unsigned int> get_items_ordered() const;

    std::string const& get_status() const;
    void set_status(std::string status);
};

#endif
