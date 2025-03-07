#include "Account.h"
#include <iostream>
#include "Transaction.h"

Account::Account(int id, double balance, std::string type)
    : accountId(id), balance(balance), accountType(type) {}

int Account::getAccountId() const {
    return accountId;
}

double Account::getBalance() const {
    return balance;
}

std::string Account::getAccountType() const {
    return accountType;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        transactions.push_back(Transaction(transactions.size() + 1, "Deposit", amount, getCurrentDate()));
    } else {
        std::cout << "Invalid deposit amount!\n";
    }
}

void Account::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        transactions.push_back(Transaction(transactions.size() + 1, "Withdrawal", amount, getCurrentDate()));
    } else {
        std::cout << "Invalid withdrawal amount or insufficient funds!\n";
    }
}

void Account::transfer(Account& targetAccount, double amount) {
    if (balance >= amount) {
        this->withdraw(amount);
        targetAccount.deposit(amount);
        std::cout << "Transfer successful!\n";
    } else {
        std::cout << "Insufficient funds for transfer!\n";
    }
}

void Account::viewTransactions() const {
    for (const auto& transaction : transactions) {
        std::cout << "Transaction ID: " << transaction.getTransactionId() 
                  << ", Type: " << transaction.getType() 
                  << ", Amount: " << transaction.getAmount() 
                  << ", Date: " << transaction.getDate() << "\n";
    }
}

std::string getCurrentDate() {
    return "2025-03-07"; // Static date for simplicity
}
