#include <iostream>
#include <fstream>
#include <string>
#include "Account.h"

using namespace std;

Account loadAccount(const string& accountNumber) {
    Account account;
    ifstream file("account" + accountNumber + ".txt");
    if (file.is_open()) {
        string accNumber;
        string name;
        float balance;
        string address;
        string phone;
        
        getline(file, accNumber);
        getline(file, name);
        file >> balance;
        file.ignore();
        getline(file, address);
        getline(file, phone);
        
        account.loadAccountDetails(stoi(accNumber), name, balance, address, phone); // Assuming loadAccountDetails accepts an integer for account number
        file.close();
    } else {
        cout << "Account not found!" << endl;
    }
    return account;
}

int main() {
    Account account;
    int choice;
    string accountNumber;  // Changed to string to handle 12-digit account numbers
    float amount;

    do {
        cout << "\n---Simple Banking System---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account Details\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.createAccount();
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                account = loadAccount(accountNumber);
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                account = loadAccount(accountNumber);
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                account = loadAccount(accountNumber);
                cout << "Balance: " << account.checkBalance() << endl;
                break;
            case 5:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                account = loadAccount(accountNumber);
                account.displayAccountDetails();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
