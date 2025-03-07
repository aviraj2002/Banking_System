#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Account.h"

class Customer {
private:
    int customerId;
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::vector<Account> accounts;

public:
    Customer(int id, std::string name, std::string address, std::string phone);
    
    int getCustomerId() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhoneNumber() const;

    void addAccount(Account& account);
    void viewAccounts() const;
    Account* getAccountById(int accountId);
};

#endif
