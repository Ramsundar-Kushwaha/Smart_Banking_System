#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H
#include "Account.h"

class SavingsAccount:public Account{ // CHILD CLASS OF ACCOUNT PARENT CLASS
    private:
        double interestRate;
    public:
        ~SavingsAccount();
        SavingsAccount(int accNo, std::string name, double balance, int pin, double rate = 0.05):Account(accNo, name, balance, pin), interestRate(rate){}
        bool withdraw(double amount) override;
        void applyInterest() override;
        void display() const override;
};

#endif