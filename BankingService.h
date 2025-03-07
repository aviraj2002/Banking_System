#ifndef BANKINGSERVICE_H
#define BANKINGSERVICE_H

#include "Account.h"

class BankingService {
public:
    static void deposit(Account& account, double amount);
    static void withdraw(Account& account, double amount);
    static void transfer(Account& fromAccount, Account& toAccount, double amount);
};

#endif
