#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <ostream>
#include<ctime>
#include"Customer.h"
using namespace std;

#ifndef CheckingAccount_H
#define CheckingAccount_H

class CheckingAccount : public Account {
private:
	double overDraftLimit;
	Account* accountCustomer;

public:
	CheckingAccount();
	CheckingAccount(Account* accountCustomer, string _fname, string _lname, string _address, string _email, string _phone, int _ID, double _balance, double _overDraftLimit);
	void setOverDraftLimit(double _overDraftLimit);

	//over load
	void withdrawal(double _withdrawalAmount);
	void depositChecking();
};

#endif //!CHECKINGACCOUNT_H