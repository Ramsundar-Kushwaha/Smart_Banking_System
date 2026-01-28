#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include "Bank.h"

class Admin{
    private:
        std::string username;
        std::string password;
    
    public:
        Admin();
        bool login(std::string username, std::string password) const;
        void showAdminMenu(Bank* bank);
};

#endif