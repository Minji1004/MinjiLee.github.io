#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
	int creditClass;
public:
	HighCreditAccount(const String name, int accountNumber, int money, int creditClass)
		:NormalAccount(name, accountNumber, money), creditClass(creditClass) {}
	int GetCredit(int depositM)
	{
		return (int)depositM*(creditClass / 100.0);
	}
	virtual void addMoney(int depositM)
	{
		NormalAccount::addMoney(depositM);
		Account::addMoney(GetCredit(depositM));
	}
	virtual void show() const
	{
		cout << "°èÁÂ Á¾·ù: ½Å¿ë½Å·Ú°èÁÂ \n";
		Account::show();
	}
};
#endif // !__HIGH_CREDIT_ACCOUNT_H__