#include <iostream>
#include <vector>
#include <sstream>

class Product {
private:
    std::string name;
    double price;
    unsigned int quantity;

public:
    std::string getName() {
        return this->name;
    }

    void setName(std::string name) {
        this->name = name;
    }

    double getPrice() {
        return this->price;
    }

    void setPrice(double price) {
        this->price = price;
    }
    
    unsigned int getQuantity() {
        return this->quantity;
    }

    void setQuantity(double quantity) {
        this->quantity = quantity;
    }
};

class Supermarket {
private:
    std::vector<Product> products;

public:
    class ErrorPriceOrQuantityZero {
        private:
        std::string message;

        public:
        ErrorPriceOrQuantityZero() {
            message = "The price/quantity could not be equal to 0...";
        }
    };

    class ErrorNameNotFound {
        private:
        std::string message;

        public:
        ErrorNameNotFound() {
            message = "The name of the product could not be found...";
        }
    };

    class ErrorRemoveMoreThanStock {
        private:
        std::string message;

        public:
        ErrorRemoveMoreThanStock() {
            message = "The amount you are trying to remove is bigger than the available stock...";
        }
    };


    Supermarket() { }

    Supermarket(std::vector<Product> products) {
        this->products = products;
    }

    std::vector<Product> getProducts() {
        return this->products;
    }


    void addProduct(Product newProduct) {
        if (newProduct.getPrice() == 0 || newProduct.getQuantity() == 0) {
            throw ErrorPriceOrQuantityZero();
        }

        bool flag = true;
        for (int i = 0; i < this->products.size(); i++) {
            if (!this->products[i].getName().compare(newProduct.getName())) {
                this->products[i].setPrice(newProduct.getPrice());
                flag = false;
            }
        }

        if (flag) {
            this->getProducts().push_back(newProduct);
        }
    }

    void removeQuantity(Product toRemove) {
        std::vector<Product>::iterator it = this->products.begin();
        for (; it != this->products.end(); ++it) {
            if (it->getName().compare(toRemove.getName())) {
                break;
            }
        }
        if (it == this->products.end()) {
            throw ErrorNameNotFound();
        }


        for (int i = 0; i < this->products.size(); i++) {
            if (this->products[i].getName().compare(toRemove.getName())) {
                if (this->products[i].getQuantity() < toRemove.getQuantity()) {
                    throw ErrorRemoveMoreThanStock();
                }
                
                this->products[i].setQuantity(this->products[i].getPrice() - toRemove.getPrice());
            }
        }
    }

    std::string toString() {
        std::stringstream ss;
        for (int i = 0; i < this->products.size(); ++i) {
            ss << products[i].getName() << " - " << products[i].getPrice() << "(" << products[i].getQuantity() << ")\n";
        } 
        return ss.str();
    }

    void fromString(std::string results) {
        std::istringstream iss(results);
        // for(int i = 0; true; ++i) {

        // }
    }
};

int main() {
    std::vector<Product> products = {("Bapple", 1.20, 8)};
    Supermarket supermarket = Supermarket(products);
    return 0;
}