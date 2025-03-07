#include "Transaction.h"

Transaction::Transaction(int id, std::string type, double amount, std::string date)
    : transactionId(id), type(type), amount(amount), date(date) {}

int Transaction::getTransactionId() const {
    return transactionId;
}

std::string Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getDate() const {
    return date;
}
