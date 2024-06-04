#ifndef BANKACCOUNT_H_INCLUDED
#define BANKACCOUNT_H_INCLUDED

class bankAccount
{
public:
	bankAccount();
	bankAccount(int);
	bankAccount(int, double);
	~bankAccount();
	int getNumber();
	double getBalance();
	bool setNumber(int);
	bool deposit(double);
	bool withdraw(double);
	void printAccountInformation();
		
protected:
	int _number;
	double _balance;
};

#endif
