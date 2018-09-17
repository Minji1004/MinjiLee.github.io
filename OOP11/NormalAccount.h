#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include <iostream>
#include "Account.h"
using namespace std;

class NormalAccount : public Account
{
	double ratio;

public:
	NormalAccount(const String name, int accountNumber, int money)
		:Account(name, accountNumber, money), ratio(0.02) {}
	virtual void addMoney(int depositM)
	{
		int sumDepositM = depositM * (1 + ratio);
		Account::addMoney(sumDepositM);
	}
	virtual void show() const
	{
		cout << "°èÁÂ Á¾·ù: º¸Åë¿¹±Ý°èÁÂ \n";
		Account::show();
	}

};
#endif // !__NORMAL_ACCOUNT_H__