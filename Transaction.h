#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    int transactionId;
    std::string type;
    double amount;
    std::string date;

public:
    Transaction(int id, std::string type, double amount, std::string date);

    int getTransactionId() const;
    std::string getType() const;
    double getAmount() const;
    std::string getDate() const;
};

#endif
