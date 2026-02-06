#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include "Bank.h"

class Admin{
    private:
        const std::string username = "Ramsundar";
        const std::string password = "ramsundar2001";
    
    public:
        Admin();
        bool login(std::string name, std::string pass) const;
        // void showAdminMenu(Bank* bank);
};

#endif