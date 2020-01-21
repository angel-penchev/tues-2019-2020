#include "order.hh"

Order::Order(unsigned int id, User ordered_by, std::map<Item, unsigned int> items_ordered)
    : id(id), ordered_by(ordered_by), items_ordered(items_ordered), status(OrderStatus::New) {}

void Order::add_item(Item item, unsigned int amount) {
    this->items_ordered[item] = amount;
}

unsigned int const& Order::get_id() const {
    return this->id;
}

User const& Order::get_ordered_by() const {
    return this->ordered_by;
}

std::map<Item, unsigned int> Order::get_items_ordered() const {
    return this->items_ordered;
}

OrderStatus const& Order::get_status() const {
    return this->status; 
}

void Order::set_status(OrderStatus status) {
    this->status = status;
}