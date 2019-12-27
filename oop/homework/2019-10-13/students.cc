#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <sstream>

class StudentInfo {
private:
    std::string name;
    std::vector<double> marks;

public:
    class ErrorCollectionSizeBiggerThan10 {
        private:
        std::string message;

        public:
        ErrorCollectionSizeBiggerThan10() {
            message = "Collection size cannot be bigger than 10!";
        }
    };

    class ErrorMarkOutOfRange {
        private:
        std::string message;

        public:
        ErrorMarkOutOfRange() {
            message = "The mark should be between 2 and 6!";
        }
    };

    class ErrorNameTooShort {
        private:
        std::string message;

        public:
        ErrorNameTooShort() {
            message = "Student's name is too short!";
        }
    };

    class ErrorIndexOutOfRange {
        private:
        std::string message;

        public:
        ErrorIndexOutOfRange() {
            message = "Mark index out of range!";
        }
    };


    StudentInfo() {}
    StudentInfo(std::string name, std::vector<double> marks) {
        if (marks.size() > 10) {
            throw ErrorCollectionSizeBiggerThan10();
        }
        
        for (int i = 0; i < marks.size(); i++) {
            if (marks[i] < 2 || marks[i] > 6) {
                throw ErrorMarkOutOfRange();
            }
        }

        if (name.length() < 5) {
            throw ErrorNameTooShort();
        }

        this->name = name;
        this->marks = marks;
    }


    std::string getName() {
        return this->name;
    }

    std::vector<double> getMarks() {
        return this->marks;
    }

    void addMark(double new_mark) {
        if (this->marks.size() == 10) {
            throw ErrorCollectionSizeBiggerThan10();
        }

        if (new_mark < 2 || new_mark > 6) {
            throw ErrorMarkOutOfRange();
        }

        this->marks.push_back(new_mark);
    }

    double getAverage() {
        return std::accumulate(this->marks.begin(), this->marks.end(), 0.0) / this->marks.size();
    }

    std::string toString() {
        std::stringstream ss;
        ss << this->name << ": ";
        for (int i = 0; i < this->marks.size(); i++) {
            ss << marks[i] << ' ';
        }
        ss << "[" << getAverage() << "]\n";
        return ss.str();
    }

    void removeMarkAt(int index) {
        if (index < 0 || index > this->marks.size()) {
            throw ErrorIndexOutOfRange();
        }

        this->marks.erase(marks.begin() + index);
    }

    void replaceMarkAt(int index, double new_mark) {
        if (index < 0 || index > this->marks.size()) {
            throw ErrorIndexOutOfRange();
        }

        if (new_mark < 2 || new_mark > 6) {
            throw ErrorMarkOutOfRange();
        }

        this->marks[index] = new_mark;
    }
};

int main(int argc, char const *argv[]) {
    StudentInfo student = StudentInfo("Gosho Losho", {5, 6, 4.44});
    student.addMark(5.66);
    std::cout << student.toString();
    return 0;
}
