#include "Account.h"
#include <iostream>
#include <fstream>
using namespace std;

Account::Account() : accountNumber(0), balance(0.0) {}

void Account::createAccount() {
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, accountHolderName);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Phone Number: ";
    getline(cin, phoneNumber);
    cout << "Enter Initial Deposit: ";
    cin >> balance;
    saveAccountDetails();
    cout << "Account Created Successfully!" << endl;
}

void Account::deposit(float amount) {
    balance += amount;
    saveAccountDetails();
    cout << "Amount Deposited Successfully!" << endl;
}

void Account::withdraw(float amount) {
    if (amount > balance) {
        cout << "Insufficient Balance!" << endl;
    } else {
        balance -= amount;
        saveAccountDetails();
        cout << "Amount Withdrawn Successfully!" << endl;
    }
}

float Account::checkBalance() {
    return balance;
}

void Account::displayAccountDetails() {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder: " << accountHolderName << endl;
    cout << "Address: " << address << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Balance: " << balance << endl;
}

int Account::getAccountNumber() {
    return accountNumber;
}

void Account::loadAccountDetails(int accNumber, string name, float bal, string addr, string phone) {
    accountNumber = accNumber;
    accountHolderName = name;
    balance = bal;
    address = addr;
    phoneNumber = phone;
}

void Account::saveAccountDetails() {
    ofstream file("account" + to_string(accountNumber) + ".txt");
    if (file.is_open()) {
        file << accountNumber << endl;
        file << accountHolderName << endl;
        file << balance << endl;
        file << address << endl;
        file << phoneNumber << endl;
        file.close();
    } else {
        cout << "Error saving account details!" << endl;
    }
}
