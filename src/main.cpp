#include "Account.h"
#include "Bank.h"
#include <iostream>

int main(){
    Bank B;
    B.createSavingAccount();
    Account* A = B.findAccount(1000);
    A->display();
    return 0;
}