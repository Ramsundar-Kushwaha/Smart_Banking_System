#include <iostream>
#include "CurrentAccount.h"


// withdraw method for current account
bool CurrentAccount::withdraw(double amount){
    if(!isActive){
        std::cout << "The Account is Deactivated\n";
        return false;
    }

    if(amount <= 0){
        std::cout << "Invalid Amount\n";
        return false;
    }

    // Normal withdraw
    if(amount <= balance){
        std::cout << "Successful | withdraw amount " << amount << std::endl;
        balance -= amount;
        return true;
    }

    std::cout << "Insufficient Balance | Do You Want to Overdraft (Y/N)\n";
    char choice;
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y'){
        if(amount <= balance + overdraftLimit){
            std::cout << "Successful | withdraw amount " << amount << std::endl;
            double overdraftUsed = amount - balance;
            balance = 0;
            overdraftLimit -= overdraftUsed;
            return true;
        }
        else{
            std::cout << "Insufficient Balance\n";
            std::cout << "Requested Amount: " << amount << std::endl;
            std::cout << "Available Balance: " << balance << std::endl;
            std::cout << "Overdraft Limit: " << overdraftLimit << std::endl;
            return false;
        }
    }
    return false;
}

// apply intrest to current account
void CurrentAccount::applyInterest(){
    std::cout << "Current Account is Not Eligible for Any Intrest | Try Opening a Saving Account\n";
}

// display account details
void CurrentAccount::display()const{
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Account Holder: " << holderName << std::endl;
    std::cout << "Balance: " << balance << std::endl;
    std::cout << "Overdraft Limit: " << overdraftLimit << std::endl;
}