#include<iostream>
#include<string>

using namespace std;

class Customer {
private:
	string fname, lname, address, email;
	double phone;
public:
	Customer()
	{
		fname = "";
		lname = "";
		address = "";
		email = "";
		phone = 0;
	}
	Customer(string _fname, string _lname, string _address, string _email, double _phone)
	{
		fname = _fname;
		lname = _lname;
		address = _address;
		email = _email;
		phone = _phone;
	}
	void setCustomer(string _fname, string _lname, string _address, string _email, double _phone)
	{
		fname = _fname;
		lname = _lname;
		address = _address;
		email = _email;
		phone = _phone;
	}

	//Setters
	void setFname(string _fname)
	{
		fname = _fname;
	}
	void setLname(string _lname)
	{
		lname = _lname;
	}
	void setAddress(string _address)
	{
		address = _address;
	}
	void setEmail(string _email)
	{
		email = _email;
	}
	void setPhone(double _phone)
	{
		if (_phone >= 0)
		{
			phone = _phone;
		}
		else
		{
			cout << "You did not enter a valid phone number, please try again and enter your 10 digit phone number." << endl;
			cout << "=========================================================================================================" << endl << endl;
		}
	}

	//Getters
	string getFname() const
	{
		return fname;
	}
	string getLname() const
	{
		return lname;
	}
	string getAddress() const
	{
		return address;
	}
	string getEmail() const
	{
		return email;
	}
	double getPhone() const
	{
		return phone;
	}

	//Other Functions
	void printInfo()
	{
		cout << "First Name: " << fname << endl;
		cout << "Last Name: " << lname << endl;
		cout << "Address: " << address << endl;
		cout << "Email: " << email << endl;
		cout << "Phone Number: " << phone << endl;
	}
};

class Account : public Customer {
private:
	int ID;
	double balance;
	static int withdrawals;
	static int deposits;
	Customer accountCustomer;

public:
	//default
	Account() :Customer()
	{
		ID = 0;
		balance = 0;
	}

	Account(string _fname, string _lname, string _address, string _email, double _phone, int _ID, double _balance) : Customer( _fname,  _lname,  _address,  _email,  _phone)
	{
		ID = 0;
		balance = 0;
		//accountCustomer.setCustomer() idr how to do this
	}
	//getter
	double getBalance() const 
	{
		return balance;
	}
	//Functions
	void withdrawal(double _withdrawalAmmount)
	{
		if (_withdrawalAmmount < 0)
		{
			cout << "Not a valid withdrawal ammount, please try again... " << endl;
			cout << "=========================================================================================================" << endl << endl;
		}
		else if ((balance - _withdrawalAmmount) < 0)
		{
			cout << "The withdrawal ammount was greater than your balance. Please try again with a lesser value..." << endl;
			cout << "=========================================================================================================" << endl << endl;
		}
		else
		{
			balance = balance - _withdrawalAmmount;
			cout << "Withdrawal complete..." << endl;
			cout << "=========================================================================================================" << endl << endl;
			withdrawals++;
		}
	}
	void deposit(double _depositAmmount)
	{
		if (_depositAmmount < 0)
		{
			cout << "Not a valid deposit ammount, please try again... " << endl;
			cout << "=========================================================================================================" << endl << endl;
		}
		else
		{
			balance = balance + _depositAmmount;
			cout << "Deposit complete..." << endl;
			cout << "=========================================================================================================" << endl << endl;
			deposits++;
		}
	}
	void printInfo()
	{
	Customer: printInfo();
		cout << "Account ID Number: " << ID << endl;
		cout << "Balance: $" << balance << endl;
		cout << "Number of withdrawals: " << withdrawals << endl;
		cout << "Number of deposits: " << deposits << endl;
	}
};
//whats this for?
int Account::withdrawals = 0; 
int Account::deposits = 0;

class CheckingAccount : public Account {
private:
	double overDraftLimit;
public:
	CheckingAccount():Account()
	{
		overDraftLimit = 0;

	}
	CheckingAccount(string _fname, string _lname, string _address, string _email, double _phone, int _ID, double _balance, double _overDraftLimit): Account( _fname,  _lname,  _address,  _email, _phone, _ID,  _balance)
	{
		overDraftLimit = _overDraftLimit;
	}
	//not sure how to overload base class 
	void withdrawals(double _withdrawalAmount) override
	{

	}
};

class SavingAccount : public Account{
private:
	double interestRate;
public:
	SavingAccount() :Account()
	{
		interestRate = 0;
	}
	SavingAccount(string _fname, string _lname, string _address, string _email, double _phone, int _ID, double _balance, double _interestRate) : Account(_fname, _lname, _address, _email, _phone, _ID, _balance, _interestRate)
	{
		interestRate = _interestRate;
	}
	double payInterest()
	{
		//somehow get that balance from Account 
	double interest = interestRate * Account:getBalance();
	}
};

int main()
{














	system("Pause");
	return 0;
}
