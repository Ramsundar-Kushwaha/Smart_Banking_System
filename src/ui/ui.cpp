#include <iostream>
#include <ui.h>
#include <Bank.h>


Bank B; // bank object

// login or signUp to banking app
void Ui::start(){
    while(true){
        system("cls");
        std::cout << "+----------+----------+---------+\n";
        std::cout << "|1. signUp | 2. Login | 3. Exit |\n";
        std::cout << "+----------+----------+---------+\n";
    
        int choice; // for getting choice
        std::cout << "> ";
        std::cin >> choice;
    
        if(std::cin.fail()){ // checks for valid input
            std::cout << "Invalide Option | Try Again\n";
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
            default:
                std::cout << "Option Out Of Range | Try Again\n";
                break;
        }
    }
}


// Saving and Current Account Creation
void Ui::accountCreation(){
    while(true){
        system("cls");
        std::cout << "                       SignUp To                       \n\n";
        std::cout << "+--------------------------+---------------------------+---------+\n";
        std::cout << "| 1. Create Saving Account | 2. Create Current Account | 3. Back |\n";
        std::cout << "+--------------------------+---------------------------+---------+\n";
        
        int choice;
        std::cout << "> ";
        std::cin >> choice;

        if(std::cin.fail()){ // checks for invalid input
            std::cout << "Invalid Input | Please Try Again\n";
            continue;
        }
        
        switch (choice)
        {
        case 1:
            B.createSavingAccount();
            break;
        
        case 2:
            B.createCurrentAccount();
            break;

        case 3:
            return;

        default:
            std::cout << "Option Out Of Range | Try Again\n";
            break;
        }
    }
}


// login to account
void Ui::login(){
    while(true){
        system("cls");
        std::cout << "                 Login To                 \n\n";
        std::cout << "+-------------------+--------------------+--------+\n";
        std::cout << "| 1. Saving Account | 2. Current Account |3. Back |\n";
        std::cout << "+-------------------+--------------------+--------+\n";
    
        int choice;
        std::cout << "> ";
        std::cin >> choice;

        if(std::cin.fail()){ // checks for invalid input
            std::cin.ignore(); // removes the error flag
            std::cout << "Invalid Option | Try Again\n";
            continue;
        }
    
        switch(choice){
            case 1:
            case 2:
                int accNo, pin;

                std::cout << "Account No: ";
                std::cin >> accNo;

                if(std::cin.fail()){ // checks for invalid input
                    std::cout << "Invalid Account | Try Again Later\n";
                    return;
                }

                std::cout << "PIN: ";
                std::cin >> pin;

                if(std::cin.fail()){ // checks for invalid input
                    std::cout << "Invalid PIN | Try Again Later\n";
                    return;
                }
                
                if(B.login(accNo, pin)){ // if account found
                    savingAccountServices();
                }

                break;
            
            case 3:
                return;

            default:
                std::cout << "Option Out Of Range | Try Again\n";
                break;
        }
    }
}

// Saving Account's Services
void Ui::savingAccountServices(){
    while(true){
        system("cls");
        std::cout << "+------------------+-------------+\n";
        std::cout << "| 1. Balance Query | 2. Withdraw |\n";
        std::cout << "+------------------+-------------+\n";
        std::cout << "| 3. Account Detail| 4. Logout   |\n";
        std::cout << "+------------------+-------------+\n";


        int choice;
        std::cout << "> ";
        std::cin >> choice;
    
        if(std::cin.fail()){ // checks for invalid input
            std::cout << "Invalid Choice | Try Again\n";
            break;
        }

        switch(choice){
            case 1:
                B.showBalance();
                break;
                
            case 2:
                double amount;
    
                std::cout << "Withdraw Amount: ";
                std::cin >> amount;

                if(std::cin.fail()){ // checks for invalid input
                    std::cout << "Invalid Amount\n";
                    return;
                }
                
                B.withdraw();
                break;
    
            case 3:
                std::cout << "This is Account Details\n";
                break;
    
            case 4:
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
        system("cls");
        std::cout << "+------------------+-------------+\n";
        std::cout << "| 1. Balance Query | 2. Withdraw |\n";
        std::cout << "+------------------+-------------+\n";
        std::cout << "| 3. Account Detail| 4. Logout   |\n";
        std::cout << "+------------------+-------------+\n";

        int choice;
        std::cout << "> ";
        std::cin >> choice;
    
        if(std::cin.fail()){ // checks for invalid input
            std::cout << "Invalid Choice | Try Again\n";
            continue;
        }

        switch(choice){
            case 1:
                B.showBalance();
                break;
                
            case 2:
                double amount;
    
                std::cout << "Withdraw Amount: ";
                std::cin >> amount;

                if(std::cin.fail()){ // checks for invalid input
                    std::cout << "Invalid Amount\n";
                    return;
                }
                
                B.withdraw();
                break;
    
            case 3:
                std::cout << "This is Account Details\n";
                break;
    
            case 4:
                B.logout();
                return;
    
            default:
                return;
        }
    }
}