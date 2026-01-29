#ifndef UI_H
#define UI_H


class Ui
{
private:
    /* data */
public:
    Ui(){
        // nothing to do with constructor now
    }

    ~Ui(){
        // nothing to do with destructor now
    }

    int loginSignUpOption();
    int login();
    int signUp();
    void userServices();
    void AdminServices();
    int accountCreation();
    int savingAccountServices();
    int currentAccountServices();
};

#endif