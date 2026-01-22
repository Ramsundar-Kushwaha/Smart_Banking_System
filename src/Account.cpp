#include <iostream>
#include "Account.h"

Account::~Account(){
    // nothing to do, but this must exist
    std::cout << "There is nothing to do with destructor\n";
}