#include"Customer.h"

using namespace std;

//default
bool validatePhone(string ph)
{
	bool valid = true;
	if (ph.length() != 10)
		return false;
	for (int i = 0; i < ph.length(); i++)
	{
		if (ph[i] < '0' || ph[i] > '9')
		{
			return false;
		}
		break;
	}
	return valid;
}
Customer::Customer()
{
	fname = "";
	lname = "";
	address = "";
	email = "";
	phone = "";
}
Customer::Customer(string _fname, string _lname, string _address, string _email, string _phone)
{
	fname = _fname;
	lname = _lname;
	address = _address;
	email = _email;
	phone = _phone;
}

void Customer::setCustomer(string _fname, string _lname, string _address, string _email, string _phone)
{
	fname = _fname;
	lname = _lname;
	address = _address;
	email = _email;
	phone = _phone;
}


//Setters
void Customer::setFname(string _fname)
{
	fname = _fname;
}
void Customer::setLname(string _lname)
{
	lname = _lname;
}
void Customer::setAddress(string _address)
{
	address = _address;
}
void Customer::setEmail(string _email)
{
	email = _email;
}
bool Customer::isValidPhone(string _phone)
{
	if (validatePhone(_phone) == false)
	{
		return false;
	}
	else
		return true;
}
void Customer::setPhone(string _phone)
{
	bool valid = isValidPhone(_phone);
	if (valid == true)
	{
		phone = _phone;
		cout << "phone valid";
	}
	else
	{
		while (valid != true)
		{
			cout << "You did not enter a valid phone number, please try again and enter your 10 digit phone number without - or ()." << endl;
			cout << "Enter phone number: ";
			cin >> _phone;
			valid = isValidPhone(_phone);
		}
		phone = _phone;
	}
}

//Getters
string Customer::getFname() const
{
	return fname;
}
string Customer::getLname() const
{
	return lname;
}
string Customer::getAddress() const
{
	return address;
}
string Customer::getEmail() const
{
	return email;
}
string Customer::getPhone() const
{
	return phone;
}

//Other Functions
void Customer::printInfo()
{
	cout << "First Name: " << fname << endl;
	cout << "Last Name: " << lname << endl;
	cout << "Address: " << address << endl;
	cout << "Email: " << email << endl;
	cout << "Phone Number: " << phone << endl;
}

void Customer::askInfo()
{
	cout << "Enter First Name: ";
	cin >> fname;
	cout << "Enter Last Name: ";
	cin >> lname;
	cout << "Enter Address: ";
	cin.ignore();
	getline(cin, address);
	cout << "Enter Email: ";
	cin >> email;
	cout << "Enter Phone Number: ";
	cin >> phone;
}

