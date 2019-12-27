#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

class CarCataloge {
private:
    std::string brand;
    std::list<std::string> models;

    std::list<std::string>::iterator findModel(std::string model_name) {
        for (std::list<std::string>::iterator it = this->models.begin(); it != this->models.end(); ++it) {
            if (it->compare(model_name)) {
                return it;
            }
        }
        return models.end();


    }

public:
    class TooFewModels{
        private:
        std::string message;

        public:
        TooFewModels() {
            message = "The size of the inputed collection is less than 5...";
        }
    };

    class ModelHasEmptyName {
        private:
        std::string message;

        public:
        ModelHasEmptyName() {
            message = "One or more models have an empty name...";
        }
    };

    class ModelHasDuplicate {
        private:
        std::string message;

        public:
        ModelHasDuplicate() {
            message = "Duplicating models found in the collection...";
        }
    };

    class ModelNameTooShort {
        private:
        std::string message;

        public:
        ModelNameTooShort() {
            message = "The model name is too short...";
        }
    };

    class IndexOutOfRange {
        private:
        std::string message;

        public:
        IndexOutOfRange() {
            message = "Index out of range...";
        }
    };


    CarCataloge() { }
    
    CarCataloge(std::string brand, std::list<std::string> models) {
        this->brand = brand;
        this->models = models;

        if (this->models.size() < 5) {
            throw TooFewModels();
        }

        std::list<std::string>::iterator it = findModel("");
        if (it != models.end()) {
            throw ModelHasEmptyName();
        }

        if (std::unique(this->models.begin(), this->models.end()) != this->models.end()) {
            throw ModelHasDuplicate();
        }

        for (std::list<std::string>::iterator it = this->models.begin(); it != this->models.end(); ++it) {
            if (it->length() < 5) {
                throw ModelNameTooShort();
            }
        }
        
    }


    std::string getBrand() {
        return this->brand;
    }

    std::list<std::string> getModels() {
        return this->models;
    }

    void addModel(std::string model_name) {
        if (model_name == "") {
            throw ModelHasEmptyName();
        }

        std::list<std::string>::iterator it = findModel(model_name);
        if (it != models.end()) {
            throw ModelHasDuplicate();
        }
        this->models.push_back(model_name);
    }

    bool hasModel(std::string model_name) {
        std::list<std::string>::iterator it = findModel(model_name);
        if (it != models.end()) {
            return true;
        } else {
            return false;
        }
    }

    std::string toString() {
        std::stringstream ss;
        ss << this->brand << ":\n";
        for (std::list<std::string>::iterator it = this->models.begin(); it != this->models.end(); ++it) {
            ss << " " << *it;
        } 
        return ss.str();
    }

    void removeModelAt(int index) {
        if (index > this->models.size()) {
            throw IndexOutOfRange();
        }

        std::list<std::string>::iterator it = this->models.begin();
        std::advance( it, index );
        this->models.erase(it);
    }

    void replaceModelAt(int index, std::string model_name) {
        if (index > this->models.size()) {
            throw IndexOutOfRange();
        }

        if (model_name == "") {
            throw ModelHasEmptyName();
        }

        std::list<std::string>::iterator it = findModel(model_name);
        if (it != models.end()) {
            throw ModelHasDuplicate();
        }

        it = this->models.begin();
        std::advance( it, index );
        this->models.erase(it);
        this->models.insert(it, model_name);
    }
};

int main() {
    return 0;
}