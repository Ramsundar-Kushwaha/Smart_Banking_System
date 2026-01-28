#include <iostream>
#include <cstdlib> // for system("cls")
#include "Account.h"
#include "Bank.h"

int main(){
    // Bank B;
    // B.createSavingAccount();
    // B.showAllAccounts();

    std::cout << "+--------------------------+---------------------------+\n";
    std::cout << "| 1. Create Saving Account | 2. Create Current Account |\n";
    std::cout << "+--------------------------+---------------------------+\n";

    int choice;
    std::cout << "> ";
    std::cin >> choice;
    if(std::cin.fail()){
        std::cout << "Invalid Input | Please Try Again\n";
    }

    Bank B;
    switch (choice)
    {
    case 1:
        system("cls");
        B.createSavingAccount();
        break;

    case 2:
        system("cls");
        B.createCurrentAccount();
        break;

    default:
        break;
    }
    return 0;
}