#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::~SavingsAccount(){
    std::cout << "child class Memory Freed Successfully\n";
}

bool SavingsAccount::withdraw(double amount){
    if (! isActive){
        std::cout << "The Account is Deactivated\n";
        return false;
    }
    else if (amount <= 0 || amount > 10000){ // restricted amount maximum up to 10,000
        std::cout << "Invalid Amount | Must Be > 0 and <= 10,000\n";
        return false;
    }
    else if (balance == 0 || amount > balance){
        std::cout << "Insufficient Balance\n";
        return false;
    }
    else{
        balance -= amount;
        std::cout << "Successfull | withdraw amount " << amount << std::endl;
        return true;
    }
}

// applies intrest on savings
void SavingsAccount::applyInterest(){
    // intrest policy will be applied later
    std::cout << "Intrest Facilities Will be Applied Later\n";
}


// displays the details of account
void SavingsAccount::display()const{
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Account Holder: " << holderName << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}