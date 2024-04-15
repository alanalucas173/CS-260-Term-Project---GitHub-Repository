#include"Customer.h"
#include"Account.h"
#include"SavingAccount.h"

using namespace std;


SavingAccount::SavingAccount()
{
	Account();
	interestRate = 0.02;
}
SavingAccount::SavingAccount(Account* accountCustomer, string _fname, string _lname, string _address, string _email, string _phone, int _ID, double _balance, double _interestRate): Account(_fname, _lname, _address, _email, _phone, _ID, _balance)
{
	if (interestRate < 1 && interestRate >= 0) //Checks to see if interestRate is valid percentage 
	{
		interestRate = _interestRate;
	}
	else
	{
		cout << "Invalid interest rate. Your inputted interest rate must be between 1 and 0. This represents the percent interest that will be mutiplied in your savings account. Please try again." << endl;
		return;
	}
}
void SavingAccount::depositSaving()
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
double SavingAccount::payInterest()
{
	double interest = interestRate * Account::getBalance();
	return interest;
}
void SavingAccount::printInfo()
{
	cout << "Name" << setw(20) << "Account ID Number" << setw(20) << "Balance" << setw(20) << "Interest Rate" << endl;
	cout << Account::accountCustomer.getFname() << setw(20) << getID() << setw(20) << getBalance() << setw(20) << interestRate << endl;
}