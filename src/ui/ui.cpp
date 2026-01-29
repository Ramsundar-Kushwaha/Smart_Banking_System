#include <iostream>
#include <ui.h>
#include <Bank.h>


// Saving and Current Account Creation
int Ui::accountCreation(){
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
        return 1;
        break;
    
    case 2:
        system("cls");
        B.createCurrentAccount();
        return 2;
        break;
    
    default:
        break;
    }
}

// Saving Account's Services
int Ui::savingAccountServices(){
    std::cout << "+------------------+-------------+\n";
    std::cout << "| 1. Balance Query | 2. Withdraw |\n";
    std::cout << "+------------------+-------------+\n";
    std::cout << "| 3. Account Detail| 4. Logout   |\n";
    std::cout << "+------------------+-------------+\n";
    int choice;
    std::cout << "> ";
    std::cin >> choice;

    // if wrong choice input is wrong
    if(std::cin.fail()){
        std::cout << "Invalid Choice\n";
        return 4;
    }
    switch(choice){
        case 1:
            std::cout << "This is for balance query\n";
            return 1;
            
        case 2:
            std::cout << "This is Withdraw Option\n";
            return 2;

        case 3:
            std::cout << "This is Account Details\n";
            return 3;

        case 4:
            std::cout << "This is Logout Option\n";
            return 4;

        default:
            return -1;
    }
}

// Current Account's Services
int Ui::currentAccountServices(){
    std::cout << "+------------------+-------------+\n";
    std::cout << "| 1. Balance Query | 2. Withdraw |\n";
    std::cout << "+------------------+-------------+\n";
    std::cout << "| 3. Account Detail| 4. Logout   |\n";
    std::cout << "+------------------+-------------+\n";
    int choice;
    std::cout << "> ";
    std::cin >> choice;

    // if wrong choice input is wrong
    if(std::cin.fail()){
        std::cout << "Invalid Choice\n";
        return 4;
    }
    switch(choice){
        case 1:
            std::cout << "This is for balance query\n";
            return 1;
            
        case 2:
            std::cout << "This is Withdraw Option\n";
            return 2;

        case 3:
            std::cout << "This is Account Details\n";
            return 3;

        case 4:
            std::cout << "This is Logout Option\n";
            return 4;

        default:
            return -1;
    }
}