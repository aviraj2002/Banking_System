#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>
#include <string>
#include "Transaction.h"

class Account {
private:
    int accountId;
    double balance;
    std::string accountType;
    std::vector<Transaction> transactions;

public:
    Account(int id, double balance, std::string type);

    int getAccountId() const;
    double getBalance() const;
    std::string getAccountType() const;

    void deposit(double amount);
    void withdraw(double amount);
    void transfer(Account& targetAccount, double amount);
    void viewTransactions() const;

    static std::string getCurrentDate();  // Declare the static method
};

#endif
