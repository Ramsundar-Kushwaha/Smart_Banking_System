#include <iostream>
#include <string>
#include "SavingsAccount.h"
#include "Bank.h"

Bank::Bank(){
    // Nothing initializes this constructor to object
}

// for freeing up memory
Bank::~Bank(){
    for(auto& pair:accounts){
        delete pair.second;
    }
}

// for creating saving account
void Bank::createSavingAccount(){
    int accNo = 1000;
    std::string name;
    double balance;
    int pin = 123;

    if(accounts.find(accNo) != accounts.end()){
        std::cout << "Account Already Exist\n";
        return;
    }

    std::cout << "Enter Your Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter balance: ";
    std::cin >> balance;

    if(std::cin.fail() || balance < 500){
        std::cout << "Invalid Amount\n";
        return;
    }

    accounts[accNo] = new SavingsAccount(accNo, name, balance, pin);
    std::cout << "Saving Account Created Successfully\n";
}

// for finding account
Account* Bank::findAccount(int accNo){
    if(accounts.empty()){
        std::cout << "No Accounts Available\n";
        return nullptr;
    }
    if(accounts.find(accNo) != accounts.end()){
        return accounts[accNo];
    }
    std::cout << "Account Doesn't Exist\n";
    return nullptr;

}