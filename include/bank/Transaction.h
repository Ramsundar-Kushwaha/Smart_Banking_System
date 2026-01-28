#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

class Transaction{ // INDEPENDENT CLASS
    private:
        int transactionId;
        int accountNumber;
        std::string type;
        double amount;
        std::string dateTime;

    public:
        Transaction(int id, int accNo, std::string type, double amount, std::string dateTime);
        int getTransactionId() const; // for getting transaction id, donot modify any value
        int getAccountNumber() const; // for getting account number only, donot modify any value
        void display() const;
};

#endif