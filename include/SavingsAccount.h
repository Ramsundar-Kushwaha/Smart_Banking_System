#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H
#include "Account.h"

class SavingAccount:public Account{ // CHILD CLASS OF ACCOUNT PARENT CLASS
    private:
        double interestRate;
    public:
        SavingAccount(int accNo, std::string name, double balance, int pin);
        bool withdraw(double amount) override;
        void calculateInterest() override;
        void display() const override;
};

#endif