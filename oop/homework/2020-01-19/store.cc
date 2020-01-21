#include "store.hh"

Store::Store(std::vector<User> users, std::vector<Item> items, std::vector<Order> orders)
    : users(users), items(items), orders(orders) {}

void Store::add_user(User const &user) {
    for (auto i : this->users) {
        if (i.get_username() == user.get_username()) {
            throw ErrorUsernameAlreadyExsists();
        }
    }

    this->users.push_back(user);
}

void Store::add_item(Item const& item) {
    this->items.push_back(item);
}

void Store::create_order(Order const& order) {
    for (auto i : this->orders) {
        if (i.get_id() == order.get_id()) {
            throw ErrorOrderIdAlreadyExsists();
        }
    }

    bool is_user_found = false;
    for (auto i : this->users) {
        if (i.get_id() == order.get_ordered_by().get_id()) {
            is_user_found = true;
            break;
        }
    }
    if (!is_user_found) {
        throw ErrorUserDoesNotExsist();
    }

    for (auto i : order.get_items_ordered()) {
        for (auto j : this->items) {
            if (i.first.get_name() == j.get_name()) {
                if (i.second > j.get_supply()) {
                    throw ErrorOrderedMoreThanAvailableSupply();
                }
            }
        }
    }

    this->orders.push_back(order);
}

std::pair<double, unsigned int> Store::accept_order(unsigned int order_id) {
    for (auto i : this->orders) {
        if (i.get_id() == order_id) {
            if (i.get_status() != OrderStatus::New) {
                throw ErrorOrderStatusError();
            }
            i.set_status(OrderStatus::Accepted);
            
            std::pair<double, unsigned int> result = {0, 0};
            for (auto const& x : i.get_items_ordered()) {
                result.first += x.first.get_price();
                if (result.second < x.first.get_delivery_time()) {
                    result.second = x.first.get_delivery_time();
                }
            }

            return result;
        }
    }

    throw Store::ErrorOrderDoesNotExsist();
}

void Store::send_order(unsigned int order_id) {
    for (auto i : this->orders) {
        if (i.get_id() == order_id) {
            if (i.get_status() != OrderStatus::Accepted) {
                throw ErrorOrderStatusError();
            }
            i.set_status(OrderStatus::Sent);
            return;
        }
    }

    throw Store::ErrorOrderDoesNotExsist();
}

std::vector<Order const*> Store::get_orders_by_user(unsigned int user_id) const {
    std::vector<Order const*> result;

    bool is_user_found = false;
    for (auto i : this->users) {
        if (i.get_id() == user_id) {
            is_user_found = true;
            break;
        }
    }
    if (!is_user_found) {
        throw ErrorUserDoesNotExsist();
    }

    for (auto const& i : this->orders) {
        if (i.get_ordered_by().get_id() == user_id) {
            result.push_back(&i);
        }
    }

    return result;
}

std::vector<Item const*> Store::get_items_by_supplier(Supplier const& supplier) const {
    std::vector<Item const*> result;

    for (auto const& i : this->items) {
        if (i.get_supplier().get_name() == supplier.get_name()) {
            result.push_back(&i);
        }
    }

    return result;
}
