#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <iostream>
using namespace std;

class AccountException
{
public:
	virtual void ShowExceptionReason() {}
};

class DepositException: public AccountException
{
	int money;
public:
	DepositException(int num) :money(num) {}
	void ShowExceptionReason()
	{
		cout << money << "은 입금 불가! \n";
	}
};

class WithdrawException : public AccountException
{
	int money;
public:
	WithdrawException(int num) :money(num) {}
	void ShowExceptionReason()
	{
		cout << money << "은 출금 불가! \n";
	}
};


#endif