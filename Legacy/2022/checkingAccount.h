#ifndef CHECKINGACCOUNT_H_INCLUDED
#define CHECKINGACCOUNT_H_INCLUDED

#include "./bankAccount.h"

class checkingAccount : public bankAccount
{
public:
	checkingAccount();
	checkingAccount(int);
	checkingAccount(int, double);
	checkingAccount(int, double, double);
	checkingAccount(int, double, double, double);
	checkingAccount(int, double, double, double, double);
	~checkingAccount();
	double getInterestRate();
	double getMinimumBalance();
	double getServiceCharges();
	bool setInterestRate(double);
	bool setMinimumBalance(double);
	bool setServiceCharges(double);
	void postInterest();
	bool writeCheck(double);
	bool withdraw(double);
	void printAccountInformation();

private:
	double _interestRate;
	double _minimumBalance;
	double _serviceCharges;
	bool _isBalanceLessThanMinimumBalance();
};

#endif
