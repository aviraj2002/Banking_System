#include "BankingService.h"
#include <iostream>

void BankingService::deposit(Account& account, double amount) {
    account.deposit(amount);
}

void BankingService::withdraw(Account& account, double amount) {
    account.withdraw(amount);
}

void BankingService::transfer(Account& fromAccount, Account& toAccount, double amount) {
    fromAccount.transfer(toAccount, amount);
}
