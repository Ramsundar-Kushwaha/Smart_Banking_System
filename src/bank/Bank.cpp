#include <iostream>
#include <string>
#include <limits>
#include <random>
#include <cstdlib>
#include "Bank.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"

Bank::Bank(){
    // Nothing initializes this constructor to object
}

// for freeing up memory
Bank::~Bank(){
    for(auto& pair:accounts){
        delete pair.second;
    }
}

// generates random 6 digit different account number
int Bank::generateAccountNumber(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(100000, 999999);
    return dist(gen);
}


// generates random 4 digit different pin number
int Bank::generatePin(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1000, 9999);
    return dist(gen);
}

// for finding the account
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

// for loging into the account
bool Bank::login(int accNo, int pin){
    auto it = findAccount(accNo); // calling find function
    if(it == nullptr){
        return false;
    }
    if(!it->authenticate(pin)){
        return false;
    }
    currentAccount = it;
    std::cout << "Login Successful\n";
    return true;
}

// for withdrawing amount
bool Bank::withdraw(){
    if(!currentAccount){
        std::cout << "Please Login First\n";
        return false;
    }

    double amount;
    std::cout <<"Withdraw Amount: ";
    std::cin >> amount;
    if(std::cin.fail()){
        std::cout << "Invalid Amount\n";
        return false;
    }

    currentAccount->withdraw(amount);
    std::cout << amount << " Withdraw Successful\n";
    return true;
}


// for logging out of the account
void Bank::logout(){
    if(currentAccount == nullptr){
        std::cout << "No User Logged In\n";
        return;
    }

    currentAccount = nullptr;
    std::cout << "Logged Out Successfully\n";
}

// for creating saving account
void Bank::createSavingAccount(){
    int accNo = generateAccountNumber();
    std::string name;
    double balance;
    int pin = generatePin();

    if(accounts.find(accNo) != accounts.end()){
        std::cout << "Account Already Exist\n";
        return;
    }

    std::cout << "Enter Your Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    std::cout << "Enter balance: ";
    std::cin >> balance;

    if(std::cin.fail() || balance < 500){
        std::cout << "Invalid Amount\n";
        return;
    }

    accounts[accNo] = new SavingsAccount(accNo, name, balance, pin);
    system("cls"); // for clearing console screen
    std::cout << "Saving Account Created Successfully\n";
    std::cout << "Your Account Number: " << accNo << std::endl;
    std::cout << "Your Pin: " << pin << std::endl;
    std::cout << "Note: Remember your Account Number and PIN Number.\n";
}

// for creating current account
void Bank::createCurrentAccount(){
    int accNo = 1001;
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

    if(std::cin.fail() || balance < 200){
        std::cout << "Invalid Amount\n";
        return;
    }

    accounts[accNo] = new CurrentAccount(accNo, name, balance, pin);
    std::cout << "Current Account Created Successfully\n";
}

// for showing balance of current user
void Bank::showBalance(){
 if (!currentAccount){
    std::cout << "No user Logged in\n";
    return;
 }

 std::cout << "Balance: " << currentAccount->getBalance() << std::endl;
}

// for deleting account
void Bank::deleteAccount(int accNo){
    auto it = accounts.find(accNo);

    if(it == accounts.end()){
        std::cout << "Account Doesn't Exist\n";
        return;
    }

    delete it->second; // freed the object, created using new keyword
    accounts.erase(it); // accNo and the pointer it completely erased
    std::cout << "Account Deleted Successfully\n";
}

// for deposit
void Bank::deposit(int accNo, int pin, double amount){

    Account* acc = findAccount(accNo);

    if(acc == nullptr){
        return;
    }

    if(!acc->authenticate(pin)){
        std::cout << "Invalid PIN\n";
        return;
    }

    acc->deposit(amount);
    
}

// for transfer funds
void Bank::transfer(int fromAcc, int toAcc, double amount){
    // i will do it later
}

// for freezing account
void Bank::freezeAccount(int accNo){
    // i will do it later
}

// for showing account
void Bank::showAllAccounts()const{
    if(accounts.empty()){
        std::cout << "No Acounts Available\n";
        return;
    }

    for(const auto& pair : accounts){
        std::cout << "------------------------\n";
        pair.second->display(); // polymorphism happens here
    }
}

void Bank::loadAccounts(){
    // i will do it later
}

// for saving account
void Bank::saveAccounts(){
    // i will do it later
}

// for saving transaction
void Bank::saveTransactions(){
    // i will do it later
}