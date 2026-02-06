#include <iostream>
#include "Admin.h"
using namespace std;

Admin::Admin(){
    // nothing to do with this constructor
}

bool Admin::login(std::string name, std::string pass)const{
    if(name == username && pass == password){
        return true;
    }
    return false;
}