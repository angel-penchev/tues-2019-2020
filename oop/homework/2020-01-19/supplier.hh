#ifndef SUPPLIER_HH
#define SUPPLIER_HH

#include <string>

class Supplier {
    std::string name;

public:
    Supplier(std::string name);

    std::string const& get_name() const;
};

#endif
