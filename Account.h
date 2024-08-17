#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolderName;
    float balance;
    string address;
    string phoneNumber;

public:
    Account();  // Constructor
    void createAccount();
    void deposit(float amount);
    void withdraw(float amount);
    void displayAccountDetails();
    float checkBalance();
    int getAccountNumber();
    void loadAccountDetails(int accNumber, string name, float bal, string addr, string phone);
    void saveAccountDetails();
};

#endif
