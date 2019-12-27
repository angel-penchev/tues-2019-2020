#ifndef COMPONENT_HH
#define COMPONENT_HH

class Component {
    double price;

public:
    Component(double price);

    float get_own_price() const;

    float get_total_price() const;
};

#endif
