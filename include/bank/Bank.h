#ifndef BANK_H
#define BANK_H
#include <map>
#include <vector>
#include "Account.h"
#include "Transaction.h"

class Bank{ // INDEPENDENT CLASS - CONTROLLER
    private:
        std::map<int, Account*> accounts; // HAS ACCOUNT
        std::vector<Transaction> transactions; // HAS TRANSACTION
        Account* currentAccount = nullptr;
        Account* findAccount(int accNo);
        int generateAccountNumber();
        int generatePin();
    public:
        Bank();
        bool login(int accNo, int pin);
        bool withdraw();
        void logout();
        void createSavingAccount();
        void createCurrentAccount();
        void showBalance();
        void deleteAccount(int accNo);
        void deposit(int accNo, int pin, double amount);
        void transfer(int fromAcc, int toAcc, double amount);
        void freezeAccount(int accNo);
        void showAllAccounts() const;
        void loadAccounts();
        void saveAccounts();
        void saveTransactions();
        ~Bank();
};

#endif