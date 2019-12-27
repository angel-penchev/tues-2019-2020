#include <iostream>
#include <vector>

class Vector {
private:
    std::vector<double> elements;

public:
    Vector(std::vector<double> elements)
        : elements(elements) {};

    std::vector<double> const& getElements() const {
        return this->elements;
    }

    unsigned int getArity() const {
        return this->elements.size();
    }

    Vector operator+(Vector const& other) const {
        std::vector<double> result;
        for (int i = 0; i < this->elements.size(); i++) {
            result.push_back(this->getElements()[i] + other.getElements()[i]);
        }
        return Vector(result);
    }

    Vector& operator+=(Vector const& other) {
        for (int i = 0; i < this->elements.size(); i++) {
            this->elements[i] += other.getElements()[i];
        }
        return *this;
    }

    Vector operator-(Vector const& other) const {
        std::vector<double> result;
        for (int i = 0; i < this->elements.size(); i++) {
            result.push_back(this->getElements()[i] - other.getElements()[i]);
        }
        return Vector(result);
    }

    Vector& operator-=(Vector const& other) {
        for (int i = 0; i < this->elements.size(); i++) {
            this->elements[i] -= other.getElements()[i];
        }
        return *this;
    }

    Vector operator*(double scalar) const {
        std::vector<double> result;
        for (int i = 0; i < this->elements.size(); i++) {
            result.push_back(this->elements[i] * scalar);
        }
        return Vector(result);
    }

    Vector& operator*=(double scalar) {
        for (int i = 0; i < this->elements.size(); i++) {
            this->elements[i] *= scalar;
        }
        return *this;
    }
};

std::ostream& operator<<(std::ostream& os, Vector const& v) {
    os << '(';
    for (int i = 0; i < v.getArity(); i++) {
        os << v.getElements()[i];
        if (i + 1 < v.getArity()) {
            os << ", ";
        }
    }
    os << ")\n";
    return os;
}

int main(int argc, char const *argv[]) {
    std::vector<double> elements = {1, 2, 3, 4, 5};
    Vector vec = Vector(elements);
    std::vector<double> other_elements = {2, 3, 0, 4, 1};
    Vector other_vec = Vector(other_elements);
    std::cout << vec;
    vec = vec + other_vec;
    std::cout << vec;
    vec += other_vec;
    std::cout << vec;
    vec -= other_vec;
    std::cout << vec;
    return 0;
}
