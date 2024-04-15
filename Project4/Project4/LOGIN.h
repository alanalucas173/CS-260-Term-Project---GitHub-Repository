#pragma once
#if !defined(UTILS_H)
#define UTILS_H
#include <iostream>
#include <string>
#include "SAVINGACCOUNT.h"
#include "CHECKINGACCOUNT.h"
#include "CUSTOMER.h"
using namespace std;

ifstream infile;
ofstream outfile;

bool IsExit(string& var, string text) {
    cout << text;
    cin >> var;
    if (var == "exit") {
        return true;
    }
    return false;
}


void createNewAccount(string type, Customer& customer, SavingsAccount* savingsArr, CheckingAccount* checkingArr, int arrSize, bool* avaliableSavings, bool* avaliableChecking) {
    double deposit;
    if (type == "savings") {
        for (int i = 0; i < arrSize; i++) {
            if (avaliableSavings[i]) {
                savingsArr[i].setCustomer(customer);
                cout << "Enter an initial deposit amount : $";
                cin >> deposit;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid value, please try again.\n";
                    cout << "value: ";
                    cin >> deposit;
                }
                savingsArr[i].deposit(deposit);
                savingsArr[i].printInfo(true);
                avaliableSavings[i] = false;
                customer.addedAccount();
                return;
            }
        }
        cout << "max account of accounts reached\n.";

    }
    else if (type == "checking") {
        for (int i = 0; i < arrSize; i++) {
            if (avaliableChecking[i]) {
                checkingArr[i].setCustomer(customer);
                cout << "Enter an initial deposit amount : $";
                cin >> deposit;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid value, please try again.\n";
                    cout << "value: ";
                    cin >> deposit;
                }
                checkingArr[i].deposit(deposit);
                checkingArr[i].printInfo(true);
                avaliableChecking[i] = false;
                customer.addedAccount();
                return;
            }
        }
        cout << "max account of accounts reached\n.";
    }
}

bool usernameExists(string username, Customer* customerArr, int customerArrSize) {
    for (int i = 0; i < customerArrSize; i++) {
        if (customerArr[i].getUser() == username) {
            return true;
        }
    }
    return false;
}

void createNewCustomer(Customer* customerArr, int& current_customer_index, int customerArrSize) {
    if (current_customer_index >= customerArrSize) {
        cout << "Maximum number of customers reached.\n";
        return;
    }

    string _fname, _lname, _address, _phone, _email, username, password;

    if (IsExit(_fname, "Enter first name: ")) {
        return;
    }
    if (IsExit(_lname, "Enter last name: ")) {
        return;
    };
    cout << "enter address: ";
    cin.ignore(1000, '\n');
    getline(cin, _address);
    if (_address == "exit") {
        return;
    }
    if (IsExit(_phone, "Enter phone number: ")) {
        return;
    }
    if (IsExit(_email, "Enter email: ")) {
        return;
    }
    if (IsExit(username, "Choose a username: ")) {
        return;
    }

    while (usernameExists(username, customerArr, current_customer_index)) {
        if (IsExit(username, "Username not available, please try again: ")) {
            return;
        }
    }
    if (IsExit(password, "Choose a password: ")) {
        return;
    }
    Customer tempCustomer(_fname, _lname, _address, _phone, _email, username, password);
    customerArr[current_customer_index] = tempCustomer;
    current_customer_index++;

    cout << "Customer created successfully. \n";
}



Customer loginCustomer(Customer* customerArr, int customerArrSize, int& customerIndex) {
    string username, password;
    Customer tempCustomer;
    if (IsExit(username, "Enter username: ")) {
        return Customer();
    }

    for (int i = 0; i < customerArrSize; i++) {
        if (customerArr[i].getUser() == username) {
            tempCustomer = customerArr[i];
            customerIndex = i;
            break;
        }
    }
    if (tempCustomer.isEmpty()) {
        cout << "No user with that username found.\n";
        return Customer();
    }
    if (IsExit(password, "Enter password: ")) {
        return Customer();
    }
    if (tempCustomer.getPassword() == password) {
        return tempCustomer;
    }
    cout << "Incorrect Credentials\n";
    return Customer();

}

void showCustomerAccounts(string username, SavingsAccount* sAccounts, CheckingAccount* cAccounts, int arrSize, bool showCustomerInfo) {
    bool found = false;
    for (int i = 0; i < arrSize; i++) {
        if (sAccounts[i].getUser() == username) {
            cout << "Showing information of Saving account #" << sAccounts[i].getId() << endl;
            sAccounts[i].printInfo(showCustomerInfo);
            found = true;
        }
        if (cAccounts[i].getUser() == username) {
            cout << "Showing information of checking account #" << cAccounts[i].getId() << endl;
            cAccounts[i].printInfo(showCustomerInfo);
            found = true;
        }
    }
    if (!found)
        cout << "No accounts found\n";

}

void getMenuOption(int& menuOption) {
    cin >> menuOption;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid option, please try again.\n";
        cout << "option: ";
        cin >> menuOption;
    }
}

