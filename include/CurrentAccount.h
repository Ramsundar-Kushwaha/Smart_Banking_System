#ifndef CURRENT_ACCOUNT_H
#define CURRENT_ACCOUNT_H
#include "Account.h"

class currentAccount:public Account{ // CHILD CLASS OF ACCOUNT PARENT CLASS
    private:
        double overdraftLimit;

    public:
        currentAccount(int accNo, std::string name, double balance, int pin);
        bool withdraw(double amount) override;
        void calculateInterest() override;
        void display() const override;
};

#endif