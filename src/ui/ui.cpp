#include <iostream>
#include <limits>
#include "ui.h"
#include "Bank.h"


Bank B; // bank object

// login or signUp to banking app
void Ui::start(){
    while(true){
        system("clear");
        std::cout << "+----------+----------+---------+\n";
        std::cout << "|1. signUp | 2. Login | 3. Exit |\n";
        std::cout << "+----------+----------+---------+\n";
    
        int choice; // for getting choice
        std::cout << "> ";
        std::cin >> choice;
    
        if(std::cin.fail()){ // checks for valid input
            std::cin.clear(); // clear the error flag
            std::cin.ignore(1000, '\n'); // removes error from buffer completely upto 1000 character until '\n'
            std::cout << "Invalide Option | Try Again\n";
            pressEnterToContinue();
            continue;
        }
    
        switch(choice){
            case 1:
                accountCreation();
                break;
            case 2:
                login();
                break;
            case 3:
                std::cout << "Good Bye...\n";
                return;

            case 4:
                B.showAllAccounts();
                pressEnterToContinue();
                break;
                
            default:
                std::cout << "Option Out Of Range | Try Again\n";
                pressEnterToContinue();
                break;
        }
    }
}

// Saving and Current Account Creation
void Ui::accountCreation(){
    while(true){
        system("clear");
        std::cout << "                       SignUp To                       \n\n";
        std::cout << "+--------------------------+---------------------------+---------+\n";
        std::cout << "| 1. Create Saving Account | 2. Create Current Account | 3. Back |\n";
        std::cout << "+--------------------------+---------------------------+---------+\n";
        
        int choice;
        std::cout << "> ";
        std::cin >> choice;

        if(std::cin.fail()){ // checks for invalid input
            std::cin.clear(); // clear the error flag
            std::cin.ignore(1000, '\n'); // removes error from buffer completely upto 1000 character until '\n'
            std::cout << "Invalid Input | Please Try Again\n";
            pressEnterToContinue();
            continue;
        }
        
        switch (choice)
        {
        case 1:
            if(B.createSavingAccount()){
                pressEnterToContinue();
                login();
            }
            break;
        
        case 2:
            if(B.createCurrentAccount()){
                pressEnterToContinue();
                login();
            }
            break;

        case 3:
            return;

        default:
            std::cout << "Option Out Of Range | Try Again\n";
            pressEnterToContinue();
            break;
        }
    }
}

// login to account
void Ui::login(){
    while(true){
        system("clear");
        std::cout << "                 Login To                 \n\n";
        std::cout << "+-------------------+--------------------+--------+\n";
        std::cout << "| 1. Saving Account | 2. Current Account |3. Back |\n";
        std::cout << "+-------------------+--------------------+--------+\n";
    
        int choice;
        std::cout << "> ";
        std::cin >> choice;

        if(std::cin.fail()){ // checks for invalid input
            std::cin.clear(); // clear the error flag
            std::cin.ignore(1000, '\n'); // removes error from buffer completely upto 1000 character until '\n'
            std::cin.ignore(); // removes the error flag
            std::cout << "Invalid Option | Try Again\n";
            pressEnterToContinue();
            continue;
        }
    
        switch(choice){
            case 1:
            case 2:
                int accNo, pin;

                std::cout << "Account No: ";
                std::cin >> accNo;

                if(std::cin.fail()){ // checks for invalid input
                    std::cin.clear(); // clear the error flag
                    std::cin.ignore(1000, '\n'); // removes error from buffer completely upto 1000 character until '\n'
                    std::cout << "Invalid Account | Try Again Later\n";
                    pressEnterToContinue();
                    return;
                }

                std::cout << "PIN: ";
                std::cin >> pin;

                if(std::cin.fail()){ // checks for invalid input
                    std::cin.clear(); // clear the error flag
                    std::cin.ignore(1000, '\n'); // removes error from buffer completely upto 1000 character until '\n'
                    std::cout << "Invalid PIN | Try Again Later\n";
                    pressEnterToContinue();
                    return;
                }
                
                if(B.login(accNo, pin)){ // if account found
                    pressEnterToContinue();
                    savingAccountServices();
                }

                break;
            
            case 3:
                return;

            default:
                std::cout << "Option Out Of Range | Try Again\n";
                pressEnterToContinue();
                break;
        }
    }
}

// Saving Account's Services
void Ui::savingAccountServices(){
    while(true){
        system("clear");
        std::cout << "Welcom Mr./Mrs. " << B.curUser() << std::endl << std::endl;
        std::cout << "+------------------+-------------+\n";
        std::cout << "| 1. Balance Query | 2. Withdraw |\n";
        std::cout << "+------------------+-------------+\n";
        std::cout << "| 3. Account Detail| 4. Logout   |\n";
        std::cout << "+------------------+-------------+\n";


        int choice;
        std::cout << "> ";
        std::cin >> choice;
    
        if(std::cin.fail()){ // checks for invalid input
            std::cin.clear(); // clear the error flag
            std::cin.ignore(1000, '\n'); // removes error from buffer completely upto 1000 character until '\n'
            std::cout << "Invalid Choice | Try Again\n";
            pressEnterToContinue();
            break;
        }

        switch(choice){
            case 1:
                B.showBalance();
                pressEnterToContinue();
                break;
                
            case 2:
                B.withdraw();
                pressEnterToContinue();
                break;
    
            case 3:
                B.curAccDetails();
                pressEnterToContinue();
                break;
    
            case 4:
                B.logout();
                pressEnterToContinue();
                return;
    
            default:
                return;
        }
    }
}

// Current Account's Services
void Ui::currentAccountServices(){
    while(true){
        system("clear");
        std::cout << "Welcom Mr./Mrs. " << B.curUser() << std::endl << std::endl;
        std::cout << "+------------------+-------------+\n";
        std::cout << "| 1. Balance Query | 2. Withdraw |\n";
        std::cout << "+------------------+-------------+\n";
        std::cout << "| 3. Account Detail| 4. Logout   |\n";
        std::cout << "+------------------+-------------+\n";

        int choice;
        std::cout << "> ";
        std::cin >> choice;
    
        if(std::cin.fail()){ // checks for invalid input
            std::cin.clear(); // clear the error flag
            std::cin.ignore(1000, '\n'); // removes error from buffer completely upto 1000 character until '\n'
            std::cout << "Invalid Choice | Try Again\n";
            pressEnterToContinue();
            continue;
        }

        switch(choice){
            case 1:
                B.showBalance();
                break;
                
            case 2:
                B.withdraw();
                pressEnterToContinue();
                break;
    
            case 3:
                B.curAccDetails();
                pressEnterToContinue();
                break;
    
            case 4:
                B.logout();
                pressEnterToContinue();
                return;
    
            default:
                return;
        }
    }
}

// press enter to continue
void Ui::pressEnterToContinue(){
    std::cout << "Press Enter...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
