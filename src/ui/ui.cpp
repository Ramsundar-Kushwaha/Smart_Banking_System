#include <iostream>
#include <limits>
#include "ui.h"
#include "Bank.h"


Bank B; // bank object

// starting of ui
void Ui::start(){
    while(true){
        system("clear");
        std::cout << "   Smart banking System   \n\n";
        std::cout << "+------------------------+\n";
        std::cout << "| 1. Login               |\n";
        std::cout << "+------------------------+\n";
        std::cout << "| 2. SignUp              |\n";
        std::cout << "+------------------------+\n";
        std::cout << "| 3. Admin Login         |\n";
        std::cout << "+------------------------+\n";
        std::cout << "| 4. Exit                |\n";
        std::cout << "+------------------------+\n";
    
        int choice;
        std::cout << "> ";
        std::cin >> choice;
    
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid Input | Try Again\n";
            continue;
        }

        switch(choice){
            case 1:
                login();
                break;
            
            case 2:
                accountCreation();
                break;

            case 3:
            {
                std::string username;
                std::string password;

                std::cout << "Username: ";
                std::cin >> username;

                std::cout << "Password: ";
                std::cin >> password;

                if(B.adminLogin(username, password)){
                    pressEnterToContinue();
                    adminServices();
                }
                break;
            }

            case 4:
                return;

            default:
                return;
        }
    }
}
    
// login to account
void Ui::login(){
    while(true){
        system("clear");
        std::cout << "     Login To      \n\n";
        std::cout << "+--------------------+\n";
        std::cout << "| 1. Saving Account  |\n";
        std::cout << "+--------------------+\n";
        std::cout << "| 2. Current Account |\n";
        std::cout << "+--------------------+\n";
        std::cout << "| 3. Back            |\n";
        std::cout << "+--------------------+\n";
    
        int choice;
        std::cout << "> ";
        std::cin >> choice;

        if(std::cin.fail()){ // checks for invalid input
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid Account | Try Again Later\n";
                    pressEnterToContinue();
                    return;
                }

                std::cout << "PIN: ";
                std::cin >> pin;

                if(std::cin.fail()){ // checks for invalid input
                    std::cin.clear(); // clear the error flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid PIN | Try Again Later\n";
                    pressEnterToContinue();
                    return;
                }
                
                if(B.login(accNo, pin)){ // if account found
                    system("clear");
                    savingAccountServices();
                }
                pressEnterToContinue();
                break;
            
            case 3:
                system("clear");
                return;

            default:
                std::cout << "Option Out Of Range | Try Again\n";
                pressEnterToContinue();
                break;
        }
    }
}

// Saving and Current Account Creation (signUp)
void Ui::accountCreation(){
    while(true){
        system("clear");
        std::cout << "       SignUp To     \n\n";
        std::cout << "+-------------------+\n";
        std::cout << "| 1. Saving Account |\n";
        std::cout << "+-------------------+\n";
        std::cout << "| 2. Current Account|\n";
        std::cout << "+-------------------+\n";
        std::cout << "| 3. Back           |\n";
        std::cout << "+-------------------+\n";
        
        int choice;
        std::cout << "> ";
        std::cin >> choice;

        if(std::cin.fail()){ // checks for invalid input
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid Input | Please Try Again\n";
            pressEnterToContinue();
            continue;
        }
        
        switch (choice)
        {
        case 1:
            if(B.createSavingAccount()){
                pressEnterToContinue();
                system("clear");
                return;
            }
            pressEnterToContinue();
            break;
        
        case 2:
            if(B.createCurrentAccount()){
                pressEnterToContinue();
                return;
            }
            pressEnterToContinue();
            break;

        case 3:
            system("clear");
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
        std::cout << "     Welcom Mr./Mrs. " << B.curUser() << std::endl;
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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                system("clear");
                B.logout();
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
        std::cout << "     Welcom Mr./Mrs. " << B.curUser() << std::endl << std::endl;
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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

// admin services or admin features
void Ui::adminServices(){
    while(true){
        system("clear");
        std::cout << "Welcome Admin Mr. " << std::endl;
        std::cout << "+-------------------------+\n";
        std::cout << "| 1. SHOW ALL ACCOUNTS    |\n";
        std::cout << "| 2. FREEZE ACCOUNT       |\n";
        std::cout << "| 3. DELETE ACCOUNT       |\n";
        std::cout << "| 4. LOGOUT               |\n";
        std::cout << "+-------------------------+\n";
        
        int choice;
        std::cout << "> ";
        std::cin >> choice;
        
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid Option | Try Again\n";
            continue;
        }
        
        switch(choice){
            case 1: // for showing all accounts
            if(B.showAllAccounts()){
                pressEnterToContinue();
                }
                break;
                
            case 2: // for freezing an account
            {
                int accNo;
                    std::cout << "Account No: ";
                    std::cin >> accNo;
                    
                    if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid Account Number | Try Again\n";
                        continue;
                    }
                    
                    if(B.freezeAccount(accNo)){
                        pressEnterToContinue();
                    }
                }
                break;
                
                case 3: // for deleting an account
                int accNo;
                std::cout << "Account No: ";
                std::cin >> accNo;
                
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid Account Number | Try Again\n";
                    continue;
                }

                if(B.deleteAccount(accNo)){
                    pressEnterToContinue();
                }
                break;
                
                case 4: // for logging out of admin page
                system("clear");
                std::cout << "Loged Out\n";
                pressEnterToContinue();
                return;
                
                default:
                std::cout << "Option Out Of Range | Try Again\n";
                pressEnterToContinue();
                break;
            }
        }
    }

// press enter to continue
void Ui::pressEnterToContinue(){
        std::cout << "Press Enter...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }