#include <iostream>
#include <list>
#include <string>

class BankAccount {
private:
    std::string client_name;
    std::string number;
    double balance;

public:
    BankAccount() {
        this->client_name = "";
        this->number = "";
        this->balance = 0;
    }

    BankAccount(std::string client_name, std::string number) {
        this->client_name = client_name;
        this->number = number;
        this->balance = 0;
    }

    BankAccount(std::string client_name, std::string number, double balance) {
        this->client_name = client_name;
        this->number = number;
        this->balance = balance;
    }
    

    void deposit(double amount) {
        this->balance += amount;
    }

    void draw(double amount) {
        this->balance -= amount;
    }

    void print() {
        std::cout << client_name << ", " << number << ", " << balance << " leva" << std::endl;
    }


    std::string get_client_name() {
        return client_name;
    }

    std::string get_number() {
        return number;
    }

    double get_balance() {
        return balance;
    }

    bool is_empty() {
        return balance == 0;
    }
};

class Bank {
private:
    std::list <BankAccount> accounts;
    
public:
    Bank() { }

    Bank(std::list<BankAccount> accounts) {
        this->accounts = accounts;
    }
    

    void add_account(BankAccount account) {
        this->accounts.push_back(account);
    }

    void remove_account(std::string number) {
        for (std::list<BankAccount>::iterator it = this->accounts.begin(); it != this->accounts.end(); ++it) {
            if(!it->get_number().compare(number)) {
                it = this->accounts.erase(it);
            }
        }
    }

    double get_account_balance(std::string number) {
        for (std::list<BankAccount>::iterator it = this->accounts.begin(); it != this->accounts.end(); ++it) {
            if(!it->get_number().compare(number)) {
                std::cout << it->get_balance() << std::endl;
            }
        }
    }

    double get_client_balance(std::string client_name) {
        double current_sum = 0;
        for (std::list<BankAccount>::iterator it = this->accounts.begin(); it != this->accounts.end(); ++it) {
            if(!it->get_client_name().compare(client_name)) {
                current_sum += it->get_balance();
            }
        }
        std::cout << current_sum << std::endl;
    }
};

int main() {
    BankAccount account_of_ivan("Ivan", "1", 2000);
    BankAccount account_of_petar("Petar", "2", 500);
    BankAccount second_account_of_ivan("Ivan", "3", 400);

    std::list<BankAccount> accounts = { account_of_ivan, account_of_petar };
    Bank bank(accounts);
    bank.add_account(second_account_of_ivan); // добавя втора сметка на "Ivan" в банката

    bank.get_account_balance("2"); // 500
    bank.remove_account("2"); // премахва сметката на "Petar" от банката

    bank.get_client_balance("Ivan");
    
    return 0;
}