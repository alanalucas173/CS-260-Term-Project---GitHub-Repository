#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <ostream>
#include<ctime>
using namespace std;

//This takes customer information (name, address, email, phone)
class Customer {
private:
	string fname, lname, address, email, phone;
public:
	//default
	Customer()
	{
		fname = "";
		lname = "";
		address = "";
		email = "";
		phone = "";
	}
	Customer(string _fname, string _lname, string _address, string _email, string _phone)
	{
		fname = _fname;
		lname = _lname;
		address = _address;
		email = _email;
		while (validatePhone(_phone) == false)
		{
			cout << "Invalid Phone number please try again." << endl;
			cout << "Please enter your phone number: ";
			cin >> _phone;
		}
		phone = _phone;
	}
	void setCustomer(string _fname, string _lname, string _address, string _email, string _phone)
	{
		fname = _fname;
		lname = _lname;
		address = _address;
		email = _email;
		while (validatePhone(_phone) == false)
		{
			cout << "Invalid Phone number please try again." << endl;
			cout << "Please enter your phone number: ";
			cin >> _phone;
		}
		phone = _phone;
	}

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
	bool isValidPhone(string _phone)
	{
		if (validatePhone(_phone) == false)
		{
			return false;
		}
		else
			return true;
	}
	void setPhone(string _phone)
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
	string getPhone() const
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

	void askInfo()
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
};

//makes an account(ID and balance) with the customers information
//also withdraw and deposit 
//has Customer accountCustomer
class Account : public Customer {
private:
	int ID;
	double balance;

protected:
	Customer accountCustomer;

public:
	int withdrawals = 0;
	int deposits = 0;
	//default
	Account() :Customer()
	{
		ID = 0;
		balance = 0;
	}

	Account(string _fname, string _lname, string _address, string _email, string _phone, int _ID, double _balance)
	{
		setCustomer(_fname, _lname, _address, _email, _phone);
		setID(_ID);
		setBalance(_balance);
		//accountCustomer.setCustomer() idr how to do this
	}
	//setter
	void setAccount(string _fname, string _lname, string _address, string _email, string _phone, int _ID, double _balance)
	{
		setCustomer(_fname, _lname, _address, _email, _phone);
		setID(_ID);
		setBalance(_balance);
	}
	void setID(int _ID)
	{
		srand(time(nullptr));
		int randomNumber = rand() % 90000 + 1000; //generates random 5 digin number between 10000 and 99999
		ID = randomNumber;
	}
	void setBalance(double _balance)
	{
		if (isdigit(_balance) && _balance >= 0)
		{
			balance = _balance;
		}
		else
		{
			while ((isalpha(_balance)) || (_balance < 0))
			{
				cout << "You have entered an invalid character or number for balance. Please enter a new balance: ";
				cin >> _balance;
			}
			balance = _balance;
		}
	}
	//Overloader
	Account operator++() //post-fix
	{

		withdrawals++;
		return *this;
	}
	//getter
	int getWithdrawals()const
	{
		return withdrawals;
	}
	double getBalance() const
	{
		return balance;
	}
	int getID() const
	{
		return ID;
	}
	//Functions
	void withdrawal(double _withdrawalAmmount)
	{
		//checks to make sure not below 0
		if (_withdrawalAmmount < 0)
		{
			cout << "Not a valid withdrawal ammount, please try again... " << endl;
			cout << "=========================================================================================================" << endl << endl;
		}
		//checks to make sure they have enough money 
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
		//checks to make sure amount is above 0
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
		cout << "Name" << setw(20) << "Account ID Number" << setw(20) << "Balance" << endl;
		cout << getFname() << setw(20) << getID() << setw(20) << getBalance() << endl;
	}


};

class CheckingAccount : public Account {
private:
	double overDraftLimit;

public:
	CheckingAccount() :Account()
	{
		overDraftLimit = 0;

	}
	CheckingAccount(string _fname, string _lname, string _address, string _email, string _phone, int _ID, double _balance, double _overDraftLimit) : Account(_fname, _lname, _address, _email, _phone, _ID, _balance)
	{
		overDraftLimit = _overDraftLimit;
	}
	void setOverDraftLimit(double _overDraftLimit)
	{
		overDraftLimit = _overDraftLimit;
	}

