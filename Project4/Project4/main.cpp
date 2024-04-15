#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <ostream>
#include <ctime>
#include <cstdlib>

//#include "CUSTOMER.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include "Account.h"

void createAccount();
void loadAccount();

using namespace std;

const string storedPassword = "test";
const int MAX_ACCOUNT = 20;
CheckingAccount chkAccounts[MAX_ACCOUNT];
int numChkAccounts = 0;
SavingAccount svAccounts[MAX_ACCOUNT];
int numSvAccounts = 0;

int main()
{
	do
	{
		cout << "1. Create account 2. Open existing account";
		int option;
		cin >> option;

		switch (option)
		{
		case 1:
		{
			createAccount();
			break;
		}
		case 2:
		{
			loadAccount();
			break;
		}
		default:
			break;
		}
	} while (true);


}

void createAccount()
{
	string _fname, _lname, _address, _email, _phone;
	double _balance = 0;
	int _ID = 0;

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

	cout << "Which account are you creating";
	cout << "1. Saving 2.Checking: ";
	int acctOption;
	cin >> acctOption;
	if (acctOption == 1)
	{
		//saving
		int randomNumber = rand() % 1000;
		_ID = randomNumber + 5000; //all saving accounts start with 5
		cout << "Your ID Number is " << _ID << endl;
		numSvAccounts++;
		svAccounts[numSvAccounts - 1].setAccount(_fname, _lname, _address, _email, _phone, _ID, _balance);
		cout << "Your acccount has successfully been created!" << endl;
	}
	else if (acctOption == 2)
	{
		//checking
		int randomNumber = rand() % 1000;  
		_ID = randomNumber + 1000; //all checking accounts start with 1
		cout << "Your ID Number is " << _ID << endl;
		numChkAccounts++;
		chkAccounts[numChkAccounts - 1].setAccount(_fname, _lname, _address, _email, _phone, _ID, _balance);
		cout << "Your acccount has successfully been created!" << endl;
	}
	else
	{
		cout << "Invalid ";
	}

	
}

void loadAccount()
//function 
{
	int findID;
	bool isChk = false;
	int acctIndex = 0;
	cout << "Enter ID Number: ";
	cin >> findID;
	if (findID < 4999)
	{
		//checking
		for (int i = 0; i < numChkAccounts; i++)
		{
			if (chkAccounts[i].getID() == findID)
			{
				isChk = true;
				acctIndex = i;
			}

		}
	}
	else
	{
		//saving
		for (int i = 0; i < numSvAccounts; i++)
		{
			if (svAccounts[i].getID() == findID)
			{
				isChk = false;
				acctIndex = i;
			}
		}
	}
	int input;
	do
	{
		cout << "Please enter a number decision according to where you would like to me navigated within your savings menu: " << endl;
		cout << "1. Deposit" << endl << "2. Withdraw" << endl << "3. View Account" << endl << "4. Exit" << endl;
		cin >> input;
		system("cls");
		switch (input)
		{
		case 1:
			double depositAmmount;
			cout << "You have chosen :DEPOSIT:" << endl;
			cout << "Please enter how much you would like to deposit: $";
			cin >> depositAmmount;
			if (isChk == false)
			{
				svAccounts[acctIndex].deposit(depositAmmount);
			}
			else
			{
				chkAccounts[acctIndex].deposit(depositAmmount);
			}
			break;
		case 2:
			double withdrawAmmount;
			cout << "You have chosen :WITHDRAW:" << endl;
			cout << "Please enter how much you would like to WITHDRAW: $";
			cin >> withdrawAmmount;
			if (isChk == false)
			{
				svAccounts[acctIndex].withdrawal(withdrawAmmount);
			}
			else
			{
				chkAccounts[acctIndex].withdrawal(withdrawAmmount);
			}
			break;
		case 3:
			if (isChk == false)
			{
				svAccounts[acctIndex].printInfo();
			}
			else
			{
				chkAccounts[acctIndex].printInfo();
			}
			break;
		case 4:
			cout << "You have chosen :EXIT:" << endl;
			cout << "Your account has been locked, thank you for banking with us today!" << endl;
			break;
		default:
			cout << "You have entered an invalid entry, please try again later..." << endl;
			break;
		}

	} 
	while (true);
}
