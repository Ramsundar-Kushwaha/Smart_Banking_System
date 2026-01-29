#include <iostream>
#include <cstdlib> // for system("cls")
// #include "Account.h"
#include <ui.h>

int main(){
    Ui U;
    int choice;

    // for signup and login option
    choice = U.loginSignUpOption();
    if(choice == 1){
        int accountType = U.accountCreation();
        switch(accountType){
            case 1:
                {
                    int feature = U.savingAccountServices();
                    break;
                }
            case 2:
                {

                    int feature = U.currentAccountServices();
                    break;
                }
            default:
                break;
        }
    }else if(choice == 2){
        int accountType = U.login();
        switch (accountType)
        {
        case 1:
            std::cout << "Not Set Yet\n";
            break;
        case 2:
            std::cout << "Not Set Yet\n";
            break;
        default:
            break;
        }
    }else{
        return -1;
    }
    return 0;
}