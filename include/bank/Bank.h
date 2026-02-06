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
        std::string currentUser;
    public:
        Bank();
        void curAccDetails();
        bool login(int accNo, int pin);
        std::string curUser()const;
        bool withdraw();
        void logout();
        bool createSavingAccount();
        bool createCurrentAccount();
        bool adminLogin()const;
        void showBalance() const;
        bool deleteAccount(int accNo);
        void deposit(int accNo, int pin, double amount);
        void transfer(int fromAcc, int toAcc, double amount);
        bool freezeAccount(int accNo);
        bool showAllAccounts() const;
        void loadAccounts();
        void saveAccounts();
        void saveTransactions();
        ~Bank();
};

#endif