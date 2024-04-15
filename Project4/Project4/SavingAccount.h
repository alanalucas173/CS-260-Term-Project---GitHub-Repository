#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <ostream>
#include<ctime>
#include"Customer.h"
#include "Account.h"
using namespace std;

#ifndef SavingAccount_H
#define SavingAccount_H

class SavingAccount : public Account {
private:
	double interestRate;
	Account* accountCustomer;

public:
	//Constructors
	SavingAccount();
	SavingAccount(Account* accountCustomer, string _fname, string _lname, string _address, string _email, string _phone, int _ID, double _balance, double _interestRate);

	//Functions
	void depositSaving();
	double payInterest();
	void printInfo();
};

#endif //!SAVINGACCOUNT_H