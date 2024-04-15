#include"ACCOUNT.h"
#include"LOGIN.h"

using namespace std;


LogIn::LogIn() : Account()
{
	userName = "";
	password = "";
}
LogIn::LogIn(string _fname, string _lname, string _address, string _email, string _phone, int _ID, double _balance, string _userName, string _password) : Account(_fname, _lname, _address, _email, _phone, _ID, _balance)
{
	userName = _userName;
	password = _password;
}
