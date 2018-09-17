#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account
{
	String name;
	int accountNumber;
	int money;

public:
	Account(const String name, int accountNumber, int money);

	int getID() const;
	virtual void addMoney(int money);
	void minMoney(int money);
	int getMoney() const;
	virtual void show() const;
};
#endif // !__ACCOUNT_H__
