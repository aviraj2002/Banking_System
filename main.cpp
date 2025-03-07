#include <iostream>
#include <vector>
#include <limits>
#include "Customer.h"
#include "Account.h"
#include "Transaction.h"
#include "BankingService.h"

// Helper function to get current date (For simplicity, use a fixed date)
std::string getCurrentDate() {
    return "2025-03-07";  // Static date for this example
}

void printMenu() {
    std::cout << "\n--- Bank Menu ---\n";
    std::cout << "1. Create Customer\n";
    std::cout << "2. Create Account\n";
    std::cout << "3. Deposit\n";
    std::cout << "4. Withdraw\n";
    std::cout << "5. Transfer\n";
    std::cout << "6. View Account Details\n";
    std::cout << "7. View Transactions\n";
    std::cout << "8. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    std::vector<Customer> customers;
    int customerIdCounter = 1; // To track customer IDs
    int accountIdCounter = 101; // To track account IDs

    while (true) {
        printMenu();
        int choice;
        std::cin >> choice;

        if (choice == 1) { // Create Customer
            std::cin.ignore(); // To clear the buffer
            std::string name, address, phone;
            std::cout << "Enter customer name: ";
            std::getline(std::cin, name);
            std::cout << "Enter customer address: ";
            std::getline(std::cin, address);
            std::cout << "Enter customer phone number: ";
            std::getline(std::cin, phone);
            
            customers.push_back(Customer(customerIdCounter++, name, address, phone));
            std::cout << "Customer created successfully!\n";
        }
        else if (choice == 2) { // Create Account
            int customerId;
            std::cout << "Enter customer ID to create account for: ";
            std::cin >> customerId;

            // Find customer by ID
            Customer* customer = nullptr;
            for (auto& c : customers) {
                if (c.getCustomerId() == customerId) {
                    customer = &c;
                    break;
                }
            }

            if (customer == nullptr) {
                std::cout << "Customer not found!\n";
                continue;
            }

            std::string accountType;
            double initialDeposit;
            std::cout << "Enter account type (Savings/Checking): ";
            std::cin >> accountType;
            std::cout << "Enter initial deposit amount: ";
            std::cin >> initialDeposit;

            Account newAccount(accountIdCounter++, initialDeposit, accountType);
            customer->addAccount(newAccount);
            std::cout << "Account created successfully!\n";
        }
        else if (choice == 3) { // Deposit
            int customerId, accountId;
            double amount;
            std::cout << "Enter customer ID: ";
            std::cin >> customerId;
            std::cout << "Enter account ID: ";
            std::cin >> accountId;

            Customer* customer = nullptr;
            for (auto& c : customers) {
                if (c.getCustomerId() == customerId) {
                    customer = &c;
                    break;
                }
            }

            if (customer == nullptr) {
                std::cout << "Customer not found!\n";
                continue;
            }

            Account* account = customer->getAccountById(accountId);
            if (account == nullptr) {
                std::cout << "Account not found!\n";
                continue;
            }

            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            account->deposit(amount);
            std::cout << "Deposit successful!\n";
        }
        else if (choice == 4) { // Withdraw
            int customerId, accountId;
            double amount;
            std::cout << "Enter customer ID: ";
            std::cin >> customerId;
            std::cout << "Enter account ID: ";
            std::cin >> accountId;

            Customer* customer = nullptr;
            for (auto& c : customers) {
                if (c.getCustomerId() == customerId) {
                    customer = &c;
                    break;
                }
            }

            if (customer == nullptr) {
                std::cout << "Customer not found!\n";
                continue;
            }

            Account* account = customer->getAccountById(accountId);
            if (account == nullptr) {
                std::cout << "Account not found!\n";
                continue;
            }

            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            account->withdraw(amount);
            std::cout << "Withdrawal successful!\n";
        }
        else if (choice == 5) { // Transfer
            int fromCustomerId, fromAccountId, toCustomerId, toAccountId;
            double amount;

            std::cout << "Enter sender customer ID: ";
            std::cin >> fromCustomerId;
            std::cout << "Enter sender account ID: ";
            std::cin >> fromAccountId;

            Customer* fromCustomer = nullptr;
            for (auto& c : customers) {
                if (c.getCustomerId() == fromCustomerId) {
                    fromCustomer = &c;
                    break;
                }
            }

            if (fromCustomer == nullptr) {
                std::cout << "Sender customer not found!\n";
                continue;
            }

            Account* fromAccount = fromCustomer->getAccountById(fromAccountId);
            if (fromAccount == nullptr) {
                std::cout << "Sender account not found!\n";
                continue;
            }

            std::cout << "Enter receiver customer ID: ";
            std::cin >> toCustomerId;
            std::cout << "Enter receiver account ID: ";
            std::cin >> toAccountId;

            Customer* toCustomer = nullptr;
            for (auto& c : customers) {
                if (c.getCustomerId() == toCustomerId) {
                    toCustomer = &c;
                    break;
                }
            }

            if (toCustomer == nullptr) {
                std::cout << "Receiver customer not found!\n";
                continue;
            }

            Account* toAccount = toCustomer->getAccountById(toAccountId);
            if (toAccount == nullptr) {
                std::cout << "Receiver account not found!\n";
                continue;
            }

            std::cout << "Enter amount to transfer: ";
            std::cin >> amount;
            fromAccount->transfer(*toAccount, amount);
        }
        else if (choice == 6) { // View Account Details
            int customerId;
            std::cout << "Enter customer ID: ";
            std::cin >> customerId;

            Customer* customer = nullptr;
            for (auto& c : customers) {
                if (c.getCustomerId() == customerId) {
                    customer = &c;
                    break;
                }
            }

            if (customer == nullptr) {
                std::cout << "Customer not found!\n";
                continue;
            }

            customer->viewAccounts();
        }
        else if (choice == 7) { // View Transactions
            int customerId, accountId;
            std::cout << "Enter customer ID: ";
            std::cin >> customerId;
            std::cout << "Enter account ID: ";
            std::cin >> accountId;

            Customer* customer = nullptr;
            for (auto& c : customers) {
                if (c.getCustomerId() == customerId) {
                    customer = &c;
                    break;
                }
            }

            if (customer == nullptr) {
                std::cout << "Customer not found!\n";
                continue;
            }

            Account* account = customer->getAccountById(accountId);
            if (account == nullptr) {
                std::cout << "Account not found!\n";
                continue;
            }

            account->viewTransactions();
        }
        else if (choice == 8) { // Exit
            std::cout << "Exiting program...\n";
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