	//over load
	void withdrawal(double _withdrawalAmount)
	{
		if ((getBalance()) < 0)
		{
			double temp;
			if (_withdrawalAmount > overDraftLimit)
			{
				cout << "You have tried to withdraw more than your over draft limit allows you to..." << endl;
				cout << "Please try again!" << endl;
			}
			else
			{
				temp = overDraftLimit - _withdrawalAmount;
				setBalance((getBalance()) - 20);
			}
		}
		else if (_withdrawalAmount < 0)
		{
			cout << "You have tried to withdraw a negative amount. You can not do this..." << endl;
			cout << "Please try again!" << endl;
		}
		else if (((getBalance()) - _withdrawalAmount) > 0)
		{
			double temp;
			temp = getBalance() - _withdrawalAmount;
			setBalance(temp);
			withdrawals++;
			cout << "Your inputted amount has been withdrawn... " << endl;
			cout << "Your new balance is $" << temp << endl;
		}
		else if (((Account::getBalance()) - _withdrawalAmount) < 0 && ((Account::getBalance()) - _withdrawalAmount) >= (0 - overDraftLimit))
		{
			double temp;
			temp = (overDraftLimit)+(getBalance() - (_withdrawalAmount));
			setOverDraftLimit(temp);
			setBalance((getBalance() - 20));
			withdrawals++;
			cout << "Your inputted amount has been withdrawn but a $20 service fee has been charged to your account for overdraft protection." << endl;
		}
		else
		{
			cout << "You have tried to withdraw more than your over draft limit allows you to." << endl;
			cout << "Please try again." << endl;
		}
	}
	void depositChecking()
	{
		double depositAmmount = 0;
		cout << "Your current balance is: $" << Account::getBalance() << endl;
		cout << "Please eneter how much you would like to deposit into your account: $";
		cin >> depositAmmount;
		if (depositAmmount >= 0)
		{
			Account::setBalance(Account::getBalance() + depositAmmount);
			cout << "Your deposit has been added..." << endl;
			cout << "Your new balance is: $" << getBalance() << endl;
		}
		else
		{
			cout << "You have inputted an invalid deposit ammount. This will not be added to your Checking Account." << endl;
			cout << "Please try again!" << endl;
		}
	}
};

class SavingAccount : public Account {
private:
	double interestRate;
public:
	SavingAccount() :Account()
	{
		interestRate = 0;
	}
	SavingAccount(string _fname, string _lname, string _address, string _email, string _phone, int _ID, double _balance, double _interestRate)
	{
		if (interestRate < 1 && interestRate >= 0) //Checks to see if interestRate is valid percentage 
		{
			interestRate = _interestRate;
			accountCustomer.setCustomer(_fname, _lname, _address, _email, _phone);
		}
		else
		{
			cout << "Invalid interest rate. Your inputted interest rate must be between 1 and 0. This represents the percent interest that will be mutiplied in your savings account. Please try again." << endl;
			return;
		}
	}
	void depositSaving()
	{
		double depositAmmount = 0;
		cout << "Your current balance is: $" << Account::getBalance() << endl;
		cout << "Please eneter how much you would like to deposit into your Savings account: $";
		cin >> depositAmmount;
		if (depositAmmount >= 0)
		{
			Account::setBalance(getBalance() + depositAmmount);
			cout << "Your deposit has been added..." << endl;
			cout << "Your new balance is: $" << Account::getBalance() << endl;
		}
		else
		{
			cout << "You have inputted an invalid deposit ammount. This will not be added to your Checking Account." << endl;
			cout << "Please try again!" << endl;
		}
	}
	double payInterest()
	{
		double interest = interestRate * Account::getBalance();
	}
	void printInfo()
	{
		cout << "Name" << setw(20) << "Account ID Number" << setw(20) << "Balance" << setw(20) << "Interest Rate" << endl;
		cout << getFname() << setw(20) << getID() << setw(20) << getBalance() << setw(20) << interestRate << endl;
	}
};

class LogIn : public Account
{
private:
	string userName, password;
public:
	LogIn() : Account()
	{
		userName = "";
		password = "";
	}
	LogIn(string _fname, string _lname, string _address, string _email, string _phone, int _ID, double _balance, string _userName, string _password) : Account(_fname, _lname, _address, _email, _phone, _ID, _balance)
	{
		userName = _userName;
		password = _password;
	}
	void registerUser(string _userName, string _password)
	{
		string _fname, _lname, _address, _email, _phone;
		double _balance = 0;
		int _ID = 0;
		userName = _userName;
		password = _password;
		cout << "Your username and password have been created. We only need a few more things from you to complete your account set-up." << endl;
		cout << "Enter First Name: ";
		cin >> _fname;
		cout << "Enter Last Name: ";
		cin >> _lname;
		cout << "Enter Address: ";
		cin.ignore();
		getline(cin, _address);
		cout << "Enter Email: ";
		cin >> _email;
		cout << "Enter Phone Number: ";
		cin >> _phone;
		setCustomer(_fname, _lname, _address, _email, _phone);
		setID(_ID);
		setBalance(_balance);
		cout << "Your acccount has successfully been created!" << endl;
	}
};

