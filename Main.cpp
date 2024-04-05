#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>

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
		phone = _phone;
	}
	void setCustomer(string _fname, string _lname, string _address, string _email, string _phone)
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
	bool isValidPhone(string _phone)
	{
		// Check if all characters in the string are digits
		for (char digit : _phone)
		{
			if (!isdigit(digit))
			{
				return false;
			}
		}
		//checks length 
		if (_phone.length() != 10)
		{
			return false;
		}
		else
		{
			return true;
		}
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
};

//makes an account(ID and balance) with the customers information
//also withdraw and deposit 
//has Customer accountCustomer
class Account : public Customer {
private:
	int ID;
	double balance;
	static int withdrawals;
	static int deposits;
protected:
	Customer accountCustomer;

public:
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
		if (isdigit(_ID) && _ID > 0)
			ID = _ID;
		else
		{
			while (isalpha(_ID) || _ID <= 0)
			{
				cout << "You have entered an invalid character or number for ID number. Please enter a new ID number: ";
				cin >> _ID;
			}
			ID = _ID;
		}
	}
	void setBalance(double _balance)
	{
		if (isdigit(_balance) && _balance > 0)
		{
			balance = _balance;
		}
		else
		{
			while ((isalpha(_balance)) || (_balance <= 0))
			{
				cout << "You have entered an invalid character or number for balance. Please enter a new balance: ";
				cin >> _balance;
			}
			balance = _balance;
		}
	}
	//getter
	double getBalance() const
	{
		return balance;
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
		cout << getFname() << setw(20) << ID << setw(20) << balance << endl;
	}

};

int main()
{
	Account a1("Alana", "Lucas", "3468", "alucas1@gmail", "9045984902", 1, 1000);
	a1.printInfo();

	system("pause");
	return 0;
}
//whats this for?
int Account::withdrawals = 0;
int Account::deposits = 0;

