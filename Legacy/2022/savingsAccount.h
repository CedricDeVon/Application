#ifndef SAVINGSACCOUNT_H_INCLUDED
#define SAVINGSACCOUNT_H_INCLUDED

#include "./bankAccount.h"

class savingsAccount : public bankAccount
{
public:
	savingsAccount();
	savingsAccount(int);
	savingsAccount(int, double);
	savingsAccount(int, double, double);
	~savingsAccount();
	double getInterestRate();
	bool setInterestRate(double);
	void postInterest();
	bool withdraw(double);
	void printAccountInformation();

private:
	double _interestRate;
};

#endif
