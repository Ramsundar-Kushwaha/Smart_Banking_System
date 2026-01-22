#ifndef CURRENT_ACCOUNT_H
#define CURRENT_ACCOUNT_H
#include "Account.h"

class CurrentAccount:public Account{ // CHILD CLASS OF ACCOUNT PARENT CLASS
    private:
        double overdraftLimit;

    public:
        CurrentAccount(int accNo, std::string name, double balance, int pin, int overdraft = 5000):Account(accNo, name, balance, pin), overdraftLimit(overdraft){}
        bool withdraw(double amount) override;
        void applyInterest() override;
        void display() const override;
};

#endif