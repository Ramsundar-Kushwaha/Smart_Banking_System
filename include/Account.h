#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
class Account{ // PARENT CLASS, CHILDS: = CurrentAccount, SavingAccount
    protected:
        int accountNumber;
        std::string holderName;
        double balance;
        int pin;
        bool isActive;

    public:
        Account(int accNo, std::string name, double balance, int pin); // constructor

        // for getting account number only, donot modify any value
        int getAccountNumber()const{
            return accountNumber;
        }

        // for getting account holder name, donot modify any value
        std::string getHolderName()const{
            return holderName;
        }

        // for balance query only, donot modify any value
        double getBalance()const{
            return balance;
        }

        // for authentication pin only, donot modify any value
        bool authenticate(int pin)const{
            return (pin == pin);
        }

        void deposit(double amount);
        virtual bool withdraw(double amount) = 0; // pure virtual funciton
        virtual void calculateInterest() = 0; // pure virtual function
        void activate();
        void deactivate();
        virtual void display()const = 0; // pure virtual function, for displaying account details, donot modify any value
        ~Account(); // destructor
};

#endif