int main()
{
	//system("cls")
	int size = 3;
	int i = 0;
	int* account = new int[size];
	int* checkingAccounts = new int[size];
	int* savingAccounts = new int[size];
	LogIn a1[3];
	SavingAccount saving[3];
	CheckingAccount checking[3];
	int menuOption, option;
	
	const int ACCOUNT_ARRSIZE = 5;
	bool currentAvaliableSavingsIndexes[ACCOUNT_ARRSIZE];
	bool currentAvaliableCheckingIndexes[ACCOUNT_ARRSIZE];
	int const CUSTOMER_ARRSIZE = 10;
	int current_customers = 0;
	int customer_index = 0;
	SavingAccount savingsArr[ACCOUNT_ARRSIZE];
	CheckingAccount checkingArr[ACCOUNT_ARRSIZE];
	Customer customerArr[CUSTOMER_ARRSIZE];;
	Customer currentCustomer;
	//int menuOption;
	int accountNumber, transferTo, transferFrom;
	string username, password;
	ifstream infile;
	ofstream outfile;
	
	for (int i = 0; i < ACCOUNT_ARRSIZE; i++) {
		currentAvaliableCheckingIndexes[i] = true;
		currentAvaliableSavingsIndexes[i] = true;
	}
	do
	{
		cout << "Welcome Main Menu \n 1.Login 2.Create Account \n Please enter 1 or 2: ";
		cin >> option;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Not valid, Try again ";
			cin >> option;
		}
		if (option == 1)
		{
			//create class to log in (inherate from account)
			
			string storedPassword, password;
			getline(cin, storedPassword);

			if (password == storedPassword)
			{
				cout << "Login successful!" << endl;
				//return true;
			}
			else
			{
				cout << "Invalid credentials." << endl;
				//return false;
			}
		}
		else if (option == 2)
		{
			a1[i];
			string username, password;
			//create class to create accputn 
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;
			size++;
			a1[i].registerUser(username, password);
			//logIn.registerUser(username, password);
		}

		cout << "Please enter 1 for Checkings or 2 for Savings: ";
		cin >> option;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Not valid, Try again ";
			cin >> option;
		}
		if (option == 1)
		{
			int input;
			cout << "Please enter a number decision according to where you would like to me navigated within your savings menu: " << endl;
			cout << "1. Deposit" << endl << "2. Withdraw " << endl << "3. View Account" << endl << "4. Exit" << endl;
			cin >> input;
			if (input == 1)
			{
				saving[i].depositSaving();
				//SavingAccount::depositSaving(depositAmmount); //still needs to figure out what account number so that correct account is pullled up
			}
			else if (input == 2)
			{
				double withdrawAmmount;
				cout << "You have chosen :WITHDRAW:" << endl;
				cout << "Please enter how much you would like to withdraw: $";
				cin >> withdrawAmmount;
				saving[i].withdrawal(withdrawAmmount);
			}
			else if (input == 3)
			{
				//SavingAccount::savingsAccount.printInfo();
				saving[i].printInfo();
			}
			else if (input == 4)
			{
				cout << "You have chosen :EXIT:" << endl;
				cout << "Your account has been locked, thank you for banking with us today!" << endl;
			}
			else
			{
				cout << "You have entered an invalid entry, please try again later..." << endl;
			}
		}
		else if (option == 2)
		{


			int input;
			cout << "Please enter a number decision according to where you would like to me navigated within your checking menu: " << endl;
			cout << "1. Deposit" << endl << "2. Withdraw" << endl << "3. View Account" << endl << "4. Exit" << endl;
			cin >> input;
			if (input == 1)
			{
				double depositAmmount;
				cout << "You have chosen :DEPOSIT:" << endl;
				cout << "Please enter how much you would like to deposit: $";
				cin >> depositAmmount;
				checking[i].deposit(depositAmmount);
				//CheckingAccount[i].deposit(depositAmmount); //still needs to figure out what account number so that correct account is pullled up
			}
			else if (input == 2)
			{
				double withdrawlAmmount;
				cout << "You have chosen :WITHDRAW:" << endl;
				cout << "PLease enter how much you would like to withdraw: $";
				cin >> withdrawlAmmount;
				checking[i].withdrawal(withdrawlAmmount);
				//CheckingAccount[i].withdraw(withdrawlAmmount);
			}
			else if (input == 3)
			{
				checking[i].printInfo();
				//CheckingAccount::checkingAccount.printInfo();
			}
			else if (input == 4)
			{
				cout << "You have chosen :EXIT:" << endl;
				cout << "Your account has been locked, thank you for banking with us today!" << endl;
			}
			else
			{
				cout << "You have entered an invalid entry, please try again later..." << endl;
			}
		}

	} 
	while (option != 0);
	return 0;
}
