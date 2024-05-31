#include <iostream>

#include "./bankAccount.h"
#include "./checkingAccount.h"

using namespace std;

checkingAccount::checkingAccount()
	: bankAccount(0, 0)
{
	_interestRate = 0;
	_minimumBalance = 0;
	_serviceCharges = 0;
}

checkingAccount::checkingAccount(
	int number) : bankAccount(number, 0)
{
	_interestRate = 0;
	_minimumBalance = 0;
	_serviceCharges = 0;
}

checkingAccount::checkingAccount(
	int number,
	double balance) : bankAccount(number, balance)
{
	_interestRate = 0;
	_minimumBalance = 0;
	_serviceCharges = 0;
}

checkingAccount::checkingAccount(
	int number,
	double balance,
	double interestRate) : bankAccount(number, balance)
{
	_interestRate = interestRate;
	_minimumBalance = 0;
	_serviceCharges = 0;
}

checkingAccount::checkingAccount(
	int number,
	double balance,
	double interestRate,
	double minimumBalance) : bankAccount(number, balance)
{
	_interestRate = interestRate;
	_minimumBalance = minimumBalance;
	_serviceCharges = 0;
}

checkingAccount::checkingAccount(
	int number,
	double balance,
	double interestRate,
	double minimumBalance,
	double serviceCharges) : bankAccount(number, balance)
{
	_interestRate = interestRate;
	_minimumBalance = minimumBalance;
	_serviceCharges = serviceCharges;
}

checkingAccount::~checkingAccount()
{

}

double checkingAccount::getInterestRate()
{
	return _interestRate;
}

double checkingAccount::getMinimumBalance()
{
	return _minimumBalance;
}

double checkingAccount::getServiceCharges()
{
	return _serviceCharges;
}

bool checkingAccount::setInterestRate(double interestRate)
{
	if (interestRate >= 0)
	{
		_interestRate = interestRate;
		return true;
	}

	return false;
}

bool checkingAccount::setMinimumBalance(double minimumBalance)
{
	if (minimumBalance >= 0)
	{
		_minimumBalance = minimumBalance;
		return true;
	}

	return false;
}

bool checkingAccount::setServiceCharges(double serviceCharges)
{
	if (serviceCharges >= 0)
	{
		_serviceCharges = serviceCharges;
		return true;
	}

	return false;
}

void checkingAccount::postInterest()
{
	cout << "interestRate: " << _interestRate << "%" << '\n';
}

bool checkingAccount::_isBalanceLessThanMinimumBalance()
{
	return _balance < _minimumBalance;
}

bool checkingAccount::writeCheck(double balance)
{
	if (balance < 0)
	{
		return false;
	}

	if (_balance < _minimumBalance)
	{
		balance -= _serviceCharges;
	}

	_balance += balance;
	_balance += _balance * (_interestRate / static_cast<double>(100));
	return true;
}

bool checkingAccount::withdraw(double balance)
{
	if (balance < 0 && _balance - balance < 0)
	{
		return false;
	}

	if (_balance < _minimumBalance)
	{
		balance -= _serviceCharges;
		if (balance < 0)
		{
			return false;
		}
	}

	_balance -= balance;
	_balance += _balance * (_interestRate / static_cast<double>(100));
	return true;
}

void checkingAccount::printAccountInformation()
{
	bankAccount::printAccountInformation();
	cout << "interestRate: " << _interestRate << "%" << '\n';
	cout << "minimumBalance: " << _minimumBalance << '\n';
	cout << "serviceCharges: " << _serviceCharges << '\n';
}