void depositToAccount(string username, SavingsAccount* sAccounts, CheckingAccount* cAccounts, int arrSize, int id) {
    double deposit;
    for (int i = 0; i < arrSize; i++) {
        if (sAccounts[i].getId() == id && sAccounts[i].getUser() == username) {
            cout << "Enter amount to deposit to savings account #" << sAccounts[i].getId() << ": ";
            cin >> deposit;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid value, please try again.\n";
                cout << "value: ";
                cin >> deposit;
            }
            sAccounts[i].deposit(deposit);
            break;
            // cout << "New balance: $" << sAccounts[i]
        }
        else if (cAccounts[i].getId() == id && cAccounts[i].getUser() == username) {
            cout << "Enter amount to deposit to checking account #" << cAccounts[i].getId() << ": ";
            cin >> deposit;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid value, please try again.\n";
                cout << "value: ";
                cin >> deposit;
            }
            cAccounts[i].deposit(deposit);
            break;
        }
    }
}

void withdrawnFromAccount(string username, SavingsAccount* sAccounts, CheckingAccount* cAccounts, int arrSize, int id) {
    double amount;
    for (int i = 0; i < arrSize; i++) {
        if (sAccounts[i].getId() == id && sAccounts[i].getUser() == username) {
            cout << "Enter amount to withdrawn from savings account #" << sAccounts[i].getId() << ": ";
            cin >> amount;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid value, please try again.\n";
                cout << "value: ";
                cin >> amount;
            }
            sAccounts[i].withdraw(amount);
            break;
            // cout << "New balance: $" << sAccounts[i]
        }
        else if (cAccounts[i].getId() == id && cAccounts[i].getUser() == username) {
            cout << "Enter amount to withdrawn from checking account #" << cAccounts[i].getId() << ": ";
            cin >> amount;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid value, please try again.\n";
                cout << "value: ";
                cin >> amount;
            }
            cAccounts[i].withdraw(amount);
            break;
        }
    }
}

void showTotalBalance(string username, SavingsAccount* sAccounts, CheckingAccount* cAccounts, int arrSize) {
    double amount = 0;
    for (int i = 0; i < arrSize; i++) {
        if (sAccounts[i].getUser() == username) {
            amount = amount + sAccounts[i].getBalance();
        }
        if (cAccounts[i].getUser() == username) {
            amount = amount + cAccounts[i].getBalance();
        }
    }
    cout << "Your total balance is $" << amount << endl;
}


void transferBetweenAccounts(string username, SavingsAccount* sAccounts, CheckingAccount* cAccounts, int arrSize, int toId, int fromId) {
    double amount;
    cout << "Enter amount to transfer: $";
    cin >> amount;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid value, please try again.\n";
        cout << "value: ";
        cin >> amount;
    }

    for (int i = 0; i < arrSize; i++) {
        if (sAccounts[i].getId() == fromId && sAccounts[i].getUser() == username) {
            sAccounts[i].withdraw(amount);
            break;
        }
        else if (cAccounts[i].getId() == fromId && cAccounts[i].getUser() == username) {
            cAccounts[i].withdraw(amount);
            break;
        }
        else {
            cout << "No account with that id found";
        }
    }

    for (int i = 0; i < arrSize; i++) {
        if (sAccounts[i].getId() == toId && sAccounts[i].getUser() == username) {
            sAccounts[i].deposit(amount);
            break;
        }
        else if (cAccounts[i].getId() == toId && cAccounts[i].getUser() == username) {
            cAccounts[i].deposit(amount);
            break;
        }
        else {
            cout << "No account with that id found";
        }
    }
}

void adminShowCustomers(Customer* customerArr, int customerArrSize, SavingsAccount* sAccounts, CheckingAccount* cAccounts, int accountArrSize) {
    for (int i = 0; i < customerArrSize; i++) {
        if (!customerArr[i].isEmpty()) {
            customerArr[i].PrintInfo();
            showCustomerAccounts(customerArr[i].getUser(), sAccounts, cAccounts, accountArrSize, false);
        }
    }
}

void adminTextCustomers(Customer* customerArr, int customerArrSize, SavingsAccount* sAccounts, CheckingAccount* cAccounts, int accountArrSize, const string& filename)
{
    outfile.open(filename);

    if (!outfile.is_open())
    {
        cout << "Error creating file" << endl;
        return;
    }

    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(outfile.rdbuf());

    for (int i = 0; i < customerArrSize; i++)
    {
        if (!customerArr[i].isEmpty())
        {
            customerArr[i].PrintInfo();
            showCustomerAccounts(customerArr[i].getUser(), sAccounts, cAccounts, accountArrSize, false);

        }

    }

    cout.rdbuf(coutbuf);

    outfile.close();
}

bool loginAdmin(string user, string pass) {
    string username = "admin", password = "admin123";
    if (user == username && pass == password) {
        return true;
    }
    return false;

}

void changeUsername(Customer& customer, Customer* customerArr, int arrSize, string username, int current_customer_index, SavingsAccount* saccounts, CheckingAccount* caccounts, int accountArrSize) {
    for (int i = 0; i < arrSize; i++) {
        if (customerArr[i].getUser() == username) {
            cout << "username already in use.\n";
            return;
        }
    }
    for (int i = 0; i < accountArrSize; i++) {
        if (saccounts[i].getUser() == customer.getUser()) {
            saccounts[i].changeUser(username);
        }
        if (caccounts[i].getUser() == customer.getUser()) {
            caccounts[i].changeUser(username);
        }

    }
    customerArr[current_customer_index].changeUsername(username);
    customer = customerArr[current_customer_index];


    cout << "username changed to " << username << endl;
}

void changePassword(Customer& customer, string password, Customer* customerArr, int arrSize, int current_customer_index) {
    customerArr[current_customer_index].changePassword(password);
    customer = customerArr[current_customer_index];
    cout << "password successfully changed.\n";

}
#endif
