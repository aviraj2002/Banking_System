#include "Customer.h"
#include <iostream>

Customer::Customer(int id, std::string name, std::string address, std::string phone)
    : customerId(id), name(name), address(address), phoneNumber(phone) {}

int Customer::getCustomerId() const {
    return customerId;
}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getAddress() const {
    return address;
}

std::string Customer::getPhoneNumber() const {
    return phoneNumber;
}

void Customer::addAccount(Account& account) {
    accounts.push_back(account);
}

void Customer::viewAccounts() const {
    std::cout << "Accounts for " << name << " (Customer ID: " << customerId << "):\n";
    for (const auto& account : accounts) {
        std::cout << "Account ID: " << account.getAccountId() << ", Type: " << account.getAccountType() << ", Balance: " << account.getBalance() << "\n";
    }
}

Account* Customer::getAccountById(int accountId) {
    for (auto& account : accounts) {
        if (account.getAccountId() == accountId) {
            return &account;
        }
    }
    return nullptr; // Account not found
}
