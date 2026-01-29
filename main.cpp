#include <iostream>
#include <cstdlib> // for system("cls")
// #include "Account.h"
#include <ui.h>

int main(){
    // Bank B;
    // B.createSavingAccount();
    // B.showAllAccounts();
    Ui U;
    int choice;
    choice = U.accountCreation();
    if(choice == 1){
        choice = U.savingAccountServices();
    }else{
        choice = U.currentAccountServices();
    }

    
    return 0;
}