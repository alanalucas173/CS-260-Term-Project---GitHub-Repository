#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <ostream>
#include<ctime>
#include"CUSTOMER.h"
using namespace std;

#ifndef Customer_H
#define Customer_H

class Customer
{
private:
	string fname, lname, address, email, phone;
public:
	//default
	Customer();
	Customer(string _fname, string _lname, string _address, string _email, string _phone);
	void setCustomer(string _fname, string _lname, string _address, string _email, string _phone);

	//Setters
	void setFname(string _fname);
	void setLname(string _lname);
	void setAddress(string _address);
	void setEmail(string _email);
	bool isValidPhone(string _phone);
	void setPhone(string _phone);

	//Getters
	string getFname() const;
	string getLname() const;
	string getAddress() const;
	string getEmail() const;
	string getPhone() const;

	//Other Functions
	void printInfo();
	void askInfo();
};

#endif //!MYCUSTOMER_H