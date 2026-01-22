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
    public:
        Bank();
        void createSavingAccount();
        void createCurrentAccount();
        Account* findAccount(int accNo);
        void deleteAccount(int accNo);
        void deposit(int accNo, double amount);
        void transfer(int fromAcc, int toAcc, double amount);
        void freezeAccount(int accNo);
        void showAllAccounts() const;
        void loadAccounts();
        void saveAccounts();
        void saveTransactions();
        ~Bank();
};

#endif