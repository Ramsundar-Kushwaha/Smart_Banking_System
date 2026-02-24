#include <iostream>
#include "Account.h"

Account::~Account(){
    // nothing to do, but this must exist
    std::cout << "account destructor\n";
}