//pulls from account  
class CheckingAccount : public Account {
private:
	double overDraftLimit;

public:
	CheckingAccount() :Account()
	{
		overDraftLimit = 0;

	}
	CheckingAccount(string _fname, string _lname, string _address, string _email, double _phone, int _ID, double _balance, double _overDraftLimit) : Account(_fname, _lname, _address, _email, _phone, _ID, _balance)
	{
		overDraftLimit = _overDraftLimit;
	}
	void setOverDraftLimit(double _overDraftLimit)
	{
		overDraftLimit = _overDraftLimit;
	}
	//not sure how to overload base class 
	void withdrawals(double _withdrawalAmount) override
	{
		if ((getBalance()) < 0)
		{
			double temp;
			if (_withdrawalAmount > overDraftLimit)
			{
				cout << "You have tried to withdraw more then your over draft limit allows you to..." << endl;
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
		else if (((Account:: getBalance()) - _withdrawalAmount) < 0 && ((Account:: getBalance()) - _withdrawalAmount) >= (0 - overDraftLimit))
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
};

class SavingAccount : public Account {
private:
	double interestRate;
public:
	SavingAccount() :Account()
	{
		interestRate = 0;
	}
	SavingAccount(string _fname, string _lname, string _address, string _email, double _phone, int _ID, double _balance, double _interestRate)
	{
		accountCustomer.setCustomer(_fname, _lname, _address, _email, _phone);

		interestRate = _interestRate;
	}
	double payInterest()
	{
		//somehow get that balance from Account 
		// 
		//double interest = interestRate * Account:getBalance();
	}
};
//

class menu : public Account
{
public:
	int input;
	void displayMenu()
	{
		cout << "Please choose from the following options:" << endl;
		cout << "1* Deposit" << endl << "2* Withdraw" << endl << "3* Transfer Money" << endl << "4* Edit Info" << endl << "5* View Account Info" << endl << "6* Close Account " << endl << "Press any other number to exit" << endl;
		cin >> input;
	}

};

class createAccount : public Account
{
	static void displayMainMenu() {
		cout << "1. Create Checking Account" << endl;
		cout << "2. Create Saving Account" << endl;
		cout << "3. Exit" << endl;
	}
	static int getUserChoice() {
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;
		return choice;
	}
	static void createCheckingAccount() {
		int id, phone;
		double bal;
		string fName, lName, addr, email;

		cout << "Enter Account ID: ";
		cin >> id;
		cout << "Enter Initial Balance: ";
		cin >> bal;
		cout << "Enter First Name: ";
		cin >> fName;
		cout << "Enter Last Name: ";
		cin >> lName;
		cout << "Enter Address: ";
		cin.ignore();
		getline(cin, addr);
		cout << "Enter Phone: ";
		cin >> phone;
		cout << "Enter Email: ";
		cin >> email;


		Account customer(fName, lName, addr, email, phone, id, bal);
		//Account* acc = CreateAccount::createCheckingAccount(id, bal, customer);
		cout << "Checking Account Created Successfully!" << endl;
		//acc->PrintInfo();
		//delete acc;
	}

	static void createSavingAccount() {
		int id, phone;
		double bal, rate;
		string fName, lName, addr, email;

		cout << "Enter Account ID: ";
		cin >> id;
		cout << "Enter Initial Balance: ";
		cin >> bal;
		cout << "Enter Interest Rate: ";
		cin >> rate;
		cout << "Enter First Name: ";
		cin >> fName;
		cout << "Enter Last Name: ";
		cin >> lName;
		cout << "Enter Address: ";
		cin.ignore();
		getline(cin, addr);
		cout << "Enter Phone: ";
		cin >> phone;
		cout << "Enter Email: ";
		cin >> email;

		Account customer(fName, lName, addr, email, phone, id, bal);
		//Account* acc = CreateAccount::createSavingAccount(id, bal, customer, rate);
		cout << "Saving Account Created Successfully!" << endl;
		//acc->PrintInfo();
		//delete acc;
	}
	//creates a username and password
	void registerUser(const string& username, const string& password) {
		// Save to file (username.txt)
		string filename = username + ".txt";
		ofstream file(filename);
		file << password << "\n";  // Save the password directly
		file.close();

		cout << "User registered successfully!" << endl;
	}
	// password and user for login
	bool validateLogin(const string& username, const string& password) {
		string filename = username + ".txt";
		ifstream file(filename);
		if (!file) {
			cout << "User not found." << endl;
			return false;
		}

	}
};
	int main()
	{
		//string _fname, string _lname, string _address, string _email, double _phone, int _ID, double _balance
		// array for number of accounts 
		Account account[20];

		//Account account("alana", "lucas", "3547 Shres Dr", "alana@gmail", 9045984902, 1, 100);
		//hard code an account
		account[0].setAccount("alana", "lucas", "3547 Shres Dr", "alana@gmail", 9045984902, 1, 100);
		account[1].setAccount("maximus", "adversalo", "736 Killebrew Way", "adversalom@gmail", 9165450572, 2, 1000);

		int option;
		cout << "1. Log in " << endl;
		cout << "2. Create account" << endl;
		//using files????
		// we can add accounts username and password to save account information 
		cin >> option;
		if (option != 1 || 2)
		{
			cout << "Not a valid option" << endl;
			cout << "Log in (L) or Create account (C)";
		}
		else if (option == 1)
		{
			//create class to log in (inherate from account)
			string storedPassword, password;
			getline(cin, storedPassword);

			if (password == storedPassword) {
				cout << "Login successful!" << endl;
				return true;
			}
			else {
				cout << "Invalid credentials." << endl;
				return false;
			}
		}
		else if (option == 2)
		{
			//create class to create accputn 
			string username, password;
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;

			registerUser(username, password);
		}

		//create menu or call menu 
		cout << "1. Select Saving Account" << endl;
		cout << "2. Select Checking Account" << endl;
		cout << "3. Exit" << endl;
		cin >> option;

		//either create options to select saving withdraw or cheicking or create a do while to display  
		if (option == 1)
		{
			//call saving account
			// create menu with options 
			//deposit, withdraw, view account,  
		}
		else if (option == 2)
		{
			//call checking
			// create menu with options 
			//deposit, withdraw, view account
		}
		else if (option == 3)
		{
			//exits
			cout << "Thank you" << endl;
			return 0;
		}
		else
		{
			cout << "invalid option" << endl;
		}


		system("Pause");
		return 0;

	}
