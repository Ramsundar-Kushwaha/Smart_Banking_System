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
        // constructor for initializing object
        Account(int accNo, std::string name, double balance, int pin){
            accountNumber = accNo;
            holderName = name;
            this->balance = balance;
            this->pin = pin;
            isActive = true;
        }

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

        // for PIN
        int getPin()const{
            return pin;
        }

        // for authentication pin only, donot modify any value
        bool authenticate(int inputPin)const{
            return isActive && (pin == inputPin);
        }

        // for balance depositing
        void deposit(double amount){
            if (isActive && amount > 0){
                balance += amount;
            }
        }

        virtual bool withdraw(double amount) = 0; // pure virtual funciton
        virtual void applyInterest() = 0; // pure virtual function

        // for activating account
        void activate(){
            isActive = true;
        }

        // for deactivating account
        void deactivate(){
            isActive = false;
        }

        virtual void display()const = 0; // pure virtual function, for displaying account details, donot modify any value
        virtual ~Account(); // destructor
};

#endif