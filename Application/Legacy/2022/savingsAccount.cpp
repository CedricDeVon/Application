#include <iostream>

#include "./bankAccount.h"
#include "./savingsAccount.h"

using namespace std;

savingsAccount::savingsAccount()
	: bankAccount(0, 0)
{
	_interestRate = 0;
}

savingsAccount::savingsAccount(
	int number) : bankAccount(number, 0)
{
	_interestRate = 0;
}

savingsAccount::savingsAccount(
	int number,
	double balance) : bankAccount(number, balance)
{
	_interestRate = 0;
}

savingsAccount::savingsAccount(
	int number,
	double balance,
	double interestRate) : bankAccount(number, balance)
{
	_interestRate = interestRate;
}

savingsAccount::~savingsAccount()
{

}

double savingsAccount::getInterestRate()
{
	return _interestRate;
}

bool savingsAccount::setInterestRate(double interestRate)
{
	if (interestRate < 0)
	{
		return false;
	}

	_interestRate = interestRate;
	return true;
}

void savingsAccount::postInterest()
{
	cout << "interestRate: " << _interestRate << "%" << '\n';
}

bool savingsAccount::withdraw(double balance)
{
	if (balance < 0 && _balance - balance < 0)
	{
		return false;
	}

	_balance -= balance;
	_balance += _balance * (_interestRate / static_cast<double>(100));
	return true;
}

void savingsAccount::printAccountInformation()
{
	bankAccount::printAccountInformation();
	cout << "interestRate: " << _interestRate << "%" << '\n';
}
