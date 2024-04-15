#include"Account.h"
#include"CheckingAccount.h"

using namespace std;

CheckingAccount::CheckingAccount()
{
	Account();
	overDraftLimit = 0;
}
CheckingAccount::CheckingAccount(Account* accountCustomer, string _fname, string _lname, string _address, string _email, string _phone, int _ID, double _balance, double _overDraftLimit) : Account(_fname, _lname, _address, _email, _phone, _ID, _balance)
{
	overDraftLimit = _overDraftLimit;
}
void CheckingAccount::setOverDraftLimit(double _overDraftLimit)
{
	overDraftLimit = _overDraftLimit;
}

//over load
void CheckingAccount::withdrawal(double _withdrawalAmount)
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
void CheckingAccount::depositChecking()
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