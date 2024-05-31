#include <iostream>
#include <cmath>

#include "./bankAccount.h"

using namespace std;

bankAccount::bankAccount()
{
	_number = 0;
	_balance = 0;
}

bankAccount::bankAccount(int number)
{
	_number = (number >= 0) ? number : 0;
	_balance = 0;
}

bankAccount::bankAccount(int number, double balance)
{
	_number = (number >= 0) ? number : 0;
	_balance = (balance >= 0) ? balance : 0;
}

bankAccount::~bankAccount()
{

}

int bankAccount::getNumber()
{
	return _number;
}

double bankAccount::getBalance()
{
	return _balance;
}

bool bankAccount::setNumber(int number)
{
	if (number >= 0)
	{
		_number = number;
		return true;
	}
	
	return false;
}

bool bankAccount::deposit(double balance)
{
	if (balance >= 0)
	{
		_balance += balance;
		return true;
	}

	return false;
}

bool bankAccount::withdraw(double balance)
{
	if (balance >= 0 && (_balance - balance) >= 0)
	{
		_balance -= balance;
		return true;
	}

	return false;
}

void bankAccount::printAccountInformation()
{
	cout << "number: " << _number << '\n';
	cout << "balance: " << _balance << '\n';
}
